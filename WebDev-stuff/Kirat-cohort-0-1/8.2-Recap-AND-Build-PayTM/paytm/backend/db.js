const mongoose = require('mongoose');
const {db_url} = require("./dbConfig");

mongoose
	.connect(db_url)
	.then(() => {
		console.log('Connected to database');
	})
	.catch((err) => {
		console.log('Error connecting to DB, The error: ', err.message);
	});

const UserSchema = new mongoose.Schema({
	username: {
		type: String,
		required: true,
		unique: true,
		trim: true,
		lowercase: true,
		minLength: 3,
		maxLength: 30,
	},
	firstName: {
		type: String,
		required: true,
		trim: true,
		maxLength: 50,
	},
	lastName: {
		type: String,
		required: true,
		trim: true,
		maxLength: 50,
	},
	password: {
		type: String,
		required: true,
		minLength: 6,
	},
	userId: {
		type: Number,
		required: true,
	},
	// userName: String,
	// firstName: String,
	// lastName: String,
	// password: String,
});

const User = new mongoose.model('User', UserSchema);

module.exports = {
	User,
};
