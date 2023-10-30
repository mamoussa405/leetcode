-- Write your PostgreSQL query statement below
select name
from SalesPerson
where name not in (
  select s.name
  from Orders o
  join Company c on o.com_id = c.com_id
  right join SalesPerson s on o.sales_id = s.sales_id
  where c.name = 'RED'
)