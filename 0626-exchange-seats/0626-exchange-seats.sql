with tot as (
    select count(*) as total from seat
)            
select
    case
        when tot.total%2=1 and 
        id=tot.total then id
        when id%2=0 then id-1
        else id+1
    end as id,
    student
from seat,tot
order by id asc