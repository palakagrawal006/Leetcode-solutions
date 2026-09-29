# Write your MySQL query statement below
SELECT e.name 
from Employee e join Employee e2
on e.id = e2.managerId
group by e.name , e.id
having count(e2.id)>= 5 
