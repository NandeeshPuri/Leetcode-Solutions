# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT employee_id,department_id from Employee
GROUP BY employee_id
having count(employee_id)=1 
UNION 
SELECT employee_id,department_id from Employee
where primary_flag='Y'