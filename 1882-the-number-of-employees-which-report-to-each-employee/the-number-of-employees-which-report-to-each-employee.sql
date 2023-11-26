-- Write your PostgreSQL query statement below
with sub as (
select reports_to as employee_id,count(*) as reports_count, round(avg(age)) as average_age
from Employees e1
where reports_to is not null
group by reports_to
)

select employee_id, (select name from Employees where sub.employee_id = Employees.employee_id) as name,
reports_count, average_age
from sub
order by employee_id
