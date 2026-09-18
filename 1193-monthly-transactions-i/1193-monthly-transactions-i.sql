with tem as(
select
    to_char(trans_date,'YYYY-MM') as month,
    country,
    state,
    amount
from transactions
)
select
    month,
    country,
    coalesce(count(*),0) as trans_count,
    coalesce(count(*) filter (where state='approved'),0) as approved_count,
    coalesce(sum(amount),0) as trans_total_amount,
    coalesce(sum(amount) filter (where state='approved'),0) as approved_total_amount
from tem
group by month,country
