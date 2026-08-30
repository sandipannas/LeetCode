select 
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
from employee as e
inner join department as d
on e.departmentId=d.id
where (e.salary,d.id) in ( 
    select max(e2.salary), d2.id
    from employee as e2
    inner join department as d2
    on e2.departmentId=d2.id
    group by d2.id
    )
