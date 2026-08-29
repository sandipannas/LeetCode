select
    employee_id,
    case
        when (not regexp_like(name,'^[mM]')) and employee_id%2=1 then salary 
        else 0
    end as bonus
from employees
order by employee_id asc
