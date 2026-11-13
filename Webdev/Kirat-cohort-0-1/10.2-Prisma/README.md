# ORMs: Prisma

### **What are ORMs**

1. Boring official defination**ORM stands for Object-Relational Mapping, a programming technique used in software development to convert data between incompatible type systems in object-oriented programming languages. This technique creates a "virtual object database" that can be used from within the programming language.ORMs are used to abstract the complexities of the underlying database into simpler, more easily managed objects within the code
    - It just makes you life easier by making basic function calls to talk to the DB be it CRUD operations, etc. They are available for most of the popular languages like Python, Java, Ruby, etc, but the one we are going to talk about is for Node.js.

**2. Easier to digest defination**: ORMs let you easily interact with your database without worrying too much about the underlying syntax (SQL language for eg)
    - Why, It is good to know SQL, but it is more useful as a data analyst where they'll have to make a lot of queries in it. But as a software developer it is not much useful and so ORMs abstract away the complexities of SQL and let you interact with the database using the programming language itself.

## **Why ORMs?**

### **1. Simpler syntax (converts objects to SQL queries under the hood)**

![syntax img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F1250f16a-848b-4c9e-ab69-1e6fbf1ecaa7%2FScreenshot_2024-02-03_at_5.46.30_PM.png?table=block&id=a139f0de-82b5-47d5-abe8-95aab5e9c074&cache=v2)

Here we can see that the non-ORM way of doing things is you will need to know the SQL. The ORM way is much more concise and easier to understand since you will need to only use the language to do stuff(similar to mongoose).
The ORM thing gets converted to SQL but we don't need to worry because that's why it is there for.

### **2. Abstraction that lets you flip the database you are using. Unified API irrespective of the DB**

![second img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F37237d9a-1ce5-4faa-a41c-25ab6199d173%2FScreenshot_2024-02-03_at_6.01.27_PM.png?table=block&id=fac0618a-6581-4352-95a8-ae2b78edcf53&cache=v2)

Prisma is not specific for PostgresDB, we can use it for any database but the syntax will be the same. So if you want to switch to another database(shouldn't do that in the midst of using one database, after deciding only or after finishing then moving to another), you will have to do some minor changes when going from SQL to NoSQL or vice versa but the application logic never changes. And as such it is very powerful.

### **3. Type safety/Auto completion**

![type image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F30d3aa28-f385-49fb-9b25-1ee247dc3612%2FScreenshot_2024-02-03_at_6.12.36_PM.png?table=block&id=79651703-6d4b-42bd-9363-4f534d731d7b&cache=v2)

- We have just been intro'ed to TS and we know how powerful it is. Prisma is built on top of TS and so it is very powerful. It gives us type safety and auto-completion. So if you are using Prisma, you will get all the benefits of TS.
- By looking into the left side code we are using any type and it is not a good practice we know why, so we need to have types associated with it when we are trying to use certain things. So Prisma will give us that.
- Prisma also gives auto-completion which is very useful. It will give you all the suggestions and you can just select from them.

### **4. Automatic migrations**

In case of a simple Postgres app, it’s very hard to keep track of all the commands that were ran that led to the current schema of the table.

In the following example, we have a table `users` table. So initially we'll have a users table which is a simple application where people come and sign up. Then let's say we want to convert it to a todo application, so we'll like to add support so add columns `todos`, after that we'll need to add the phone number as well so we'll add `phone_number` column, etcccc. This schema keeps changing so we'll have to keep track of all these commands that were run to get to the current schema of the table.

![migration](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F50a8ab5a-364d-4375-9ea8-64d347d9515f%2FScreenshot_2024-02-03_at_7.01.25_PM.png?table=block&id=e4ade148-bcf9-46f9-bd65-df5008e09dcb&cache=v2)

```sql
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100) UNIQUE NOT NULL
);

ALTER TABLE users
ADD COLUMN phone_number VARCHAR(15)
```

As your app grows, you will have a lot of these `CREATE` and `ALTER`  commands. But after adding to production, i.e to a new database how'll we remember, where to store this information, how will we migrate to a new DB, etc, this is called "Migration". This is a very long file or multiple files where we store that this specific schema was reached by running these commands. And we won't need to worry about the data.

ORMs (or more specifically Prisma) maintains all of these for you. So it'll give you a centralized place to store all of this, what has changed, what happened, etc and as such we'll not have to worry about those anymore.

For example - <https://github.com/code100x/cms/tree/main/prisma/migrations>

## **What is Prisma**

![prisma image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F87d6586b-8eb0-4149-91df-b664dbe786e5%2FScreenshot_2024-02-03_at_6.20.14_PM.png?table=block&id=02e58595-53b2-454c-b7c5-0cb0faa5e5d7&cache=v2)

Let's breakdown the image above about what they have said:

### **1. Data model**

In a single file, define your schema. What it looks like, what tables you have, what field each table has, how are rows related to each other.

We don't have to write any of the above, any SQL commands, etc. We just have to give a single file called `schema.prisma` which will have the schema(eg: the todos table or any other table, and that's all the dev has to write) and Prisma will take care of the rest. This is what they mean by "intuitive data model".

