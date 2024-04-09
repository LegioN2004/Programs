interface User {
	firstName: string;
	lastName: string;
	age: number;
}

function filtersUser(user: User[]) {
	return user.filter((x) => x.age >= 18);
}

console.log(
	filtersUser([
		{
			firstName: 'first',
			lastName: 'first',
			age: 1,
		},
		{
			firstName: 'second',
			lastName: 'second',
			age: 18,
		},
	])
);
