select
    user_id,
    concat(
        upper(left(name,1)),
        lower(substring(name from 2 for length(name)-1 ))
        ) as name
from users
order by user_id