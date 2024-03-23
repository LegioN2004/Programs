interface User {
	firstName: string;
	lastName: string;
	email: string;
	age: number;
}

const user: User = {
	firstName: 'John',
	lastName: 'Doe',
	email: 'hello@gmail.com',
	age: 30,
};

console.log(user.firstName);
