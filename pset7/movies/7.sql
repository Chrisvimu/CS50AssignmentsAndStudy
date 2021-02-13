SELECT ra.rating, mo.title FROM movies mo
JOIN ratings ra ON mo.id = ra.movie_id
WHERE mo.year = 2010
ORDER BY ra.rating DESC, title ASC;