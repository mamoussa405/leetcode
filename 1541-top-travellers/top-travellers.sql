# Write your MySQL query statement below
SELECT name, SUM(case when distance is not null then distance else 0 end) AS travelled_distance
FROM Users u
LEFT JOIN Rides r
ON u.id = r.user_id
GROUP BY r.user_id
ORDER BY travelled_distance desc,
name asc