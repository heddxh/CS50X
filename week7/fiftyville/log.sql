-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 找到指定的案件
SELECT description FROM crime_scene_reports
 WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street"
 AND description like "%CS50%";
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- 查询面包房10点到11点的记录
SELECT * FROM bakery_security_logs
 WHERE year = 2021 AND month = 7 AND day = 28
 AND hour = 10;

-- 查询三人笔录
SELECT * FROM interviews
 WHERE year = 2021 AND month = 7 AND day = 28;