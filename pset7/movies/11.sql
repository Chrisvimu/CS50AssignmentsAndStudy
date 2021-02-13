SELECT mo.title FROM movies mo
JOIN stars st ON mo.id = st.movie_id
JOIN ratings ra ON mo.id = ra.movie_id
JOIN people pe ON st.person_id = pe.id
WHERE pe.name = "Chadwick Boseman"
ORDER BY ra.rating DESC LIMIT 5;