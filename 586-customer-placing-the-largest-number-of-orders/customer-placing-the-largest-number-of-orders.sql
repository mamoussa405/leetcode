-- Write your PostgreSQL query statement below
with sub as (
select customer_number, count(*) as group_size
from Orders
group by customer_number
order by group_size DESC
)
select customer_number
from sub
limit 1
