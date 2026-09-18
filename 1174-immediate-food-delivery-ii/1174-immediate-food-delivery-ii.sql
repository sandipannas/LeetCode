with tem as(
select 
    delivery_id as did,
    customer_id as cid,
    order_date as od,
    customer_pref_delivery_date as pd,
    rank() over (partition by customer_id order by order_date) as rank
from delivery
)
select
round((
    (select count(*) from tem where rank=1 and od=pd)::numeric/
    (select count(*) from tem where rank=1)*100),
2) as immediate_percentage