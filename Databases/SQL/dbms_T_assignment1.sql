-- Active: 1739339070113@@127.0.0.1@3306@DBMS_assignment
CREATE DATABASE DBMS_assignment;

USE DBMS_assignment;

CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    age INT NOT NULL,
    email VARCHAR(100) UNIQUE
);

CREATE TABLE Courses (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(20) NOT NULL UNIQUE,
    credits INT NOT NULL,
    student_id INT,
    FOREIGN KEY (student_id) REFERENCES Students (student_id) ON DELETE CASCADE
);

INSERT INTO Students (student_id, Name, age, email) VALUES (1, 'Ram', 20, 'ram@gmail.com'), ( 2, 'Shyam', 21, 'shyam@gmail.com'), ( 3, 'Mohan', 22, 'mohan@gmail.com'), (4, 'raj', 30, 'raj@gmail.com');
INSERT INTO Courses (course_id, course_name, credits, student_id) VALUES(101, 'DBMS', 4, 1), (102, 'OS', 3, 1), (103, 'CN', 3, 2), (104, 'COA', 3, 4), (105, 'DSA', 3, 3);

UPDATE Courses SET credits=1 WHERE course_id=104;
DELETE FROM Students WHERE student_id=4;

SELECT * from `Students`;
SELECT * from `Courses`;

TRUNCATE TABLE `Students`;

CREATE TABLE Students2 (
    student_id INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    age INT NOT NULL,
    email VARCHAR(100) UNIQUE
);
INSERT INTO Students2 (student_id, Name, age, email) VALUES (1, 'Ram', 20, 'ram@gmail.com'), ( 2, 'Shyam', 21, 'shyam@gmail.com'), ( 3, 'Mohan', 22, 'mohan@gmail.com'), (4, 'raj', 30, 'raj@gmail.com');
SELECT * FROM `Students2`;
TRUNCATE TABLE `Students2`;