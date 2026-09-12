select 
    t1.id,
    case
        when min(t1.p_id) is null then 'Root'
        when min(t2.id) is null then 'Leaf'
        else 'Inner'
    end as type
from tree as t1
left join tree as t2
on t1.id=t2.p_id
group by t1.id
