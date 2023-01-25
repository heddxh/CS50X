SELECT DISTINCT(people.name)
  FROM stars
  JOIN people ON people.id = stars.person_id
  JOIN movies ON movies.id = stars.movie_id
 WHERE movies.id IN
       (SELECT movie_id
          FROM people
          JOIN stars ON stars.person_id = people.id
         WHERE people.name = "Kevin Bacon" AND birth = 1958)
   AND people.name != "Kevin Bacon";