### **2. Automated migrations**

Prisma generates and runs database migrations based on changes to the Prisma schema. Written about in the above lines. What it does is that it'll auto generate the migrations(other changes be it deletion or updation, that has been done) for you and run them as well. So you don't have to worry about the migrations.

Migration is a new word, it means that let's say we have a full stack application and we create a backend for it, DB in AWS. We started the DB and is about to deploy the application but before deploying we will have to make sure that the DB has the new schema. This is called a migration, that these are the commands you need to run to get the current schema of the application and if in future AWS goes done and we need to change, we'll need to run the same migrations again in the new place. Prism will take care of all of this.

### **3. Type Safety**

Prisma generates a type-safe database client based on the Prisma schema.

![type safe image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F00202edc-fdad-4a09-85d4-0f525aaf7815%2FScreenshot_2024-02-03_at_6.05.30_PM.png?table=block&id=42017b46-d44d-48e5-86a8-02109f1e6b56&cache=v2)

### **4. Auto-Completion**

![auto complete image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F41a55d69-4e66-49fd-bf0b-ac8f7e1fc7cd%2FScreenshot_2024-02-03_at_6.23.46_PM.png?table=block&id=608e8627-5c66-427f-bb9d-7d3c4abdbd94&cache=v2)

## Created a new typescript project and then more code

Let’s create a simple TODO app

1. Initialize an empty Node.js project

```bash
npm init -y
```

1. Add dependencies

```bash
npm install prisma typescript ts-node @types/node --save-dev
```

1. Initialize typescript

```bash
npx tsc --init
```

Change`rootDit` to `src`
Change `outDir` to `dist`

1. Initialize a fresh prisma project

```bash
npx prisma init
```

![image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fbe79252e-dbb5-4334-a6cb-e3bc33575051%2FScreenshot_2024-02-03_at_6.45.49_PM.png?table=block&id=50594c3f-0b66-45fc-9771-003519eed81a&cache=v2)

## **Step 5 - Selecting your database**

Prisma lets you chose between a few databases (MySQL, Postgres, Mongo). You can update `prisma/schema.prisma`  to setup what database you want to use. Just change the `provider` field to the database you want to use.

💡 Also replace the database url with your test url for now

![schema.prisma image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fc1d48f7a-8622-464b-82bf-a8a6bcd3e3ec%2FScreenshot_2024-02-03_at_6.49.12_PM.png?table=block&id=671ee58a-983e-4953-ac34-9c72a6f95e19&cache=v2)

💡 Good to have the VSCode extension that lets you visualise prisma better

![extension image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fbc4196f6-3db8-4dcf-820f-12733d67bf1d%2FScreenshot_2024-02-03_at_6.47.55_PM.png?table=block&id=e1f08251-12b8-4b1c-832c-f64f01e8c1f2&cache=v2)

## **Defining your data model**

**Prisma expects you to define the shape of your data in the `schema.prisma` file**

![image1](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fc2792e40-ef85-4b93-9b95-a1f517ed02d6%2FScreenshot_2024-02-03_at_6.58.23_PM.png?table=block&id=383be376-56d9-4e3b-a8c6-18fe13189a79&cache=v2)

If your final app will have a Users table, it would look like this in the `schema.prisma`  file
Writing the model like this gives us an easier syntax to understand and write but under the hood it gets converted and runs the same SQL commands that we normally run to create a table. We don't need to understand the SQL commands, Prisma will take care of that, but there are some prisma specific stuff that we'll need to understand.

```prisma
model User {
  id         Int      @id @default(autoincrement())
  username   String   @unique
  password   String
  firstName  String
  lastName   String
}
```

- here `@id` in the first line means that it will be the primary key, then `@default(autoincrement())` means that by default it will auto increment as 1,2,3,... , then `@unique` means that it will be unique, etc.
- *NOTE*: if you want to make any inputs optional you can add the question mark at the end of the type.

which is similar to what we wrote in the SQL query which is

```sql
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(100) UNIQUE NOT NULL,
    password VARCHAR(100) NOT NULL,
    first_name VARCHAR(100),
    last_name VARCHAR(100)
);
```

### **Assignment**

Add a Users and a Todo table in your application. Don’t worry about `foreign keys`/`relationships` just yet

