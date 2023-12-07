// let person1 = 'hello';
// let person2 = 'hi';
// let person3 = 'bye';
// let person = 'h';

// const personArray = ['hello ', ' hi ', ' byeeeeee '];
// console.log(personArray[0] + personArray[2]);

// // print even no in an array
// const ages = [22, 23, 24, 25, 26];

// for (let i = 0; i < ages.length; i++) {
// 	if (ages[i] % 2 == 0) {
// 		console.log(ages[i]);
// 	}
// }

// // print the biggest no in an array

// const big = [123, 234, 234324, 3, 12423424];
// let a = 0;
// for (let i = 0; i < big.length; i++) {
// 	if (big[i] > a) {
// 		a = big[i];
// 	}
// }
// console.log(a);

// // gender
// const personArray2 = ['ram', 'shyam', 'goru', ' goodnight'];
// const genderArray = ['male', 'male', 'female', 'female'];

// for (i = 0; i < personArray2.length; i++) {
// 	if (genderArray[i] == 'male') {
// 		console.log(personArray2[i]);
// 	}
// }

// // complex object
// const user1 = {
// 	firstName2: 'mili',
// 	genderArray2: 'male',
// };

// console.log(user1['genderArray2']);

// arsoteinartion
const allUsers = [
	{
		firstName: 'mili',
		genderArray: 'male',
		metadata: [
			{
				age: 21,
				height: 6,
			},
		],
	},
	{
		firstName: 'bye',
		genderArray: 'female',
	},
	{
		firstName: 'nonastain',
		genderArray: 'female',
	},
];

for (let i = 0; i < allUsers.length; i++) {
	console.log(allUsers[0]['metadata']);
	if (allUsers[i]['genderArray'] == 'male') {
		console.log(allUsers[i]['firstName']);
	}
}
