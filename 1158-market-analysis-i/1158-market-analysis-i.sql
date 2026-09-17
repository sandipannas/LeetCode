select
    user_id as buyer_id,
    min(join_date) as join_date,
    count(*) filter (where order_date between '2019-01-01' and '2019-12-31') as orders_in_2019
from users as u
left join orders as o
on u.user_id=o.buyer_id
group by user_id
