SELECT title FROM movies
    WHERE id IN
        (SELECT movie_id FROM stars
            WHERE person_id IN
                (SELECT id FROM people
                    WHERE name = "Johnny Depp")
        )
    JOIN
        (SELECT title FROM movies
            WHERE id IN
                (SELECT movie_id FROM stars
                    WHERE person_id IN
                        (SELECT id FROM people
                            WHERE name = "Helena Bonham Carter")
                ));

SELECT title FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN shows ON stars.show_id = shows.id
    WHERE name = "Steve Carell";

