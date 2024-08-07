# Write your MySQL query statement below
SELECT author_id as id FROM Views GROUP BY author_id HAVING SUM(IF(viewer_id = author_id, 1, 0)) >= 1 ORDER BY author_id;