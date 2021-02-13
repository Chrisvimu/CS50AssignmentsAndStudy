SELECT rs1.title FROM


(SELECT mo.title AS title FROM movies mo
JOIN stars st ON mo.id = st.movie_id
JOIN people pe ON st.person_id = pe.id
WHERE pe.name = "Helena Bonham Carter") AS rs1

INNER JOIN

(SELECT mo.title AS title FROM movies mo
JOIN stars st ON mo.id = st.movie_id
JOIN people pe ON st.person_id = pe.id
WHERE pe.name = "Johnny Depp") AS rs2

ON rs1.title = rs2.title;
