# Write your MySQL query statement below
(SELECT u.name AS results FROM Users AS u 
    JOIN 
(SELECT user_id, COUNT(movie_id) as movies FROM MovieRating GROUP BY user_id) AS m
    ON u.user_id = m.user_id ORDER BY m.movies DESC, u.name LIMIT 1)

UNION ALL

(SELECT m.title AS result FROM Movies AS m 
    JOIN 
(SELECT movie_id, AVG(rating) as avg_ratings FROM MovieRating WHERE YEAR(created_at) = 2020 AND MONTH(created_at) = 02 GROUP BY movie_id) AS mr 
    ON m.movie_id = mr.movie_id ORDER BY mr.avg_ratings DESC, m.title LIMIT 1)