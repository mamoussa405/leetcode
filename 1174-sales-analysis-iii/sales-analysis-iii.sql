-- Write your PostgreSQL query statement below
with sub as (
select p.product_id
from Product p
join Sales s
on p.product_id = s.product_id
group by p.product_id
having min(sale_date) >= '2019-01-01' and max(sale_date) <= '2019-03-31'
)

select p.product_id, p.product_name
from Product p, sub s
where p.product_id = s.product_id
