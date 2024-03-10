// make me a simple fetch request code snippet
const axios = require('axios');
async function main() {
	const response = await fetch('https://sum-server.100xdevs.com/todos');
	const res = await response.json();
	console.log(res);
	console.log(' from here is the new out put');
}

async function mainAxios() {
	const response = await axios.get('https://sum-server.100xdevs.com/todos');
	console.log(response.data.todos);
}

main();
mainAxios();
