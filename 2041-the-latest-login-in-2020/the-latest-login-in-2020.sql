-- Write your PostgreSQL query statement below
with sub as (
  select user_id, time_stamp
  from Logins
  where time_stamp >= '2020-01-1 00:00:00' and time_stamp < '2021-01-1 00:00:00'
)
select user_id, max(time_stamp) as last_stamp
from sub
group by user_id