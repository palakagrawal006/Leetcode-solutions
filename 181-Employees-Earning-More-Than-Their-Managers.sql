

select e.name as Employee
    from Employee as e inner join Employee as m 
    on m.id = e.managerId
    where e.salary > m.salary