// make me a simple fetch request code snippet
const axios = require('axios');
async function main() {
	// const response = await fetch('https://www.boredapi.com/api/activity');
	const response = await fetch('https://reqres.in/api/users', {
		method: 'POST', // you have to define post here, get is by default
		body: {
			username: 'morpheus',
			password: 'pistol',
		},
		headers: {
			Authorization: 'Bearer my-token',
		},
	});
	const res = await response.json();
	console.log('-----------------------------');
	console.log(res, 'first response');
}
async function mainAxios() {
	const response = await axios.get(
		'https://httpdump.app/dumps/d5b31dd3-5d4b-45e5-83c2-f79e07b875b0',
		{
			username: 'morpheus',
			password: 'pistol',
		},
		{
			headers: {
				Authorization: 'Bearer token',
			},
		}
	);
	console.log(response.data, 'second response');
}

// main();
mainAxios();
