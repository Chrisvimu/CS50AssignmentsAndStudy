--SELECT strftime('%Y','now') - (CAST(birth AS INTEGER)) AS "age" FROM people WHERE name = "Emma Stone";

SELECT (CAST(birth AS INTEGER)) AS "age" FROM people WHERE name = "Emma Stone";