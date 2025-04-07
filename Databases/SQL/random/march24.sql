-- Active: 1739339070113@@127.0.0.1@3306@DBMS_assignment
SHOW DATABASES;

USE DBMS_assignment;

DESC `students`;

SELECT * FROM `students`;

SELECT * FROM `students` ORDER BY Age asc;

SELECT  MAX(Age) FROM `students` WHERE `Age` > 20;

SELECT  COUNT(Age) FROM `students`;
SELECT  SUM(Age) FROM `students`;




