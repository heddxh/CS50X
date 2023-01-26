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

-- 查询当日电话记录
SELECT * FROM phone_calls
 WHERE year = 2021 AND month = 7 AND day = 28;

-- 根据上述三次查询寻找共同的人
SELECT * FROM people
 WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
                          WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10
                            AND minute BETWEEN 15 AND 25)
   AND id IN (SELECT person_id FROM bank_accounts
               WHERE account_number IN(SELECT account_number FROM atm_transactions
                                        WHERE year = 2021 AND month = 7 AND day = 28
                                          AND atm_location = "Leggett Street"
                                          AND transaction_type = "withdraw"))
   AND phone_number IN (SELECT caller FROM phone_calls
                         WHERE year = 2021 AND month = 7 AND day = 28
                           AND duration < 60);
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       |
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+

-- 查询本地机场
SELECT * from airports
 WHERE city = "Fiftyville";

-- 查询次日起飞最早航班
SELECT * from flights
 WHERE origin_airport_id = 8
   AND year = 2021 AND month = 7 AND day = 29
 ORDER BY hour
 LIMIT 1;

-- 找到上述二人中称作该航班的人
SELECT * FROM passengers
 WHERE flight_id = 36;