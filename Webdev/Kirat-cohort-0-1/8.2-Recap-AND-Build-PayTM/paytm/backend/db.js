const mongoose = require('mongoose');
const { db_url } = require('./dbConfig');

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
		trim: true, // removes any extra spaces from the names of the user
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
	// userName: String,
	// firstName: String,
	// lastName: String,
	// password: String,
});

const accountSchema = new mongoose.Schema({
	userId: {
		type: mongoose.Schema.Types.ObjectId,
		ref: 'User',
		required: true,
	},
	balance: {
		type: Number,
		required: true,
	},
});

const User = new mongoose.model('User', UserSchema);
const Account = new mongoose.model('Account', accountSchema);

module.exports = {
	User,
	Account,
};
