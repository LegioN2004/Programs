# All about SQL Databases

## **Types of databases**

> 💡 What all we’ll learn today - Simple - SQL vs NoSQL, how to create Postgres Databases, How to do CRUD on them Advance - Relationships, Joins, Transactions

### **There are a few types of databases, all service different types of use-cases**

### **NoSQL databases**

1. Store data in a `schema-less` fashion. Extremely lean and fast way to store data.
   - This is the reason why NoSQL databases are taught first since they are easy to learn at first.
2. Examples - MongoDB,

![image 1, MongoDB](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fc1750169-9a32-4b92-a424-13feba37211d%2Fs6_data_no_sidebar.png?table=block&id=fd5d37a7-88ae-40d3-8cdf-f97ca850d60b&cache=v2)

### **Graph databases**

1. Data is stored in the form of a graph. Specially useful in cases where `relationships` need to be stored, who is related to whom. (social networks)
2. Examples - Neo4j

![image 2, Neo4j](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fdeec5e2d-bb2c-4b5e-b8d8-ed26342cfec3%2FNeo4j-01.png?table=block&id=6a664c87-1fbd-49a2-88d6-af084e6f52b1&cache=v2)

### **Vector databases**

1. Stores data in the form of vectors
2. Useful in Machine learning
3. Examples - Pinecone

![Pinecone example image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F76957494-3415-46c1-a395-c633d0001872%2F64ff91994b8f87cabbd254cc_vector_database.webp?table=block&id=9baba7b4-64e7-48e1-874f-d225b9192112&cache=v2)

### **SQL databases**

1. Stores data in the form of rows
2. Most full stack applications will use this
3. Examples - MySQL, Postgres
4. We don't store a JSON here, it'll have a simple row and column like data table where we'll store the data.

![Postgres example image](<https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F48b213de-b3d3-4d6d-8cf4-f09afce3fb40%2Fdownload_(2).png?table=block&id=8fa33082-8b13-49ef-b7a7-e25e15937972&cache=v2>)

### Why not NoSQL

You might’ve used MongoDB
It’s schemaless properties make it ideal to for bootstraping a project fast. You have a hackathon project, you should use MongoDB
But as your app grows, this property makes it very easy for data to get corrupted

### **What is schemaless?**

Different rows can have different schema (keys/types), which is termed as corrupted data here i.e different sorts of data or maybe types in their respective places.
![pic](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F3f3641a6-337a-45bb-a9d0-2cf110b459be%2FScreenshot_2024-02-02_at_6.50.17_PM.png?table=block&id=c9ee2bbd-97d3-4dd1-aec0-fd7ffa75d8e9&cache=v2)

### **Problems?**

1. Can lead to inconsistent database.
2. Can cause runtime errors. You might expect a key to be present, but it’s not there kinda errors.
3. Is too flexible for an app that needs strictness.

### **Upsides?**

1. Can move very fast
2. Can change schema very easily

> 💡 You might think that `mongoose` does add strictness to the codebase because we used to define a schema there. That strictness is present at the Node.js level, not at the DB level. You can still put in erroneous data in the database that doesn’t follow that schema.

## **Why SQL?**

SQL databases have a strict schema. They require you to

1. Define your schema upfront.
   - you need to put in the data that follows the schema and updates the schema as your app changes.
2. Put in data that follows that schema
3. Update the schema as your app changes and perform `migrations`

So there are 4 parts when using an SQL database (not connecting it to Node.js, just running it and putting data in it)

1. Running the database.
2. Using a library that let’s you connect and put data in it.
3. Creating a table and defining it’s `schema`.
4. Run queries on the database to interact with the data (Insert/Update/Delete)

