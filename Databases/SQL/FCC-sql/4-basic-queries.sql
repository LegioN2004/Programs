select * from fcc;

select fcc.name, fcc.major from fcc;


select fcc.name, fcc.major from fcc ORDER BY fcc.name ;
select fcc.name, fcc.major from fcc ORDER BY fcc.name DESC;
select * from fcc ORDER BY fcc.major, fcc.student_id;
select * from fcc ORDER BY fcc.major, fcc.student_id desc;