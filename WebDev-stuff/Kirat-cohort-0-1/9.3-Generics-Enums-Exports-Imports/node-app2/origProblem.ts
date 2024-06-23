function origProblem<T>(arg: T[]): T[] {
	return [arg[0], arg[1]];
}

const helloHi = origProblem<string>(['Halleooooo', 'BYeeeeEee']);
const helloHi2 = origProblem([1, 2, 3]);

interface User {
	name: string;
	age: number;
}

const User1 = origProblem<User>([
	{ name: 'John', age: 25 },
	{ name: 'Doe', age: 30 },
]);

for (let index = 0; index < 2; index++) {
	console.log(User1[index].name.toLowerCase());
}
