SELECT pe.name FROM people pe
JOIN stars st ON pe.id = st.person_id
JOIN movies mo ON st.movie_id = mo.id
WHERE mo.title IN

    (SELECT mo.title AS title FROM movies mo
    JOIN stars st ON mo.id = st.movie_id
    JOIN people pe ON st.person_id = pe.id
    WHERE pe.name = "Kevin Bacon" AND pe.birth = 1958)

AND pe.name != "Kevin Bacon";
