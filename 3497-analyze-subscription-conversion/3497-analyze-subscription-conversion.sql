select 
    user_id,

    round(
    avg(activity_duration) filter ( where activity_type='free_trial')
    ,2) as trial_avg_duration,

    round(
    avg(activity_duration) filter ( where activity_type='paid')
    ,2) as paid_avg_duration
    
from useractivity where activity_type!='cancelled'
group by user_id
having max(activity_type)='paid' and min(activity_type)!='paid'
order by user_id