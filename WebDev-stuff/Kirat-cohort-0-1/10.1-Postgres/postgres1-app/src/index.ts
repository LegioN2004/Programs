import { Client } from 'pg';
import { PG_URL } from './password';

// const client = new Client({
// 	host: 'ep-sparkling-wood-14667063.ap-southeast-1.aws.neon.tech',
// 	port: 5334,
// 	database: 'firstMongoDbInstance',
// 	user: 'LegioN2003',
// 	password: '7gnQPfdeZY4s',
// });

const client = new Client({
	connectionString: PG_URL,
});

// async function connectClient() {
// 	if (!client.connect()) {
// 		await client.connect();
// 	}
// }

// create users table
async function createUsersTable() {
	// connectClient();
	const result = await client.query(`
    CREATE TABLE users (
        id SERIAL PRIMARY KEY,
        username VARCHAR(50) UNIQUE NOT NULL,
        email VARCHAR(255) UNIQUE NOT NULL,
        password VARCHAR(255) NOT NULL,
        created_at TIMESTAMP WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP
    );
    `);
}

// createUsersTable();

async function createAddressesTable() {
	// connectClient();
	const result = await client.query(`
CREATE TABLE addresses (
    id SERIAL PRIMARY KEY,
    user_id INTEGER NOT NULL,
    city VARCHAR(100) NOT NULL,
    country VARCHAR(100) NOT NULL,
    street VARCHAR(255) NOT NULL,
    pincode VARCHAR(20),
    created_at TIMESTAMP WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
);
    `);
}

// createAddressesTable();

// insert data to users table
async function insertDataToUsers() {
	await client.connect();
	try {
		const Query =
			"INSERT INTO users (username, email, password) VALUES ('hello3', 'hello3@gmail.com', 'password3');";
		const res = await client.query(Query);
		console.log('Insertion success', res);
	} catch (error) {
		console.log('some error happened', error);
	} finally {
		await client.end();
	}
}

// insertDataToUsers();

// secure data entry

async function insertDataSecurely(
	user_id: number,
	city: string,
	country: string,
	street: string,
	pincode: string
) {
	// connectClient();
	try {
		await client.connect();
		// await client.connect(); // Ensure client connection is established
		// Use parameterized query to prevent SQL injection
		const insertQuery =
			// 'INSERT INTO users (username, email, password) VALUES ($1, $2, $3)';
			'INSERT INTO addresses (user_id, city, country, street, pincode) VALUES ($1, $2, $3, $4, $5);';
		const values = [user_id, city, country, street, pincode];
		const res = await client.query(insertQuery, values);
		console.log('Insertion success:', res); // Output insertion result
	} catch (err) {
		console.error('Error during the insertion:', err);
	} finally {
		await client.end(); // Close the client connection
	}
}

// Example usage
// insertDataSecurely(1, 'New York City', 'hello', 'bye street', '10348l').catch( console.error);

// fetch data from users table

async function fetchDataFromUsers(email: string) {
	try {
		await client.connect();
		const query = `SELECT * FROM users WHERE email = $1`;
		const value = [email];
		const result = await client.query(query, value);
		// const result = await client.query(query, [email]);
		if (result.rows.length > 0) {
			console.log('User found:', result.rows[0]); // Output user data
			return result.rows[0]; // Return the user data
		} else {
			console.log('No user found with the given email.');
			return null; // Return null if no user was found
		}
	} catch (err) {
		console.error('Error during fetching user:', err);
		throw err; // Rethrow or handle error appropriately
	} finally {
		await client.end(); // Close the client connection
	}
}

// fetchDataFromUsers('hello3@gmail.com').catch(console.error);

async function joinUsersToAddresses(user_id: string) {
	try {
		await client.connect();
		const query = ` SELECT u.id, u.username, u.email, a.city, a.country, a.street, a.pincode
		FROM users u
		JOIN addresses a ON u.id = a.user_id
		WHERE u.id = $1;`;
		const result = await client.query(query, [user_id]);
		if (result.rows.length > 0) {
			console.log('User and address found:', result.rows[0]);
			return result.rows[0];
		} else {
			console.log('No user or address found with the given ID.');
			return null;
		}
	} catch (error) {
		console.log('error while connect or some server error', error);
		throw error;
	} finally {
		await client.end();
	}
}

joinUsersToAddresses('1');
