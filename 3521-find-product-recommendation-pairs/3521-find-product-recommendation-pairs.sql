with tem as(
    select 
        user_id as id,
        pp.product_id as pid,
        quantity,
        category
    from productpurchases as pp
    inner join productinfo as i
    on pp.product_id=i.product_id
    where quantity>0
)
select 
    t1.pid as product1_id,
    t2.pid as product2_id,
    min(t1.category) as product1_category,
    min(t2.category) as product2_category,
    count(*) as customer_count
from tem as t1
inner join tem as t2
on t1.id=t2.id
where t1.pid<t2.pid
group by t1.pid,t2.pid
having count(*)>=3
order by customer_count desc,t1.pid asc,t2.pid asc