![the table image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F3698bba2-23a2-4a42-846d-5c5ac4fe8e88%2FScreenshot_2024-02-03_at_7.01.25_PM.png?table=block&id=d3feee59-e35a-4692-87a5-590e68814ef8&cache=v2)

- Answer

The answer is something like the following
things to note:

- This is the only place you will have to update the schema as per the growth of the application.

```prisma
model Users2 {
  id Int @id @default(autoincrement())
  email String @unique
  // if you want to make any inputs optional you can add the question mark at the end of the type.
  firstName String 
  lastName String?
  password String
  phoneNumber String // not int since there can be cases like +102374290347
}

model Todos2 {
  id Int @id @default(autoincrement())
  title String
  done Boolean @default(false)
  description String? 
  userId Int
}
```

### **Generate migrations**

You have created a single schema file. You haven’t yet run the `CREATE TABLE`  commands. To run those and create `migration files` , run

```bash
npx prisma migrate dev --name 
```

- This will firstly migrate the DB
- Create one migrations file locally so as to make a copy of what was ran before to create it in the first place.
  - The migrations sql generate newly for everytime you run the above command since it should be not be confusing and it must be clear that what all migrations have been done till now, so that it can be run again in the future if needed.
- the _prisma_migrations table will be created in the DB to keep track of all the migrations that have been done till now.

On comparing the prisma file with the sql file we get the following sql code. Things to note here:

- Prisma have created these tables for us and ran the commands as well.
- `id` has been set as the `CONSTRAINT "Users2_pkey" PRIMARY KEY ("id")` since we set it as `@id`, which basically tells us that `id` is the primary key of both the tables. But it represents how uniquely you can find a row in this table. Users table will have an unique thing called `id` since that will be constant but not the others since that can be changed.
- `SERIAL` here means that the part where we said `@default(autoincrement())`
- here `lastName` doesn't has `NOT NULL` since it is set as `lastName?` in prisma which means that it is optional
- for `String` it is `TEXT`

```sql
-- CreateTable
CREATE TABLE "Users2" (
    "id" SERIAL NOT NULL,
    "email" TEXT NOT NULL,
    "firstName" TEXT NOT NULL,
    "lastName" TEXT,
    "password" TEXT NOT NULL,

    CONSTRAINT "Users2_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Todos2" (
    "id" SERIAL NOT NULL,
    "title" TEXT NOT NULL,
    "done" BOOLEAN NOT NULL DEFAULT false,
    "description" TEXT,
    "userId" INTEGER NOT NULL,

    CONSTRAINT "Todos2_pkey" PRIMARY KEY ("id")
);

-- CreateIndex
CREATE UNIQUE INDEX "Users2_email_key" ON "Users2"("email");

```

Initialize the schema

Your DB should now have the updated schema.

you will have something like the following table:

| Schema | Name | Type | Owner
| --- | --- | --- | --- |
| public | Users2 | table | postgres
| public | Todos2 | table | postgres
| public | _prisma_migrations | table | postgres

- There are these Users2 and Todos2 tables that have been created.
- `prisma_migrations` is a table that prisma uses to keep track of all the migrations that have been run so that it knows how to migrate more as per the growth of the application and this gets filled over time so that prisma understands what all migrations that have been done.

💡 Check the `prisma/migrations`  folder and check if you see anything interesting in there

## **Exploring your database**

If you have `psql` , try to explore the tables that `prisma`  created for you.

```bash
psql -h localhost -d postgres -U postgres
```

![notion image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F37356874-b6c8-40ad-b4c5-bb8dbb066ead%2FScreenshot_2024-02-03_at_7.07.21_PM.png?table=block&id=4bb51e98-490d-4585-b4a7-b6af360def1c&cache=v2)

## Generating the prisma client**

### **What is a client?**

Client represents all the functions that convert. Autogenerated clients were also introduced in the syllabus, which means that if this is a project which has a `schema.prisma` file and eventually have my `index.ts` for node.js file. The benefit of prisma is that we can write `User.findOne()` and `User.add()`, so this `User` variable should come from somewhere and how does the file import that. And that'll be Prisma, Prisma will auto generate clients so that the index.ts file could use them, i.e there are these tables that Prisma understands and creates JS class or JS clients that index.ts can use. This is done by the schema file of prisma. So the steps that occur in a prisma project

- You create a `schema.prisma` file
- You run a command that generates the migrations for you
- You run `npx prisma generate` which will generate the clients for you(yeah you need to tell prisma to generate the clients for you with this command).
- You can use these clients in your Node.js app

And these autogenereated clients will convert the following code

```ts
User.create({email: "harkirat@gmail.com"})
```

into following SQL code

```sql
INSERT INTO users VALUES ...
```

Once you’ve created the `prisma/schema.prisma` , you can generate these `clients`  that you can use in your Node.js app

