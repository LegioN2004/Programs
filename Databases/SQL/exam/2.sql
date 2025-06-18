use study;

show TABLES;

CREATE TABLE students (
    id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    dept VARCHAR(10) NOT NULL,
    age INT,
    marks INT
);

INSERT INTO students (id, name, dept, age, marks) VALUES
(1, 'Amit', 'CSE', 20, 85),
(2, 'Priya', 'ECE', 21, 72),
(3, 'Rahul', 'CSE', 22, 92),
(4, 'Divya', 'ME', 23, 70),
(5, 'Anjali', 'CSE', 22, 92),
(6, 'Mohan', 'ECE', 20, 85),
(7, 'Sneha', 'CSE', 21, NULL);

select * from students;

select name from students where marks > (SELECT AVG(marks) from students);

select name from students where age > all (select age from students where dept='ECE');

select marks, count(*) as count from students where marks IS NOT NULL group by marks having count(*) > 1;

select name, marks from students where marks = ( select max(marks) from students where dept = 'CSE');

select AVG(marks) avg, dept from students group by dept ORDER BY avg desc;

select name from students where dept not in ('CSE', 'ECE');

SELECT MAX(marks) as marks from students where marks < (SELECT MAX(marks) FROM students);

select name, age from students where age = (select age from students WHERE name = 'Amit');

SELECT * from students where name like '%a' AND marks is not null;

select * from students s where marks = (select MAX(marks) from students where dept = s.dept);

select dept from students group by dept having AVG(marks) > 80;