There can be questions like why not just use a **Zod** like library to have a strict backend so that the stuff that goes inside the DB is the correct one. But that still doesn't work since there will be mistakes and as such those mistakes will persist in the DB which is what we don't want to happen, that can be very dangerous and hence we use SQL databases(which will reject everything that doesn't follow the rules of the schema) as well as **Zod**.

## **Creating a database**

You can start a Potgres database in a few ways -

- Using neondb

  <https://neon.tech/> is a decent service that let’s you create a server.

  ![neonDB dashboard](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fb7ee7eea-328e-4b37-8481-0afb51676e7b%2FScreenshot_2024-02-02_at_9.45.53_PM.png?table=block&id=f089c2e4-7756-4532-a7df-ca4a482138ac&cache=v2)

  ![second pic of the dashboard](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F18fc29c5-b324-4e91-bdd0-549d4977561b%2FScreenshot_2024-02-02_at_9.46.01_PM.png?table=block&id=2d1bd758-fd33-4bef-95ae-47f826076991&cache=v2>)

**Normal Connection String**

`postgresql://username:password@ep-broken-frost-69135494.us-east-2.aws.neon.tech/calm-gobbler-41_db_2253874

- Using docker locally

  `docker run --name my-postgres -e POSTGRES_PASSWORD=mysecretpassword -d -p 5432:5432 postgres

  - **Connection String**

    `postgresql://postgres:mysecretpassword@localhost:5432/postgres?sslmode=disable

- Using docker on windows

  How to run postgrSQL in windows terminal(if you have docker installed).

  - fist run docker gui application that help in running commands in terminal.
  - After that run it with the docker instance by the help of following command .
    -- for the first time if the image is not downloaded .
    -- `docker run --name my-postgres1 -e POSTGRES_PASSWORD=mysecretpassword -d -p 5432:5432 postgres`.
    -- if the docker image is there, prior to use the it can simply be runned by `docker run <image name>`.
  - After that ,
    -- use `docker exec -it my-postgres1 psql -U postgres -d postgres` this command in terminal .
    -- then enter the password and it will connect to localhost Postgress instance .
    -- now you will be inside the postress command line that looks like `postgres-#` .
  - U can check it by running `\\dt` , (the command to display all the tables.)

> 💡 The connection string is similar to the string we had in mongoose.

### **Connection String**

![postgres string](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F879101b6-dd5e-4a36-86ba-36513d0c3274%2FScreenshot_2024-02-03_at_2.42.21_AM.png?table=block&id=f9978396-dba5-456e-9899-2c185b85c85d&cache=v2)

where does harkirat live ⇒ [1, 2, 2, 2, 3001, 100]

Harkirat lives in India ⇒ [1, 2, 2, 2, 2,2 ]

Harkirat is from chandigarh ⇒ [1, 2, 2, 2, 3]

Harkirat has been living in india, chandigarh ⇒ [1, 2, 2, 2, 2, 3]

The world is round ⇒ [1, 2, 10001, 1001, 001001]

Pacman is such a good game ⇒ [100, 10001, 20020, 1-001, 100]

## Using a library that let’s you connect and put data in it.\*\*

### **1. psql**

`psql` is a terminal-based front-end to PostgreSQL. It provides an interactive command-line interface to the PostgreSQL (or TimescaleDB) database. With psql, you can type in queries interactively, issue them to PostgreSQL, and see the query results.

### **How to connect to your database?**

psql Comes bundled with postgresql. You don’t need it for this tutorial. We will directly be communicating with the database from Node.js

`psql -h p-broken-frost-69135494.us-east-2.aws.neon.tech -d database1 -U 100xdevs

### **2. pg**

`pg` is a `Node.js` library that you can use in your backend app to store data in the Postgres DB (similar to `mongoose`). We will be installing this eventually in our app.

## **Creating a table and defining it’s schema.**

### **Tables in SQL**

A single database can have multiple tables inside. Think of them as collections in a MongoDB database.

- As per the image given below, it has a users table which will store all the users values, todos table for all the todos and the admins table for the admins.
- Based on our application we will setup more such tables

![image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F6fe44578-8e4f-4303-8034-f4621e533ad3%2FScreenshot_2024-02-03_at_1.37.51_PM.png?table=block&id=b9928b02-d188-42d4-832b-2b20c9a6f7fb&cache=v2)

![image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F1ce3660e-f87a-4d1d-b03e-b9c6728e868b%2FScreenshot_2024-02-03_at_12.14.18_AM.png?table=block&id=3e3adbb5-7d32-4d21-a52c-0a915b60fb42&cache=v2)

Until now, we have a database that we can interact with. The next step in case of postgres is to define the `schema` of your tables.

SQL stands for `Structured query language`. It is a language in which you can describe what/how you want to put data in the database.

To create a table, the command to run is -

```sql
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    created_at TIMESTAMP WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP
);
```

When we created that DB first in neon.tech we have that pink empty part which are to be filled with tables using the above command

- `SERIAL` is a postgres specific data type that auto increments the value of the column. It is similar to the \_id in MongoDB. It is the `PRIMARY KEY` of the table.
- `VARCHAR` is a variable character string data type that can store up to 50 characters for storing some characters i.e the username. It is used to limit the length of the username. Should be `UNIQUE` for every row and shouldn't be null `NOT NULL`.
- email is similar to username.
- password is similar to username but it can be non unique and `NOT NULL`.
- created_at is a timestamp with timezone that stores the time when the user was created. It has a default value of the current timestamp.

There are a few parts of this SQL statement, let’s decode them one by one

### **1. CREATE TABLE users**

**`CREATE TABLE users`**: This command initiates the creation of a new table in the database named **`users`**.

### **2. id SERIAL PRIMARY KEY**

- **`id`**: The name of the first column in the **`users`** table, typically used as a unique identifier for each row (user). Similar to `_id` in mongodb
- **`SERIAL`**: A PostgreSQL-specific data type for creating an auto-incrementing integer. Every time a new row is inserted, this value automatically increments, ensuring each user has a unique **`id`**. Just like the one we had with **mongoDB** that put random id for every new user.
- **`PRIMARY KEY`**: This constraint specifies that the **`id`** column is the primary key for the table, meaning it uniquely identifies each row. Values in this column must be unique and not null.
  - This is an SQL concept, i.e wherever you are creating a table this is a primary key for it.
  - A user with a single phone number/email will only be able to signup once. But the general rule is that the id must be a primary key since a user may want to change their email or phone number from time to time and setting them as primary keys will not allow them to do so.
  - Primary key can be a combination of multiple columns as well, like id and phone number. So we can have cases like username email couples can be present, like with email 1 having two usernames namely 1 and 2 can be present.

### **3. email VARCHAR(255) UNIQUE NOT NULL,**

- `email`: The name of the second column, intended to store the user's username.
- **`VARCHAR(50)`**: A variable character string data type that can store up to 50 characters. It's used here to limit the length of the username.
- **`UNIQUE`**: This constraint ensures that all values in the **`username`** column are unique across the table. No two users can have the same username.
- **`NOT NULL`**: This constraint prevents null values from being inserted into the **`username`** column. Every row must have a username value.

### **4. password VARCHAR(255) NOT NUL**

Same as above, can be non unique

### **5. created_at TIMESTAMP WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP**

- **`created_at`**: The name of the fifth column, intended to store the timestamp when the user was created.
- **`TIMESTAMP WITH TIME ZONE`**: This data type stores both a timestamp and a time zone, allowing for the precise tracking of when an event occurred, regardless of the user's or server's time zone.
- **`DEFAULT CURRENT_TIMESTAMP`**: This default value automatically sets the **`created_at`** column to the date and time at which the row is inserted into the table, using the current timestamp of the database server.

💡

If you have access to a database right now, try running this command to create a simple table in there

```sql
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    created_at TIMESTAMP WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP
);