### **How to generate the client?**

```bash
npx prisma generate
```

This generates a new `client` for you. What this means that there is a new file that gets generated in `'@prisma/client'` after running the above command in the modules folder of prisma that it not in the npm registry and as such we can use that tables' names directly to do CRUD operations on them in the following way. The process of converting that schema to the usable client is termed as autogenerated client

```ts
import { PrismaClient } from '@prisma/client';
const prisma = new PrismaClient();
prisma.users2.find({}) // delete / update / create / findMany / findOne ... etc
```

## Creating your first app

Write a function that let’s you insert data in the `Users` table. Typescript will help you out, here’s a starter code

```ts
import { PrismaClient } from "@prisma/client";

const prisma = new PrismaClient();

async function insertUser(username: string, password: string, firstName: string, lastName: string) {
  
}
```

Solution:

```ts
import { PrismaClient } from "@prisma/client";
const prisma = new PrismaClient();

async function insertUser(username: string, password: string, firstName: string, lastName: string) {
  const res = await prisma.user.create({
    data: {
        username,
        password,
        firstName,
        lastName
    }
    select: {
      id: true,
      password: true,
    }
  })
  console.log(res);
}

insertUser("admin1", "123456", "harkirat", "singh")
```

- the syntax of the prisma library goes in this manner so the data object is required, there may be other keys like this that expects some type of data. It only expects two keys, `data` and `select`.
  - The other object keys examples are like `select` which tells us what that `res` variable should return after the operation is done.
- The syntax will be like this for other crud operations.
- **NOTE**: Since there is an autoIncrement in the id, everytime we do an erroneous operation, the id will keep on increasing but the value will not reach the DB. So we see that the id is three in our neonDB table.

id | email | first_name | last_name | password
--- | --- | --- | --- | ---
1 | <aorstni@gmail.com> | harkirat | aorisnt | arsotina
2 | <aorstni@gmail.com> | harkirat | aorisnt | arsotina
4 | <aorstni@gmail.com> | harkirat | aorisnt | arsotina

**Update**: Write a function that let’s you update data in the `Users`  table.Starter code -

```ts
import { PrismaClient } from "@prisma/client";
const prisma = new PrismaClient();

interface UpdateParams {
    firstName: string;
    lastName: string;
}

async function updateUser(username: string, {
    firstName,
    lastName
}: UpdateParams) {
  
}
```

Solution:

```ts
import { PrismaClient } from "@prisma/client";

const prisma = new PrismaClient();

interface UpdateParams {
    firstName: string;
    lastName: string;
}

async function updateUser(username: string, {
    firstName,
    lastName
}: UpdateParams) {
  const res = await prisma.user.update({
    where: { username },
    data: {
      firstName,
      lastName
    }
  });
  console.log(res);
}

updateUser("admin1", {
    firstName: "new name",
    lastName: "singh"
})
```

How to know which are the keys that the objects of the prisma library expects, you can check the documentation of the prisma library, or just ctrl+click on the object, or google it out.

**Get a user’s details**: Write a function that let’s you fetch the details of a user given their emailStarter code

```ts
import { PrismaClient } from "@prisma/client";
const prisma = new PrismaClient();

async function getUser(username: string) {
  
}
```

```ts
import { PrismaClient } from "@prisma/client";

const prisma = new PrismaClient();

async function getUser(username: string) {
  const user = await prisma.user.findFirst({
    where: {
        username: username
    }
  })
  console.log(user);
}

getUser("admin1");
```

![hello](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F1462c745-cd2b-45a7-851d-33f9b284123f%2FScreenshot_2024-02-04_at_12.47.46_AM.png?table=block&id=1937fb45-5ace-4b7b-95b4-9662cb8f0489&cache=v2)

![second](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F53d7eba3-cb51-42bb-8368-a4051beea4ea%2FScreenshot_2024-02-04_at_12.49.38_AM.png?table=block&id=37fb73c6-3356-465c-aad5-d98bf1a6d311&cache=v2)

**NOTE**: Also don't forget to add try catch blocks to the code so that any error while connecting or some other errors gets caught and the code doesn't break. Also don't forget to close the connection to the database after the operations are done. Also don't forget to add the `await` keyword before the prisma functions so that the code waits for the operation to be done before moving to the next line.
Additional Notes:

- Prisma Client Lifecycle: It’s important to manage the lifecycle of the Prisma client correctly. If your application runs multiple queries, you might not want to disconnect after each operation. In such cases, manage the client connection and disconnection more centrally in your application.
- Error Handling: Proper error handling is included to log any issues that occur during the update operation.
- Also to use the interface with an const object, you should use the `:` operator after the const object so that the interface properties are used in the object.
