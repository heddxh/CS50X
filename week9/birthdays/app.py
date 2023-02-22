import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        date = request.form.get("date")
        month = date[5:7]
        day = date[8:]
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)
        return redirect("/")

    else:

        # Display the entries in the database on index.html
        data = db.execute("SELECT * FROM birthdays")
        birthdays = []
        for item in data:
            birthday = {}
            birthday["id"] = item["id"]
            birthday["name"] = item["name"]
            birthday["date"] = str(item["month"]) + "月" + str(item["day"]) + "日"
            birthdays.append(birthday)
        return render_template("index.html", birthdays=birthdays)


