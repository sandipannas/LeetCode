select
    tweet_id
from tweets
where not regexp_like(content,'^[0-9a-zA-Z !]{1,15}$')