-- Then try running inside psql shell
\dt
```

to see if the table has been created or not

## **Interacting with the database**

There are 4 things you’d like to do with a database, create, read, update and delete data. These are called `CRUD` operations, and this is one of the most common things that are done with a database.
The following things are needed to learn to interact with a SQL database, but when writing this code back in the day or to directly interact with the database, we need to learn these commands. But nowadays due to abstraction libraries and ORMs we don't need to learn these commands.

### **1. INSERT**

```sql
INSERT INTO users (username, email, password)
VALUES ('username_here', 'user@example.com', 'user_password');
```

- Which means insert data to users table, with the username, email and password as the values, which are given in the values section.
- Note that it can be in any manner(talking in the context of the tables) but the order of the values should be the same as the order of the columns in the table, but you don't necessarily need to add everything in the table serially while querying.

> 💡 Notice how you didn’t have to specify the `id` because it auto increments

### **2. UPDATE**

```sql
UPDATE users
SET password = 'new_password'
WHERE email = 'user@example.com';
```

### **3. DELETE**

```sql
DELETE FROM users
WHERE id = 1;
```

- This will delete the user with the id 1. But you don't really delete users in a real app. Whenever someone says to delete something which is called _is hidden_, you don't delete them but mark them as _hidden_ for auditability purposes.

### **4. Select**

```sql
SELECT * FROM users
WHERE id = 1;
```

This is enough for creating a simple application like todo. You can now create a table, insert data into it, update it, delete it and read it.

## **How to do queries from a Node.js app?**

In the end, postgres exposes a protocol that someone needs to talk to be able to send these commands (update, delete) to the database.
`psql` is one such library that takes commands from your terminal and sends it over to the database.
To do the same in a Node.js , you can use one of many `Postgres clients`

### **pg library**

<https://www.npmjs.com/package/pg>

Non-blocking PostgreSQL client for Node.js.

Documentation - <https://node-postgres.com/>

Connecting -

```sql
import { Client } from 'pg'

const client = new Client({
  host: 'my.database-server.com',
  port: 5334,
  database: 'database-name',
  user: 'database-user',
  password: 'secretpassword!!',
})

client.connect()Copy
```

Querying -

```sql
const result = await client.query('SELECT * FROM USERS;')
console.log(result)Copy

// write a function to create a users table in your database.
import { Client } from 'pg'

const client = new Client({
  connectionString: "postgresql://postgres:mysecretpassword@localhost/postgres"
})

