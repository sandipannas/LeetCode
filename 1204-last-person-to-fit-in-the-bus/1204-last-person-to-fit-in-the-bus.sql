with tem as(
select
 person_name,
 sum(weight) over (order by turn) as acc_weight
from Queue
order by turn desc
)
select
    person_name
from tem
where acc_weight<=1000
limit 1

