-- Write your PostgreSQL query statement below
delete from Person
where (id, email) not in (
  select min(id), email
  from Person
  group by email
)