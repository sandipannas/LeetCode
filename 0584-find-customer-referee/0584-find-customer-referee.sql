select
    c.name
from 
    customer c
left join
    customer r on c.referee_id=r.id
where
    r.id is null or r.id!=2