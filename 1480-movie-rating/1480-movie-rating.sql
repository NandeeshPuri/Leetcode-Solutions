# Write your MySQL query statement below
(SELECT u.name AS results
FROM MovieRating AS m, Users AS u
WHERE u.user_id=m.user_id 
GROUP BY m.user_id
ORDER BY COUNT(m.user_id) DESC, u.name LIMIT 1)

UNION ALL

(SELECT m.title AS results
FROM MovieRating AS r, Movies AS m
WHERE m.movie_id=r.movie_id
AND r.created_at like "2020-02-%"
GROUP BY r.movie_id
ORDER BY AVG(r.rating) DESC, m.title LIMIT 1);