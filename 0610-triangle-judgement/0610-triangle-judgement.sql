SELECT *,   
    CASE 
        WHEN 
            (x + y <= z) 
            OR (z + x <= y) 
            OR (z + y <= x) 
            OR (x <=0 OR y<=0 OR z<=0) 
        THEN "No"
    ELSE "Yes" END AS triangle 
FROM Triangle;