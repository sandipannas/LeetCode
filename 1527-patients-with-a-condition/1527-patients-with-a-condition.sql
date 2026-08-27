select *
from patients
where regexp_like(conditions,' DIAB1') or regexp_like(conditions,'^DIAB1')