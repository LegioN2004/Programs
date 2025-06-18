use study;

show TABLES;

select * from students;

alter table students add email VARCHAR(10);

ALTER table students drop email;

drop table students;

desc students;

create table students (
    id int primary key,
    name varchar(50),
    dept varchar(30),
    age int
);

insert into students(id, name, dept, age) values(1, 'John Doe', 'Computer Science', 20), (2, 'Jane Smith', 'Mathematics', 22), (3, 'Alice Johnson', 'Physics', 21), (4, 'Bob Brown', 'Chemistry', 23), (5, 'Charlie White', 'Biology', 19);


UPDATE students set name='gahori' where id=1;


desc students;
alter table students MODIFY age int default 100;

insert into students(id, name, dept) values(6, 'Eve Adams', 'History');


SELECT * from students1;

select DISTINCT name from students1;

select * from students1 where name like '%2%';


select * from students1 where name in ('name2', 'name3');

select * from students1 where name in(select name from students1);

select name from students1 group by name having id = 101;

