with tem as(
    select distinct
        salary
    from employee
    order by salary desc
    limit 2
)
select
    case
        when (select count(*) from tem )<2 then null
        else min(salary)
    end as SecondHighestSalary
from tem