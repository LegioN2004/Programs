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
