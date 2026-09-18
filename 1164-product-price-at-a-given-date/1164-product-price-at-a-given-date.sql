with tem as(
select
    product_id,
    max(change_date) as change_date
from products
where change_date<='2019-08-16'::date
group by product_id
)
select
    p.product_id,
    min(case
        when t.change_date is null then 10
        else p.new_price
    end) as price
from products as p
left join tem as t
on p.product_id=t.product_id
where p.change_date=t.change_date or t.product_id is null
group by p.product_id