async function createUsersTable() {
    await client.connect()
    const result = await client.query(`
        CREATE TABLE users (
            id SERIAL PRIMARY KEY,
            username VARCHAR(50) UNIQUE NOT NULL,
            email VARCHAR(255) UNIQUE NOT NULL,
            password VARCHAR(255) NOT NULL,
            created_at TIMESTAMP WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP
        `);
    )
    console.log(result)
}

createUsersTable();
```

Adding new users to the table -

```ts
// insert data to users table
async function insertDataToUsers() {
  await client.connect();
  try {
    const Query = `INSERT INTO users (username, email, password) VALUES ('hello', 'hello@gmail.com', 'passwordTurMurTu')`;
    const res = await client.query(Query);
    console.log("Insertion success", res);
  } catch (error) {
    console.log("some error happened", error);
  } finally {
    await client.end();
  }
}

insertDataToUsers();
```

Things to note here:

- You need to await on client.connect() because it takes some time to connect to the PG DB and then send the various queries.
- You need to use single quotes for the values in the query, since it’s a string(more on that on the end of this doc with gpt notes).
- You will get proper success messages when you run the query successfully and error messages when you don’t(at the end of this page).

## **Creating a simple Node.js app**

1. Initialise an empty typescript project

```shell
npm init -y
npx tsc --initCopy`
```

2. Change the `rootDir` and `outDir` in `tsconfig.json`

```shell
`"rootDir": "./src",
"outDir": "./dist",Copy`
```

3. Install the `pg` library and it’s types (because we’re using TS)

```shell
npm install pg
npm install @types/pgCopy`
```

4. Create a simple Node.js app that lets you put data

Create a function that let’s you insert data into a table. Make it `async`, make sure `client.connect` resolves before u do the insert

- Answer

```ts
import { Client } from "pg";

// Async function to insert data into a table
async function insertData() {
  const client = new Client({
    host: "localhost",
    port: 5432,
    database: "postgres",
    user: "postgres",
    password: "mysecretpassword",
  });

  try {
    await client.connect(); // Ensure client connection is established
    const insertQuery =
      "INSERT INTO users (username, email, password) VALUES ('username2', 'user3@example.com', 'user_password');";
    const res = await client.query(insertQuery);
    console.log("Insertion success:", res); // Output insertion result
  } catch (err) {
    console.error("Error during the insertion:", err);
  } finally {
    await client.end(); // Close the client connection
  }
}

insertData();
```

> 💡 This is an `insecure` way to store data in your tables. When you expose this functionality eventually via `HTTP`, someone can do an `SQL INJECTION` to get access to your data/delete your data.

Why this is insecure: **SQL Injection**

- What we are doing and we'll be eventually doing here is that we'll be creating an express server with a SQL DB and it will be taking direct inputs from the user and as such sending them to the DB. This is a very bad practice since the user can send in malicious code instead of data(such as sql queries for doing things that you don't want) and as such can do things that you don't want in the whole database. This is called `SQL Injection`.
- This is a very common attack done to the SQL databases and so this must be prevented at all costs.
- What we shouldn't do is to put the user provided fields directly into the SQL string.

1. More secure way to store data.
   Update the code so you don’t put `user provided fields` in the `SQL string`

- What are user provided strings?
  - In your final app, this insert statement will be done when a user signs up on your app. Email, username, password are all user provided strings
- What is the SQL string ?
  `const insertQuery = "INSERT INTO users (username, email, password) VALUES ('username2', 'user3@example.com', 'user_password');";`

  - Hint

  ```ts
  const insertQuery =
    "INSERT INTO example_table(column1, column2) VALUES($1, $2)";
  const res = await client.query(insertQuery, [column1Value, column2Value]);
  ```

- Solution

```ts
  try {
    await client.connect(); // Ensure client connection is established
    // Use parameterized query to prevent SQL injection
    const insertQuery = "INSERT INTO users (username, email, password) VALUES ($1, $2, $3)";
    // instead of
    // const insertQuery = "INSERT INTO users (username, email, password) VALUES ('username2', 'user3@example.com', 'user_password');";
    const values = [username, email, password];
    const res = await client.query(insertQuery, values);
    console.log('Insertion success:', res); // Output insertion result
  } catch (err) {
    console.error('Error during the insertion:', err);
  } finally {
    await client.end(); // Close the client connection
  }
}

