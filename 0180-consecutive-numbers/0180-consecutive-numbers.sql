with tem as(
    select 
        id,
        num,
        lag(num) over (order by id) as pre_num,
        lead(num) over (order by id) as post_num
    from logs
)
select distinct
    num as consecutiveNums
from tem
where pre_num=num and num=post_num