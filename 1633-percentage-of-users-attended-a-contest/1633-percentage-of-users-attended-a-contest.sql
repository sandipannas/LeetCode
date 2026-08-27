select
    r.contest_id,
    round( (count(r.user_id)::numeric/(select count(*) from users))*100 ,2) 
    as percentage
from users as u
inner join register as r
on u.user_id=r.user_id
group by r.contest_id
order by percentage desc,contest_id asc
