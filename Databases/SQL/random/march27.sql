-- Active: 1739339070113@@127.0.0.1@3306@DBMS_assignment
USE  DBMS_assignment;

select * from bank;

select * from bank where `Customer_Name` LIKE "_r%";
select * from bank where `Customer_Name` LIKE "_r%";
select * from bank where `Customer_Name` LIKE "a__%";

select * from bank where `Customer_Name` LIKE "a%o";

select * from bank where `Customer_Name` NOT in('Arifo', 'Aruto');

select * from bank where `Bank_Ac_No` NOT BETWEEN 101 AND 105;

select Bank_Ac_No as ID from bank;


SELECT * from bank;

SELECT * FROM bank where `Customer_Name` LIKE "%a%" AND `Customer_Name` LIKE "%o%";

select * from bank where `Bank_Ac_No` BETWEEN 101 AND 106 AND `Bank_Ac_No` != 103;

select * from bank where `City` IN("Dibrugarh","Tinsukia");

SELECT * FROM bank where `Customer_Name` LIKE "%A_____"

SELECT * FROM bank where `Customer_Name` LIKE "%arh"

select Customer_Name from bank where `Customer_Name` LIKE "A%o" AND LENGTH(`Customer_Name`)>=3;

select SUM(Bank_Ac_No) FROM bank;

select * from bank limit 3 offset 1;