# Write your MySQL query statement below
SELECT person_name FROM Queue
WHERE turn = (
    SELECT MAX(turn) FROM (
        SELECT q1.turn, SUM(q2.weight) FROM Queue AS q1 JOIN Queue AS q2 ON q1.turn >= q2.turn GROUP BY q1.turn HAVING              SUM(q2.weight) <= 1000 ORDER BY q1.turn
    ) AS temp
);