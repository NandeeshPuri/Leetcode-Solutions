# Write your MySQL query statement below
# Write your MySQL query statement below
with cte as(select requester_id id from RequestAccepted
union all
select accepter_id id from RequestAccepted)


select id, count(*) num  from cte group by 1 order by 2 desc limit 1