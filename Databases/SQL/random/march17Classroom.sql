-- Active: 1739339070113@@127.0.0.1@3306@study

CREATE TABLE employee1 (
  id INT PRIMARY KEY NOT NULL,
  Name VARCHAR(50) NOT NULL
);

SELECT * FROM employee1;
INSERT INTO employee1 (id, Name) VALUES (1, 'John Doe'), (2, 'Jane Doe'), (3, 'Alice Smith');

ALTER TABLE employee1 ADD COLUMN employeeID INT FIRST;

UPDATE employee1 SET employeeID = 101 WHERE id = 1;
UPDATE employee1 SET employeeID = 102 WHERE id = 2;
UPDATE employee1 SET employeeID = 103 WHERE id = 3;
ALTER TABLE employee1 ADD COLUMN age INT;

UPDATE employee1 SET age=100 WHERE id=1;
UPDATE employee1 SET age=200 WHERE id=2;
UPDATE employee1 SET age=300 WHERE id=3;

desc employee1;

-- modify the existing primary key to another key
ALTER TABLE employee1 DROP PRIMARY KEY;

ALTER TABLE employee1 ADD PRIMARY KEY(employeeID);

TRUNCATE TABLE employee1;
DROP TABLE employee1;

ALTER TABLE employee1 DROP COLUMN id;

ALTER TABLE employee1 RENAME COLUMN Name TO NAME;

SELECT * FROM employee1;

