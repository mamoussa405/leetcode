# Write your MySQL query statement below
SELECT p.product_id,
CASE
WHEN units IS NOT NULL THEN round(SUM(units * price) / SUM(units), 2)
ELSE 0 END AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
WHERE purchase_date  BETWEEN start_date AND end_date OR purchase_date IS NULL
GROUP BY p.product_id