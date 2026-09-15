CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  RETURN QUERY (
    with tem as(
        select distinct
            e.salary,
            dense_rank() over ( order by e.salary desc) as rank
        from employee as e
        order by e.salary desc
    )
    select
        case
            when N<=0 then null
            when (select count(*) from tem)<N then null
            else (select tem.salary from tem where rank=N)
        end as getNthHightestSalary
    from tem as t
    limit 1
  );
END;
$$ LANGUAGE plpgsql;