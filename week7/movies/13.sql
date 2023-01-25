SELECT people.name
 FROM people
 JOIN movies 


SELECT movie_id
  FROM people
  JOIN stars ON stars.person_id = people.id
 WHERE people.name = "Kevin Bacon" AND birth = 1985