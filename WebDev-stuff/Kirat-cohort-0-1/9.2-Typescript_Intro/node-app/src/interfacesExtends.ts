interface Manager {
	name: string;
}

interface User {
	age: string;
}

interface BigPerson extends User,Manager{
   gender: string; 
}