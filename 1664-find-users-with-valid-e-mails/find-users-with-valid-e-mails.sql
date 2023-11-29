# Write your MySQL query statement below
SELECT *
FROM Users
WHERE mail REGEXP '^[a-zA-Z]+[0-9_.\\-a-zA-Z]*@leetcode\\.com$'