with tem as(
select
    product_id,
    min(year) as first_year 
from sales
group by product_id
)
select
    s.product_id,
    t.first_year,
    s.quantity,
    s.price
from tem as t
inner join sales as s
on t.first_year=s.year and t.product_id=s.product_id

