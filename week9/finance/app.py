import os
import json

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
# if not os.environ.get("API_KEY"):
# raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_id = session["user_id"]
    rows_by_stock = db.execute("SELECT SUM(shares), stock FROM history WHERE user_id = ? GROUP BY stock", user_id)
    stocks = []
    total = 0
    for row in rows_by_stock:
        symbol = row["stock"]
        response = lookup(symbol)
        stock = {
            "symbol": symbol,
            "name": response["name"],
            "shares": row["SUM(shares)"],
            "price": response["price"]
        }
        stocks.append(stock)

        total += stock["price"] * stock["shares"]

    cash_left = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
    total += cash_left

    return render_template("index.html", stocks=stocks, cash_left=cash_left, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":

        # Ensure input not empty
        if not request.form.get("symbol") or not request.form.get("shares"):
            return apology("please provide stock symbol and its number", 400)

        number = request.form.get("shares")

        if not isinstance(number, int):
            return apology("please provide a positivy integer", 400)

        symbol = request.form.get("symbol")
        response =lookup(symbol)

        # Ensure stock symbol is valid(exist)
        if response == None:
            return apology(symbol + " do not exist or something went wrong", 400)

        # Ensure number is valid
        # 交给 HTML 元素确保输入为整数
        if number <= 0:
            return apology("please provide a positive integer", 400)

        # Check user's cash
        price_per = response["price"]
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        price = price_per * number
        if user_cash < price:
            return apology("POOR GUY!", 403)
        else:
            left_cash = user_cash - price

        # Update history table
        db.execute("INSERT INTO history (user_id,stock,price,shares) VALUES (?,?,?,?)", user_id, symbol, price_per, number)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", left_cash, user_id)
        return redirect("/")

    elif request.method == "GET":
        return render_template("buy.html")




@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    user_id = session["user_id"]
    rows = db.execute("SELECT * FROM history WHERE user_id = ? ORDER BY timestamp DESC", user_id)

    history = []

    for row in rows:
        item = {}
        shares = int(row["shares"])
        if shares > 0:
            item["type"] = "Buy"
        else:
            item["type"] = "Sell"

        item.update({
            "symbol": row["stock"],
            # "name":
            "time": row["timestamp"],
            "shares": abs(shares),
            "price": row["price"]
        })
        history.append(item)

    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "GET":

        return render_template("quote.html")

    elif request.method == "POST":

        if not request.form.get("symbol"):
            return apology("please provide stock symbol", 400)
        else:
            symbol = request.form.get("symbol")
            responce = lookup(symbol) # API

            if responce == None:
                return apology(symbol + " do not exist or something went wrong", 400)
            else:
                responce["price"] = usd(responce["price"])
                return responce


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    if request.method == "POST":

        # Ensure username is not empty
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure username do not exist
        username = request.form.get("username")
        if db.execute("SELECT * FROM users WHERE username = ?", username):
            return apology("username already exists", 400)

        # Ensure password is not empty
        if not request.form.get("password"):
            return apology("please provide password", 400)
        elif not request.form.get("confirmation"):
            return apology("please repeat your password", 400)

        # Ensure confirm is the same with the password
        password = request.form.get("password")
        confirm = request.form.get("confirmation")
        if password != confirm:
            return apology("the second input of password is not the same with the first", 400)

        # Insert into the database
        hash = generate_password_hash(password)
        db.execute(
            "INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    user_id = session["user_id"]

    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("please provide a valid stock symbol you owned", 400)

        symbol = request.form.get("symbol")
        shares_sell = int(request.form.get("shares"))

        shares_own = db.execute("SELECT SUM(shares) FROM history WHERE user_id=? AND stock=?", user_id, symbol)[0]["SUM(shares)"]

        if shares_sell > shares_own:
            return apology("You don't have that mach shares", 400)

        price = lookup(symbol)["price"]

        # Insert into history table
        db.execute("INSERT INTO history (user_id,stock,price,shares) VALUES (?,?,?,?)", user_id, symbol, price, -shares_sell)

        # Update users table
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", price*shares_sell, user_id)

        return redirect("/")

    elif request.method == "GET":

        stocks = db.execute("SELECT DISTINCT stock FROM history WHERE user_id = ?", user_id)
        # stocks is a list with mutiple dict(stock:?) in it
        return render_template("/sell.html", stocks=stocks)
