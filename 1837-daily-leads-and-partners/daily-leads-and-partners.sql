-- Write your PostgreSQL query statement below
select date_id, make_name, Count(distinct lead_id) as unique_leads, Count(distinct partner_id) as unique_partners
from DailySales
group by date_id, make_name