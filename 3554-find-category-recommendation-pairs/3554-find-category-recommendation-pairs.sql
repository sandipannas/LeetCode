with us as (
select distinct
    user_id as id,
    category as cat
from ProductPurchases as pp
inner join ProductInfo as i
on pp.product_id=i.product_id
where quantity > 0
)
select
    u1.cat as category1,
    u2.cat as category2,
    count(*) as customer_count
from us as u1
inner join us as u2
on u1.id=u2.id
where u1.cat<u2.cat
group by u1.cat,u2.cat
having count(*)>=3
order by customer_count desc,category1 asc,category2 asc