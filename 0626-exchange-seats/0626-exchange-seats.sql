select
    case
        when (select count(*) from seat)%2=1 and 
        id=(select count(*) from seat) then id
        when id%2=0 then id-1
        else id+1
    end as id,
    student
from seat
order by id asc