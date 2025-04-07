-- Active: 1739339070113@@127.0.0.1@3306@BankDB
SELECT * FROM `BankDetails`;

INSERT INTO `BankDetails`(`Address`, `Age`, `Bank_Acc_No`, `Bank_Name`, `Name`, `Ph_No`) VALUES('123 Main St', 30, 12345, 'Bank of America', 'John Doe', 9876543210), ('456 Elm St', 25, 98765, 'Chase Bank', 'Jane Smith', 1234567890), ('789 Oak St', 40, 55555, 'Wells Fargo', 'Alice Johnson', 5555555555);

SELECT DISTINCT Bank_Name FROM BankDetails;
SELECT DISTINCT Name FROM BankDetails;
desc `BankDetails`;

update BankDetails SET Bank_Name="SBI" WHERE Bank_Acc_No=12345;

select * from `BankDetails` where NOT age = 30 OR `Bank_Name` = "SBI";
