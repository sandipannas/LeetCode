with tem as(
select 
    requester_id as id
from requestAccepted

union all

select 
    accepter_id as id
from requestAccepted
)
select 
    id,
    count(*) as num
from tem
group by id
order by count(*) desc
limit 1