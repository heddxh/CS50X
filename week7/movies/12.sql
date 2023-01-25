SELECT title
  FROM (
    SELECT title,  FROM people AS t1
      JOIN stars ON stars.person_id = people.id
      JOIN movies ON movies.id = stars.movie_id
     WHERE name = "Helena Bonham Carter"
  )
  JOIN stars ON stars.person_id = people.id
  JOIN movies ON movies.id = stars.movie_id
 WHERE name = "Johnny Depp"
