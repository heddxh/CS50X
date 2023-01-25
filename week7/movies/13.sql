SELECT people.name
 FROM
 JOIN stars ON stars.movie_id
WHERE movies.id IN
      (SELECT movie_id
         FROM people
         JOIN stars ON stars.person_id = people.id
        WHERE people.name = "Kevin Bacon" AND birth = 1985)