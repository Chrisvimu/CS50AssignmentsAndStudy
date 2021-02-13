-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Query to get DB Schema:
.schema;

-- Following the hint, query to get the reports of the date of the crime on Chamberlin street:
SELECT * FROM crime_scene_reports WHERE year = 2020 AND month = 7 and day = 28 AND street LIKE "%Chamberlin%";

-- Check interviews conducted on the day of the crime that mention the courthouse, should result in 3 witnesses.
SELECT * FROM interviews WHERE year = 2020 AND month = 7 and day = 28 AND transcript LIKE "%courthouse%" ORDER BY name DESC;
-- The results from the witnesses mention diferent things, I'll be addresing them by name.

-- Ruth says that: She saw someone get into a car in the courthouse parking lot within 10 minutes of the theft.
-- Checking the security logs.
SELECT * FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 5 AND minute <= 25 AND activity = "exit"; -- 6 results.

-- Raymond says that: He saw the tief leaving the courthouse and called somneone for less tham a minute and asked by the phone to book the earliest flight out of Fiftyville tomorrow (29).
-- Checking the phone calls.
SELECT * FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration <= 60; -- 10 results.
-- Checking the earliest flights.
SELECT * FROM flights fl JOIN airports ai ON fl.origin_airport_id = ai.id WHERE fl.year = 2020 AND fl.month = 7 AND fl.day = 29 AND ai.city LIKE "%Fiftyville%" ORDER BY hour ASC, minute DESC LIMIT 1;

-- Eugene says thath: He saw the tief previusly withdrawing money from the ATM on Fifer Stree.
SELECT * FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location LIKE "%Fifer Street%" AND transaction_type = "withdraw"; -- 8 results.

-- Check list of people who took the earliest flight out of Fiftyville in the 29/07/2020, made a call within 10 mins of the ruber duck incident and withdrew money in the same day
-- and exited the courtyard in the same timewindow.
SELECT pe.name, pe.id from people pe
    JOIN phone_calls pc ON pe.phone_number = pc.caller
    JOIN passengers pa ON pe.passport_number = pa.passport_number
    JOIN flights fl ON pa.flight_id = fl.id
    JOIN bank_accounts ba ON pe.id = ba.person_id
    JOIN atm_transactions at ON ba.account_number = at.account_number
    JOIN courthouse_security_logs csl ON pe.license_plate = csl.license_plate
    WHERE fl.id IN
        (SELECT fl.id FROM flights fl
         JOIN airports ai ON fl.origin_airport_id = ai.id
         WHERE fl.year = 2020 AND fl.month = 7 AND fl.day = 29
         AND ai.city LIKE "%Fiftyville%" ORDER BY hour ASC, minute DESC LIMIT 1)
    AND pc.caller IN
        (SELECT caller FROM phone_calls
         WHERE year = 2020 AND month = 7
         AND day = 28 AND duration <= 60)
    AND ba.account_number IN
        (SELECT account_number FROM atm_transactions
         WHERE year = 2020 AND month = 7 AND day = 28
         AND atm_location LIKE "%Fifer Street%" AND transaction_type = "withdraw")
    AND pe.license_plate IN
        (SELECT license_plate FROM courthouse_security_logs
         WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10
         AND minute >= 5 AND minute <= 25 AND activity = "exit")
    GROUP BY pe.id;
-- Acording to the result, the tief was Ernest *DRAMATIC NOISES*

-- Check calls made by Ernest, to get who helped him.
SELECT pe.name, pe.id FROM people pe
    JOIN phone_calls pc ON pe.phone_number = pc.receiver
    AND pe.phone_number IN
    (SELECT pc.receiver FROM people pe
     JOIN phone_calls pc ON pe.phone_number = pc.caller
     WHERE pc.year = 2020 AND pc.month = 7 AND pc.day = 28 AND pc.duration <= 60
     AND name = "Ernest");
-- Acording to the result, the tief accomplice is Berthold

-- Check flights that Ernest took, to check for the destination city.
SELECT ai.city, fl.destination_airport_id FROM people pe
    JOIN passengers pss ON pe.passport_number = pss.passport_number
    JOIN flights fl ON pss.flight_id = fl.id
    JOIN airports ai ON fl.destination_airport_id = ai.id
    WHERE fl.id =
        (SELECT fl.id FROM flights fl
         JOIN airports ai ON fl.origin_airport_id = ai.id
         JOIN passengers pss ON fl.id = pss.flight_id
         WHERE fl.year = 2020 AND fl.month = 7 AND fl.day = 29
         AND ai.city LIKE "%Fiftyville%" AND pss.passport_number =
            (SELECT passport_number FROM people WHERE name = "Ernest"));
-- Ernest went to London to cash in the crime.