SELECT title FROM people
  JOIN stars ON stars.person_id = people.id
  JOIN movies ON movies.id = stars.movie_id
 WHERE name = "Johnny Depp"
    AS t1
(SELECT title FROM people
  JOIN stars ON stars.person_id = people.id
  JOIN movies ON movies.id = stars.movie_id
 WHERE name = "Helena Bonham Carter"
    AS t2)
 WHERE t1.title = t2.title;