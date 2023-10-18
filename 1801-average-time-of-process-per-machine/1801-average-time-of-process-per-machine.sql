# Write your MySQL query statement below
select machine_id, Round(2 * avg(if(activity_type = 'start',-timestamp, timestamp)),3) as processing_time from activity group by machine_id