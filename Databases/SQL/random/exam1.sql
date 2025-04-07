-- Active: 1739339070113@@127.0.0.1@3306@XYZ

CREATE TABLE Students (
  Roll_No INT PRIMARY KEY,
  Student_Name VARCHAR(50),
  Student_ID INT,
  NoOfSub INT,
  Fee DECIMAL(10, 2),
  Date DATE,
  Branch VARCHAR(50),
  City VARCHAR(50)
);

INSERT INTO Students (Roll_No, Student_Name, Student_ID, NoOfSub, Fee, Date, Branch, City)
VALUES
(1, 'Alex Brown', 101, 5, 1000.00, '2023-01-01', 'CSE', 'Guwahati'),
(2, 'Bob Davis', 102, 4, 800.00, '2023-01-05', 'ECE', 'Guwahati'),
(3, 'Charlie Evans', 103, 5, 1200.00, '2023-01-10', 'CSE', 'Guwahati'),
(4, 'David Foster', 104, 4, 900.00, '2023-01-15', 'ECE', 'Guwahati'),
(5, 'Emily Garcia', 105, 5, 1100.00, '2023-01-20', 'CSE', 'Guwahati'),
(6, 'Frank Harris', 106, 4, 1000.00, '2023-01-25', 'ECE', 'Guwahati');


CREATE TABLE Customers (
  AC_No INT PRIMARY KEY,
  Customer_Name VARCHAR(50),
  Branch_Name VARCHAR(50),
  Address VARCHAR(100),
  City VARCHAR(50),
  Pin INT,
  State VARCHAR(50)
);

INSERT INTO Customers (AC_No, Customer_Name, Branch_Name, Address, City, Pin, State)
VALUES
(1, 'Amit Oberoi', 'Main Branch', '123 Main St', 'Guwahati', 781001, 'Assam'),
(2, 'Rahul Agarwal', 'City Branch', '456 City St', 'Guwahati', 781002, 'Assam'),
(3, 'Suresh Rao', 'Town Branch', '789 Town St', 'Shillong', 793001, 'Meghalaya'),
(4, 'Anita Arora', 'Village Branch', '901 Village St', 'Guwahati', 781003, 'Assam'),
(5, 'Rajesh Kumar', 'Rural Branch', '234 Rural St', 'Shillong', 793002, 'Meghalaya'),
(6, 'Priya Sharma', 'Urban Branch', '567 Urban St', 'Guwahati', 781004, 'Assam');



CREATE TABLE Courses (
  Course_ID INT PRIMARY KEY,
  Course_Name VARCHAR(50),
  Student_ID INT
);

INSERT INTO Courses (Course_ID, Course_Name, Student_ID)
VALUES
(1, 'Mathematics', 101),
(2, 'Science', 102),
(3, 'English', 103),
(4, 'History', 104),
(5, 'Geography', 105),
(6, 'Physics', 106);

SELECT * FROM `Customers` where `Customer_Name` LIKE "%a%" AND `Customer_Name` LIKE "%o%";

SELECT * FROM `Customers` where `` LIKE "%a%" AND `Customer_Name` LIKE "%o%";