// Example usage
insertData('username5', 'user5@example.com', 'user_password').catch(console.error);
```

How the above is secure:

- The format remains the same but the values part is being set as `($1, $2, $3)` instead of directly giving the values(which prevents SQL injection).
  - Why this works: By giving the values using the $ sign instead of directly giving the values, the DB knows that those are values and they should be treated like that. And then the values should be given in the array format in the `client.query` function. This is called **parameterized query** and is a very common way to prevent SQL injection.
  - Since user provided fields are not directly put into the SQL string so the user can't put in malicious code in the SQL string and as such can't do SQL injection.
    - Common thing to try in an input field using SQL injection is to put in `;DELETE * FROM USERS;` in the input field and you can delete the data in the database if that matches this table name. Why this happens: On seeing the semicolon, SQL thinks that the query has ended and a new query has started and as such it runs the next query which is the delete query. But using $1, $2, $3, this can't be done, it will just store that string in the database.

1. Query data
   Write a function `getUser` that lets you fetch data from the database given a `email` as input. It's gets a little different in the query

```ts
  try {
    await client.connect(); // Ensure client connection is established
    const query = 'SELECT * FROM users WHERE email = $1';
    const values = [email];
    const result = await client.query(query, values);
  // const result = await client.query(query, [email]); // can also give like, and using $1 it expects the first value so it'll pick up the first value from the array.

    if (result.rows.length > 0) {
      console.log('User found:', result.rows[0]); // Output user data
      return result.rows[0]; // Return the user data
    } else {
      console.log('No user found with the given email.');
      return null; // Return null if no user was found
    }
  } catch (err) {
    console.error('Error during fetching user:', err);
    throw err; // Rethrow or handle error appropriately
  } finally {
    await client.end(); // Close the client connection
  }
}

// Example usage
getUser('<user5@example.com>').catch(console.error);`
```

## **Relationships and Transactions**

Relationships let you store data in different tables and `relate` it with each other.

### **Relationships in Mongodb**

We are using the example of a user having different details as the data such as name, email, password and address which contain sub-details like street, city, country and pincode. So there are different ways in which this can be done in mongoDB and in SQL DB.

Since `mongodb` is a NoSQL database, you can store any shape of data in it, since it stores data in a JSON-like format called BSON (Binary JSON). Each document in a MongoDB collection has a flexible schema, meaning documents in the same collection can have different fields .
If I ask you to store a users details along with their address, you can store it in an object that has the address details.

![mongDB img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Ffd33f71f-ac54-432e-9afc-321758d50b04%2FScreenshot_2024-02-03_at_1.24.12_AM.png?table=block&id=ededf670-2336-4101-b701-c384e35f7447&cache=v2)

### **Relationships in SQL**

Since SQL can not store `objects` as such, we need to define two different tables to store this data of users and address in by relating them somehow and this is termed as relationships. This is not the only way but the most popular and right way to store schema like this in the users table. So it can be one in the following manner.

Why can't we merge the users table and the address, well a user can have 2 adresses so edge cases like these won't let you do that. You can store the address in a different table and relate it to the user.

For that very reason we bring them down to two different tables and then relate them. How does that work

- We ofcourse have more than one tables to relate them, so we have the users table and the address table.
- Then we have the `user-id` in the address table which is the same as the id in the users table. This is called a `foreign key` which is a key in one table that is a primary key in another table. So any entry in the `user_id` column of the address table is a foreign key
  - What this does is that the address table should only allow an entry only if a user exists i.e there must be an user with that id in the users table(which comes with the foreign key).
  - This `user_id` table will have atleast one user in the users table with the smae id.

![relationships img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F1646f1fe-2d70-4df1-9de1-b619b28bf3a7%2FScreenshot_2024-02-03_at_1.30.10_AM.png?table=block&id=4af3b6ab-44fe-4ca4-8f04-c3d063592e11&cache=v2)

This is called a `relationship` , which means that the `Address` table is related to the `Users` table.

When defining the table, you need to define the `relationship`

```sql
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    created_at TIMESTAMP WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP
);
```

```sql
CREATE TABLE addresses (
    id SERIAL PRIMARY KEY,
    user_id INTEGER NOT NULL,
    city VARCHAR(100) NOT NULL,
    country VARCHAR(100) NOT NULL,
    street VARCHAR(255) NOT NULL,
    pincode VARCHAR(20),
    created_at TIMESTAMP WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
);
```

Explanation:

- The others are the same as before
- `FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE`
  - The `FOREIGN KEY` constraint ensures that the `user_id` column in the `addresses` table references the `id` column in the `users` table. This means that the `user_id` in the `addresses` table must exist in the `id` column of the `users` table.
  - But the `ON DELETE CASCADE` is new. This means that if a user is deleted, all the addresses of that user should probably be also deleted. This is called a `cascade delete`.

### **SQL query**

To insert the address of a user -

```sql
INSERT INTO addresses (user_id, city, country, street, pincode)
VALUES (1, 'New York', 'USA', '123 Broadway St', '10001');
```

