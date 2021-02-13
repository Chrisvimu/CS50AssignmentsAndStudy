SELECT COUNT(mo.title) FROM movies mo
JOIN ratings ra ON mo.id = ra.movie_id
WHERE ra.rating = 10.0;