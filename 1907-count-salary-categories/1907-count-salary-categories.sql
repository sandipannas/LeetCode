with tem as (
select
    count(income) filter ( where income <20000) as LowSalary,
    count(income) filter ( where income between 20000 and 50000) as AverageSalary,
    count(income) filter ( where income >50000) as HighSalary
from accounts
)
select
    'Low Salary' as category,
    LowSalary as accounts_count
from tem

union all

select
    'Average Salary' as category,
    AverageSalary as accounts_count
from tem

union all

select
    'High Salary' as category,
    HighSalary as accounts_count
from tem
