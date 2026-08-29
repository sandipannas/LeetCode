select 
    machine_id,
    round((sum(timestamp) filter (where activity_type='end') - sum(timestamp) filter (where activity_type='start'))::numeric/(count(*)/2),3) as processing_time
from activity
group by machine_id