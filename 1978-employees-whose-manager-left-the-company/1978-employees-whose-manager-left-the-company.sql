# Write your MySQL query statement below
SELECT 
    E1.employee_id 
FROM 
    Employees AS E1 
WHERE   
    E1.salary < 30000 
    AND E1.manager_id IS NOT NULL
    AND E1.manager_id NOT IN 
    (SELECT E2.employee_id 
     FROM Employees AS E2)
ORDER BY 
    E1.employee_id;
