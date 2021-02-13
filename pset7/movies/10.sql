SELECT DISTINCT(pe.name) FROM people pe
JOIN directors di ON pe.id = di.person_id
JOIN movies mo ON di.movie_id = mo.id
JOIN ratings ra ON mo.id = ra.movie_id
WHERE ra.rating >= 9.0;