Now if you want to get the address of a user given an `id` , you can run the following query -

```sql
SELECT city, country, street, pincode
FROM addresses
WHERE user_id = 1;
```

### **Extra - Transactions in SQL**

> 💡 Good question to have at this point is what queries are run when the user signs up and sends both their information and their address in a single request. Do we send two SQL queries into the database? What if one of the queries (address query for example) fails? This would require `transactions` in SQL to ensure either both the user information and address goes in, or neither does

- SQL Query

  ```sql
    BEGIN; -- Start transaction

    INSERT INTO users (username, email, password)
    VALUES ('john_doe', '<john_doe1@example.com>', 'securepassword123');

    INSERT INTO addresses (user_id, city, country, street, pincode)
    VALUES (currval('users_id_seq'), 'New York', 'USA', '123 Broadway St', '10001');

    COMMIT;
  ```

- Node.js Code

  ```ts
  import { Client } from "pg";

  async function insertUserAndAddress(
    username: string,
    email: string,
    password: string,
    city: string,
    country: string,
    street: string,
    pincode: string,
  ) {
    const client = new Client({
      host: "localhost",
      port: 5432,
      database: "postgres",
      user: "postgres",
      password: "mysecretpassword",
    });

    try {
      await client.connect();

      // Start transaction
      await client.query("BEGIN");

      // Insert user
      const insertUserText = `
                INSERT INTO users (username, email, password)
                VALUES ($1, $2, $3)
                RETURNING id;
            `;
      const userRes = await client.query(insertUserText, [
        username,
        email,
        password,
      ]);
      const userId = userRes.rows[0].id;

      // Insert address using the returned user ID
      const insertAddressText = `
                INSERT INTO addresses (user_id, city, country, street, pincode)
                VALUES ($1, $2, $3, $4, $5);
            `;
      await client.query(insertAddressText, [
        userId,
        city,
        country,
        street,
        pincode,
      ]);

      // Commit transaction
      await client.query("COMMIT");

      console.log("User and address inserted successfully");
    } catch (err) {
      await client.query("ROLLBACK"); // Roll back the transaction on error
      console.error("Error during transaction, rolled back.", err);
      throw err;
    } finally {
      await client.end(); // Close the client connection
    }
  }

  // Example usage
  insertUserAndAddress(
    "johndoe",
    "john.doe@example.com",
    "securepassword123",
    "New York",
    "USA",
    "123 Broadway St",
    "10001",
  );
  ```

## **Joins**

Defining relationships is easy.

What’s hard is `joining` data from two (or more) tables together. Like give users details and their addresses or in a todo application, which has a name and all the todos the query might be that give me the users' information and all their todos. And that can be done using `joins`.

For example, if I ask you to fetch me a users details `and` their address, what SQL would you run?

- Approach 1 (Bad):

  - how this happens: Firstly get the user's details and then get the address of the user using the user's id. Secondly, get the user's address using the user's id.

  ```sql
  -- Query 1: Fetch user's details and addresses
  SELECT id, username, email
  FROM users
  WHERE id = YOUR_USER_ID;
  -- Query 2: Fetch user's address
  SELECT city, country, street, pincode
  FROM addresses
  WHERE user_id = YOUR_USER_ID;
  ```

- Approach 2 (using joins)

  - The benefit: We can combine the two above queries into one and get the user's details and address(basically to get data from two tables) in a single query. This is how joining lets you grab data for related tables.

  ```sql
  -- without using aliases
    SELECT users.id, users.username, users.email, addresses.city, addresses.country, addresses.street, addresses.pincode
    FROM users
    JOIN addresses ON users.id = addresses.user_id
    WHERE users.id = '1';
  ```

  ```sql
  -- by using aliases
    SELECT u.id, u.username, u.email, a.city, a.country, a.street, a.pincode
    FROM users u
    JOIN addresses a ON u.id = a.user_id
    WHERE u.id = YOUR_USER_ID;
  ```

Now try converting the same to your node app

- Approach 1 (Bad)

  ```ts
        try {
            await client.connect();

            // Fetch user details
            const userDetailsQuery = 'SELECT id, username, email FROM users WHERE id = $1';
            const userDetails = await client.query(userDetailsQuery, [userId]);

            // Fetch user address
            const userAddressQuery = 'SELECT city, country, street, pincode FROM addresses WHERE user_id = $1';
            const userAddress = await client.query(userAddressQuery, [userId]);

            if (userDetails.rows.length > 0) {
                console.log('User found:', userDetails.rows[0]);
                console.log('Address:', userAddress.rows.length > 0 ? userAddress.rows[0] : 'No address found');
                return { user: userDetails.rows[0], address: userAddress.rows.length > 0 ? userAddress.rows[0] : null };
            } else {
                console.log('No user found with the given ID.');
                return null;
            }
        } catch (err) {
            console.error('Error during fetching user and address:', err);
            throw err;
        } finally {
            await client.end();
        }
    }
    getUserDetailsAndAddressSeparately("1");
  ```

