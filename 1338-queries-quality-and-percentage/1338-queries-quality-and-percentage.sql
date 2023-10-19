# Write your MySQL query statement below
Select query_name,
round(avg(cast(rating as decimal)/position),2) as quality,
round(sum(case when rating<3 then 1 else 0 end)*100/count(*),2) as poor_query_percentage
From queries
Group By query_name;