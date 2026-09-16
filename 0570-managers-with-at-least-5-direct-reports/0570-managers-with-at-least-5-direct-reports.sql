select
    min(e1.name) as name
from employee as e1
inner join employee as e2
on e1.id=e2.managerId
group by e1.id
having count(*)>=5