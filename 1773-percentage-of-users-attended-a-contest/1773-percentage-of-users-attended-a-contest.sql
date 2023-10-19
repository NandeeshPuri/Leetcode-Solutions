# Write your MySQL query statement below
Select r.contest_id,Round(COUNT(r.user_id)*100/(Select Count(*)From users),2) AS percentage
From Register r
Group By r.contest_id
Order By percentage Desc,r.contest_id