select * from fcc;

select fcc.name, fcc.major from fcc;


select fcc.name, fcc.major from fcc ORDER BY fcc.name ;
select fcc.name, fcc.major from fcc ORDER BY fcc.name DESC;
select * from fcc ORDER BY fcc.major, fcc.student_id;
select * from fcc ORDER BY fcc.major, fcc.student_id desc;

select * from fcc limit 2; -- shows 2 only

select * from fcc where `CGPA` <> 1.0 order by student_id asc; -- error

select * from fcc where name in ("gargu", "milu");
select * from fcc where name in ("gargu", "milu") AND cgpa > 1;

