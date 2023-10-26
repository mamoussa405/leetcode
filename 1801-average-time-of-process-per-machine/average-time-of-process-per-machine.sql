-- Write your PostgreSQL query statement below
SELECT t1.machine_id, round(cast(avg(t2.timestamp - t1.timestamp) as numeric), 3) AS processing_time
FROM Activity t1
JOIN Activity t2
ON t1.machine_id = t2.machine_id and t1.process_id = t2.process_id
and t1.activity_type = 'start' and t2.activity_type = 'end'
GROUP BY t1.machine_id