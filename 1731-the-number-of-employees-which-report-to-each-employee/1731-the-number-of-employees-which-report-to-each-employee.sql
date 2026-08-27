select 
    e1.employee_id,
    min(e1.name) as name,
    count(*) as reports_count,
    round(avg(e2.age)) as average_age
from employees as e1
inner join employees as e2
on e1.employee_id = e2.reports_to
group by e1.employee_id
order by e1.employee_id