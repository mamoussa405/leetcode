-- Write your PostgreSQL query statement below
with sub as (
  select employee_id, Count(department_id) as cnt
  from Employee
  group by employee_id
)

select employee_id, department_id
from Employee e
where primary_flag = 'Y' or employee_id in (select employee_id from sub where employee_id = e.employee_id and cnt = 1)