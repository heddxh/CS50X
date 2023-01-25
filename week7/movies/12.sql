SELECT title FROM people
  JOIN stars ON stars.person_id = people.id
  JOIN movies ON movies.id = stars.movie_id
 WHERE name = "Johnny Depp"
SELECT title FROM people
  JOIN stars ON stars.person_id = people.id
  JOIN movies ON movies.id = stars.movie_id
 WHERE name = "Helena Bonham Carter")
