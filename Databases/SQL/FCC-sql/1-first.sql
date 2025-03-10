DROP table fcc;

create table fcc (
    student_id INT PRIMARY KEY AUTO_INCREMENT, -- using AUTO_INCREMENT we can just leave out the fields and values for the id part, it'll automatically fill it.
    name VARCHAR(20) NOT NULL,
    major VARCHAR(20) DEFAULT "undeclared" UNIQUE
    -- PRIMARY KEY (student_id) -- primary key is by default unique and not null
    -- you can do this as well, instead of writing out with the id initialization itself
);

DESCRIBE fcc;

ALTER TABLE fcc ADD age DECIMAL(3, 2); -- 3 total digits, 2 after the decimal point. eg: 3._ _

ALTER TABLE fcc drop column age;

insert into fcc(student_id, name, major, CGPA) VALUES(1, "hi", "CS", 1.00);
insert into fcc VALUES(2, "hello", "CS2", 1.00);

-- if a student didn't have a major, in the first fcc() part, don't give the args of the one you want to have null by default.
insert into fcc(student_id, name, CGPA) VALUES(3, "hello", 2.00);

insert into fcc VALUES(4, "hello", "CS", 2.00);
insert into fcc(name, major,age) VALUES("hello", "CS4", 9.00);

SELECT * from fcc;

ALTER TABLE fcc RENAME COLUMN age to CGPA;
insert into fcc(student_id, name, major, CGPA) VALUES(5, "gargu", "biology", 9.00);
insert into fcc(student_id, name, major, CGPA) VALUES(6, "milu", "programming", 8.00);
insert into fcc(student_id, name, major, CGPA) VALUES(7, "name7", "sociology", 5.00);
insert into fcc(student_id, name, major, CGPA) VALUES(8, "name8", "zoology", 7.00);
insert into fcc(student_id, name, major, CGPA) VALUES(9, "name9", "biology", 6.00);

-- ALTER Table fcc DROP CONSTRAINT UNIQUE; -- didn't work




