with tem as
(
    select
        visited_on,
        sum(amount) as daily_total
    from customer
    group by visited_on 
    order by visited_on
),
tem2 as (
    select
        visited_on,
        sum(daily_total) over (
            order by visited_on
            rows between 6 preceding
            and current row
        ) as amount,
        row_number() over (order by visited_on) as num,
        round(avg(daily_total) over(
            order by visited_on
            rows between 6 preceding
            and current row
        ),2) as average_amount
    from tem
)
select 
    visited_on,
    amount,
    average_amount
from tem2
where num>=7