- Approach 2 (using joins)

  ```ts
        try {
            await client.connect();
            const query = `
                SELECT u.id, u.username, u.email, a.city, a.country, a.street, a.pincode
                FROM users u
                JOIN addresses a ON u.id = a.user_id
                WHERE u.id = $1
            `;
            const result = await client.query(query, [userId]);

            if (result.rows.length > 0) {
                console.log('User and address found:', result.rows[0]);
                return result.rows[0];
            } else {
                console.log('No user or address found with the given ID.');
                return null;
            }
        } catch (err) {
            console.error('Error during fetching user and address:', err);
            throw err;
        } finally {
            await client.end();
        }
    }
    getUserDetailsWithAddress("1");
  ```

**Benefits of using a join -**

1. **Reduced Latency**
2. Simplified Application Logic
3. **Transactional Integrity**

**What happens if you don't use joins?**
We'll have a node app that will send queries to the SQL DB table. Firstly it'll get one query and after it finishes then we'll send another which will be the normal course of action. Two separate get queries.

- First issue is latency: If you run two queries, you need to wait for the first query to finish before you can run the second query. This can be slow if the queries are slow.
- Second issue is that you need to write more code to handle the two queries. You need to handle the result of the first query and then use that result to run the second query. This can be complex and error-prone.
- Third issue is transactional integrity: If the first query request succeeds but the second query fails or the data changes before the second request, then you'll need to handle this situation. for that reason it always makes sense to send a single joined query rather then sending two separate queries. You only do it for data that is related to each other.

### **Types of Joins**

**1. INNER JOIN**

Returns rows when there is at least one match in both tables. If there is no match, the rows are not returned. It's the most common type of join.

**Use Case: Find All Users With Their Addresses. If a user hasn’t filled their address, that user shouldn’t be returned**

```sql
SELECT users.username, addresses.city, addresses.country, addresses.street, addresses.pincode
FROM users
INNER JOIN addresses ON users.id = addresses.user_id;
```

**2. LEFT JOIN**

Returns all rows from the left table, and the matched rows from the right table.

