SELECT DISTINCT(pe.name) FROM people pe
JOIN stars st ON pe.id = st.person_id
JOIN movies mo ON st.movie_id = mo.id
WHERE mo.year = 2004
ORDER BY pe.birth ASC;