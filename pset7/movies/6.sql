SELECT AVG(ra.rating) FROM ratings ra
JOIN movies mo ON ra.movie_id = mo.id
WHERE mo.year = 2012;