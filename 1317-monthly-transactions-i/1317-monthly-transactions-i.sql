# Write your MySQL query statement below
SELECT 
    Date_Format(trans_date,'%Y-%m') AS month,
    country,
    count(*) AS trans_count,
    sum(IF(state='approved',1,0)) AS approved_count,
    sum(amount) AS trans_total_amount,
    sum(IF(state = 'approved',amount,0)) AS approved_total_amount
FROM Transactions
Group By Date_Format(trans_date,'%Y-%m'),country;
