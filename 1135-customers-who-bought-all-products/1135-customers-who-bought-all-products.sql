# Write your MySQL query statement below
SELECT customer_id 
FROM Customer
GROUP BY customer_id 
HAVING count(distinct product_key) IN (
  SELECT count(distinct product_key)
  FROM Product 
)