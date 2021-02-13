SELECT so.name
FROM songs so JOIN artists ar ON so.artist_id = ar.id
WHERE ar.name = "Post Malone";