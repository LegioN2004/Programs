interface Manager {
	name: string;
}

interface User {
	age: number;
}

interface BigPerson extends User, Manager {
	gender: string;
}

const main = (user: BigPerson) => {
	user.name = 'John';
	user.age = 25;
	user.gender = 'byen';
	return user.name, user.age, user.gender;
};

console.log(main);
