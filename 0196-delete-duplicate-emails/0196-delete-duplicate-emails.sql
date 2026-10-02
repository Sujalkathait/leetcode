# Write your MySQL query statement below
DELETE t1
FROM person t1
JOIN person t2
ON t1.email = t2.email
AND t1.id > t2.id;