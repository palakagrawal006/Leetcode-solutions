# Write your MySQL query statement below
select product_id , year as first_year , quantity , price 
from Sales 
group by product_id  
having min(year) 