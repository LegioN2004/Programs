CREATE TABLE table1 (
    Rollno INT PRIMARY KEY,
    Name VARCHAR(50),
    Branch VARCHAR(50)
);

CREATE TABLE table2 (
    phone INT,
    address VARCHAR(50),
    age INT
);

INSERT INTO table1 (Rollno, Name, Branch) VALUES(41, 'hello', 'CSE');
INSERT INTO table1 (Rollno, Name, Branch) VALUES(21, 'hiii', 'CSE');
INSERT INTO table2 (phone, address, age) VALUES(2112341234, 'tur murot', 1000);

SELECT * FROM table1;
SELECT * from table2;

CREATE TABLE students (
    Rollno INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT,
    Branch VARCHAR(50)
);

INSERT INTO students(Rollno, Name, Age, Branch) VALUES(1, "mili", 21, "CSE");
INSERT INTO students(Rollno, Name, Age, Branch) VALUES(2, "mili2", 21, "CSE");
INSERT INTO students(Rollno, Name, Age, Branch) VALUES(3, "mili3", 22, "ECE");
INSERT INTO students(Rollno, Name, Age, Branch) VALUES(4, "mili4", 11, "CSE");
INSERT INTO students(Rollno, Name, Age, Branch) VALUES(5, "mili5", 10, "CSE");
DELETE from students where Rollno=2;
SELECT * from students;
select * from students where age > 20;
select * from students where Branch='ECE';
UPDATE students SET Age=19 where Name='mili4';
SELECT * from students;
