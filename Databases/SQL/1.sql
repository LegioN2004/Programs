CREATE TABLE student3(
    ID int PRIMARY KEY,
    Name VARCHAR(50),
    Age INT,
RollNo INT);

INSERT INTO student3(ID, Name, Age, RollNo) VALUES(1, 'gargi', 21, 21);
INSERT INTO student3(ID, Name, Age, RollNo) VALUES(2, 'milinda', 41, 41);
INSERT INTO student3(ID, Name, Age, RollNo) VALUES(3, 'folding bed', 21, 21);

DELETE FROM student3 WHERE `ID`=2;