Use case - To list all users from your database along with their address information (if they've provided it), you'd use a LEFT JOIN. Users without an address will still appear in your query result, but the address fields will be NULL for them.

```sql
SELECT users.username, addresses.city, addresses.country, addresses.street, addresses.pincode
FROM users
LEFT JOIN addresses ON users.id = addresses.user_id;
```

**3. RIGHT JOIN**

Returns all rows from the right table, and the matched rows from the left table.

Use case - Given the structure of the database, a RIGHT JOIN would be less common since the **`addresses`** table is unlikely to have entries not linked to a user due to the foreign key constraint. However, if you had a situation where you start with the **`addresses`** table and optionally include user information, this would be the theoretical use case.

```sql
SELECT users.username, addresses.city, addresses.country, addresses.street, addresses.pincode
FROM users
RIGHT JOIN addresses ON users.id = addresses.user_id;
```

**4. FULL JOIN**

Returns rows when there is a match in one of the tables. It effectively combines the results of both LEFT JOIN and RIGHT JOIN.

Use case - A FULL JOIN would combine all records from both **`users`** and **`addresses`**, showing the relationship where it exists. Given the constraints, this might not be as relevant because every address should be linked to a user, but if there were somehow orphaned records on either side, this query would reveal them.

```sql
SELECT users.username, addresses.city, addresses.country, addresses.street, addresses.pincode
FROM users
FULL JOIN addresses ON users.id = addresses.user_id;
```

## GPT NOTES dump

### why you can't use double quotes in SQL queries for strings?

Based on the search results, it is generally not recommended to use double quotes to enclose string values in SQL statements. Here's why:

- In SQL, single quotes (`'`) are used to enclose string literals, while double quotes (`"`) are typically used for delimited identifiers like table or column names.

- Using double quotes to enclose string values can cause syntax errors or unexpected behavior. For example, in Oracle, using double quotes results in an "ORA-00923: FROM keyword not found where expected" error[2].

- To include a single quote within a string, you need to escape it by using two consecutive single quotes (`''`). For example: `INSERT INTO table (column) VALUES ('It''s a string');`

- If you need to include double quotes within a string, you can use the `CONCAT()` function or string concatenation to build the string. For example: `INSERT INTO table (column) VALUES (CONCAT('The word "', word, '" is important.'));`

So in summary, while your code may work with single quotes, it's considered a best practice to always use single quotes to enclose string literals in SQL statements. Using double quotes for this purpose is not recommended and may cause issues with certain databases or SQL dialects.

you will have error messages which look like this

```shell
some error happened error: column "hello" does not exist
    at C:\Users\User\ghq\github.com\LegioN2004\Programs\WebDev-stuff\Kirat-cohort-0-1\10.1-Postgres\postgres1-app\node_modules\pg\lib\client.js:526:17
    at process.processTicksAndRejections (node:internal/process/task_queues:95:5) {
  length: 105,
  severity: 'ERROR',
  code: '42703',
  detail: undefined,
  hint: undefined,
  position: '55',
  internalPosition: undefined,
  internalQuery: undefined,
  where: undefined,
  schema: undefined,
  table: undefined,
  column: undefined,
  dataType: undefined,
  constraint: undefined,
  file: 'parse_relation.c',
  line: '3665',
  routine: 'errorMissingColumn'
}
```

and success messages which look like this

```shell
Insertion success Result {
  command: 'INSERT',
  rowCount: 1,
  oid: 0,
  rows: [],
  fields: [],
  _parsers: undefined,
  _types: TypeOverrides {
    _types: {
      getTypeParser: [Function: getTypeParser],
      setTypeParser: [Function: setTypeParser],
      arrayParser: [Object],
      builtins: [Object]
    },
    text: {},
    binary: {}
  },
  RowCtor: null,
  rowAsArray: false,
  _prebuiltEmptyResultObject: null
}
```

### All about 'u' for users and 'a' for addresses in the SQL query and their usage

In SQL, the order of the clauses in a query is important and follows a specific sequence. The FROM clause, where the aliases are defined, is processed before the SELECT clause, where the aliases are used.

#### SQL Query Order of Execution

1. **FROM clause**: This is where the tables are listed and any table aliases are defined.
2. **JOIN clause**: This is processed after the FROM clause and uses the table aliases defined in the FROM clause.
3. **WHERE clause**: This filters the rows based on the conditions.
4. **SELECT clause**: This specifies the columns to be returned and can use the table aliases defined in the FROM clause.

Let's break down the process for your query:

```sql
SELECT u.id, u.username, u.email, a.city, a.country, a.street, a.pincode
FROM users u
JOIN addresses a ON u.id = a.user_id
WHERE u.id = YOUR_USER_ID; -- Replace YOUR_USER_ID with the actual user ID
```

1. **FROM users u**:

   - The `users` table is specified, and the alias `u` is defined for it.

2. **JOIN addresses a ON u.id = a.user_id**:

   - The `addresses` table is specified, and the alias `a` is defined for it.
   - The join condition `u.id = a.user_id` uses the alias `u` to refer to the `users` table and `a` to refer to the `addresses` table.
   - till here is the join clause

3. **WHERE u.id = YOUR_USER_ID**:

   - The `WHERE` clause filters the results using the alias `u` to refer to the `id` column from the `users` table.
   - if u.id is not defined then it'll apply the join clause on the all of the users on the table

4. **SELECT u.id, u.username, u.email, a.city, a.country, a.street, a.pincode**:
   - The `SELECT` clause uses the aliases `u` and `a` to specify the columns to be returned in the result set.

#### Example Query Execution

Let's look at a more detailed example to illustrate this:

```sql
SELECT u.id, u.username, u.email, a.city, a.country, a.street, a.pincode
FROM users u
JOIN addresses a ON u.id = a.user_id
WHERE u.id = 1; -- Replace YOUR_USER_ID with the actual user ID
```

- **Step 1**: Process the `FROM` clause:

  ```sql
  FROM users u
  ```

  - The `users` table is referenced and aliased as `u`.

- **Step 2**: Process the `JOIN` clause:

  ```sql
  JOIN addresses a ON u.id = a.user_id
  ```

  - The `addresses` table is referenced and aliased as `a`.
  - The join condition `u.id = a.user_id` is evaluated using the aliases.
  - till here is the join clause

- **Step 3**: Process the `WHERE` clause:

  ```sql
  WHERE u.id = 1
  ```

  - The `WHERE` clause filters the results to only include rows where `u.id` (which refers to `users.id`) is `1`.
  - If not mentioned then it'll apply the join clause on all the users in the table.

- **Step 4**: Process the `SELECT` clause:

  ```sql
  SELECT u.id, u.username, u.email, a.city, a.country, a.street, a.pincode
  ```

  - The `SELECT` clause specifies the columns to be returned, using the aliases `u` and `a` to refer to the `users` and `addresses` tables, respectively.
