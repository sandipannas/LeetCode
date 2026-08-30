select
    e.employee_id
from employees as e
left join salaries as s
on e.employee_id=s.employee_id
where s.employee_id is null or e.name is null

union

select
    s.employee_id
from salaries as s
left join employees as e
on s.employee_id=e.employee_id
where e.employee_id is null or s.salary is null

order by employee_id asc