with tem as(
    select
        player_id as pid,
        event_date as login,
        lag(event_date) over (partition by player_id order by event_date) as pre_login,
        lead(event_date) over (partition by player_id order by event_date) as post_login
    from activity
),
tem2 as (
select distinct
    pid
from tem
where pre_login is null and (post_login::date-"login"::date=1)
)
select
     round(coalesce((select count(*) from tem2),0)::numeric/(select count(distinct pid) from tem),2) as fraction
