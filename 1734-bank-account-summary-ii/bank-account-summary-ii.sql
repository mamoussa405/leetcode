-- Write your PostgreSQL query statement below
select name, Sum(amount) as balance
from Users u
join Transactions t
on u.account = t.account
group by t.account, u.name
having Sum(amount) > 10000