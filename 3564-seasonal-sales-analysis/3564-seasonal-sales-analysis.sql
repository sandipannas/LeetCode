with tem as (
select
    s.product_id as pid,
    case
        when extract(month from sale_date) in ( 12 , 1 , 2) then 'Winter'
        when extract(month from sale_date) in ( 3 , 4 , 5) then 'Spring'
        when extract(month from sale_date) in ( 6 , 7 , 8) then 'Summer'
        else 'Fall'
    end 
    as season, 
    category,
    quantity,
    quantity*price as revenue
from sales as s
inner join products as p
on s.product_id=p.product_id
),
tem2 as(
select 
    season,
    category,
    sum(quantity) as total_quantity,
    sum(revenue) as total_revenue,
    row_number() over (partition by season order by sum(quantity) desc,sum(revenue) desc,category asc) as rank
from tem
group by category,season
)
select 
    season,
    category,
    total_quantity,
    total_revenue
from tem2 where rank=1 order by season
