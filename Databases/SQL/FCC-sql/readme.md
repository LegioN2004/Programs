# freeCodeCamp SQL Tutorial

We are using the table

| student_id | name   | major             | CGPA |
|------------|--------|-------------------|------|
| 1          | hi     | computer science  | 1.00 |
| 2          | hello  | CS2               | 1.00 |
| 3          | hello  | undeclared        | 2.00 |
| 4          | hello  | computer science  | 9.00 |
| 5          | gargu  | bio               | 9.00 |
| 6          | milu   | programming       | 8.00 |
| 7          | name7  | socilogy          | 5.00 |
| 8          | name8  | zoology           | 7.00 |

## Creating tables

Datatypes are as follows:

- `INT`: A whole number
- `DECIMAL(M,N)`: A decimal number;`M` total digits to store for this number and `N` is the number of digits to be stored after the decimal point. Exact value
- `VARCHAR(n)`: A string with a maximum length of `n` characters
- `BLOB`: A binary large object, stores large data
- `DATE`: A date in the format `YYYY-MM-DD`
- `BOOLEAN`: A boolean value, either `TRUE` or `FALSE` (or `1` or `0`)
- `JSON`: A JSON object (less efficient than `JSONB`)
- `JSONB`: A binary JSON object (more efficient than `JSON`)
- `UUID`: A unique identifier in the format `8-4-4-4-12`
- `TIMESTAMP`: A timestamp in the format `YYYY-MM-DD HH:MM:SS`
- `TIME`: A time

Constraints are as follows:

- `PRIMARY KEY`: A unique identifier for each row in a table
- `FOREIGN KEY`: A reference to a `PRIMARY KEY` in another table
- `UNIQUE`: A unique constraint
- `NOT NULL`: A column cannot have a `NULL` value
- `DEFAULT`: A default value for a column
- `AUTO_INCREMENT`: A column that increments automatically
- `ON DELETE CASCADE`: Deletes all rows in a table that have a `FOREIGN KEY` referencing a `PRIMARY KEY` in another table

Notes here and there:

- auto_increment is used to automatically increment the value of the field by 1 each time a new record is added
- primary key is used to uniquely identify each record in the table

## updating data

We now want to update data in places where the data matches, like to change the "biology" to "bio" `update fcc set major = 'bio' where major = 'biology';`. This will change all the rows where the major is "biology" to "bio".

You can also use OR to check multiple things at once. Like say you have bio and zoology and you want both to have biology, then you can do something like this `update fcc set major = 'biology' where major = 'bio' OR 'zoology';`

Or you can change the value of multiple attributes of one tuple with one attribute, `update fcc set name = 'tera baap', major='tur mur tu' where student_id=3 ;`, this changes the name to "tera baap" and major to "tur mur tu" where the student_id is 3.

- To change the name of the column, do this: `ALTER TABLE fcc RENAME COLUMN age to CGPA;`

## deleting data

We can use the process of updating to deleting as well and as such we can delete using the student_id or other attributes

So updating and deleting is very useful but can be dangerous if not used properly like you need to specify which tuple to delete using certain attributes or you might end up deleting everything.

## Basic queries

- `SELECT * FROM fcc;`: This will select all the rows and columns from the table fcc
- `SELECT name FROM fcc;`: This will select all the rows but only the name column
- `SELECT name, major FROM fcc;`: This will select all the rows but only the name and major columns
- `SELECT * FROM fcc WHERE major = 'computer science';`: This will select all the rows and columns from the table fcc where the major is computer science
- `SELECT * FROM fcc WHERE major = 'computer science' AND CGPA > 2;`: This will select all the rows and columns from the table fcc where the major is computer science and the CGPA is greater than 2
- You can write these table names in `SELECT table_name.column_name FROM table_name` this format as well so as to be more specific as to where the column name and values are coming from. eg: `SELECT fcc.name FROM fcc;`
- You can also order by name by doing `select fcc.name, fcc.major from fcc ORDER BY fcc.name;` this will order the rows by the name column in ascending order(alphabetical order to be precise for strings). You can also do `ORDER BY fcc.name DESC;` to order in descending order. By default it'll be in ascending order(alphabetical) if you don't specify.
  - you can add `desc` at the end to show it in descending order
  - you can add `asc` at the end to show it in ascending order

