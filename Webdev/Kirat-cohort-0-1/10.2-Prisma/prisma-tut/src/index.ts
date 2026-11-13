import { PrismaClient } from '@prisma/client';
const prisma = new PrismaClient();

// similar to import mongoose from "mongooose"; mongoose.connect("")

// insert user into the DB
async function insertUser(
	username: string,
	password: string,
	firstName: string,
	lastName: string
) {
	const res = await prisma.users2.create({
		data: {
			email: username,
			password,
			firstName,
			lastName,
		},
		select: {
			id: true,
			password: true,
		},
	});
	console.log(res);
}

// insertUser('hello2@gmail.com', 'thirdPass@123', 'third', 'name');

// update user into the DB
interface UpdateUser {
	firstName: string;
	lastName: string;
}

const updatedUser: UpdateUser = {
	firstName: 'UpdatedThird',
	lastName: 'lastname',
};

async function updateUser(
	username: string,
	{ firstName, lastName }: UpdateUser
) {
	try {
		const res = await prisma.users2.update({
			where: { email: username },
			data: {
				firstName,
				lastName,
			},
		});
		console.log(res);
	} catch (err) {
		console.log('some error', err);
	}
}

// updateUser('hello2@gmail.com', updatedUser);
// or use this updateUser('hello2@gmail.com', {firstName: "hello", lastName: "hi"})

// delete the user from the DB
interface DeleteUser {
	firstName: string;
	lastName: string;
}

async function deleteUser(username: string) {
	try {
		const res = await prisma.users2.delete({
			where: { email: username },
		});
		console.log('deleted', res);
	} catch (error) {
		console.log('some error occured', error);
	}
}
// deleteUser('hello3@gmail.com');

// fetch a user's details
async function getUsers(username: string) {
	try {
		const res = await prisma.users2.findFirst({
			where: { email: username },
		});
		console.log(res);
	} catch (error) {
		console.log('there is some error', error);
	}
}

getUsers('hello5@gmail.com');
