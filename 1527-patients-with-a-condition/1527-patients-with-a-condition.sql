select *
from patients
where regexp_like(conditions,'(^| )DIAB1')