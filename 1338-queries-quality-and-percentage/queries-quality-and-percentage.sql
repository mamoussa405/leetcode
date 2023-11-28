-- Write your PostgreSQL query statement below

select query_name, round(avg(cast(rating as decimal) / position), 2) as quality, 
round(cast(count(case when rating < 3 then 1 end) as decimal) / count(rating) * 100, 2) as poor_query_percentage
from Queries
group by query_name