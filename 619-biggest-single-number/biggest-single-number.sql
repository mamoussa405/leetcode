-- Write your PostgreSQL query statement below
with sub as (
select num
from MyNumbers
group by num
having count(num) = 1
)
select  Max(num) as num
from sub