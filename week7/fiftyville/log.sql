-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 找到指定的案件
SELECT description FROM crime_scene_reports
 WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street"
   AND description like "%CS50%";

-- 查询三人笔录
SELECT * FROM interviews
 WHERE year = 2021 AND month = 7 AND day = 28
   AND transcript LIKE "%bakery%";

-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- 查询面包房案发十分钟(10:15-10:25)的记录
SELECT * FROM bakery_security_logs
 WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10
   AND minute BETWEEN 15 AND 25;

-- 查询当日上午指定街道ATM取钱记录
SELECT * FROM atm_transactions
 WHERE year = 2021 AND month = 7 AND day = 28
   AND atm_location = "Leggett Street"
   AND transaction_type = "withdraw";

-- 根据上述两次查询寻找共同的人
SELECT license_plate FROM bakery_security_logs

 WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10
   AND minute BETWEEN 15 AND 25;