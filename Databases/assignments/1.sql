CREATE TABLE Employees (
  EmployeeID INT NOT NULL,
  Name VARCHAR(255) NOT NULL,
  Age INT,
  Country VARCHAR(255) DEFAULT 'USA'
);

INSERT INTO Employees (EmployeeID, Name, Age) VALUES (1, 'John Doe', 30);
INSERT INTO Employees (EmployeeID, Name, Age, Country) VALUES (2, 'Jane Doe', 25, 'Canada');
INSERT INTO Employees (EmployeeID, `Age`) VALUES (3, 20); -- This will throw an error because Age is not specified and has no default value.

SELECT * from `Employees`;


CREATE TABLE Students (
    student_id SERIAL PRIMARY KEY,  -- Auto-incrementing primary key
    name VARCHAR(100) NOT NULL,      -- NOT NULL constraint ensures a value must be provided
    age INT DEFAULT 18,              -- DEFAULT constraint sets a default value if none is given
    course VARCHAR(50) NOT NULL      -- Another NOT NULL constraint
);
INSERT INTO Students (name, age, course) VALUES (NULL, 20, 'Computer Science');
INSERT INTO Students (name, course) VALUES ('Alice', 'Mathematics');
SELECT * FROM `Students`;