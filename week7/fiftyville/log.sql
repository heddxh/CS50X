-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 找到指定的案件
SELECT description FROM crime_scene_reports
 WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street"
   AND description like "%CS50%";

-- 查询三人笔录
SELECT * FROM interviews
 WHERE year = 2021 AND month = 7 AND day = 28
   AND transcript LIKE "%bakery%";

-- 查询面包房案发十分钟(10:15-10:25)的记录
SELECT * FROM bakery_security_logs
 WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10
   AND minute BETWEEN 15 AND 25;
