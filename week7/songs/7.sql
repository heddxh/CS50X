SELECT SUM(energy) / count(*) AS "average energy" FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = "Drake");