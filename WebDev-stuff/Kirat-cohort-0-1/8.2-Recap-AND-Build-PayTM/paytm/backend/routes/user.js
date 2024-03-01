const express = require('express');
const router = express.Router();
const zod = require('zod');
const jwt = require('jsonwebtoken');
const { User } = require('../db');
const { JWT_SECRET } = require('../dbConfig');

const userSchema = zod.object({
	userName: zod.string().min(3).max(30).email(),
	firstName: zod.string().max(50),
	lastName: zod.string().max(50),
	password: zod.string().min(6),
});

const userId = Math.floor(Math.random() * 1000000);

async function signupMiddleware(req, res, next) {
	const userName = req.body.userName;
	const firstName = req.body.firstName;
	const lastName = req.body.lastName;
	const password = req.body.password;

	const parsedUsers = userSchema.safeParse({
		userName: req.body.userName,
		firstName: req.body.firstName,
		lastName: req.body.lastName,
		password: req.body.password,
	});

	const userExists = await User.findOne({
		userName: req.body.userName,
		password: req.body.password,
	});

	// credential logic
	try {
		if (!userExists && parsedUsers) {
			const user = new User({
				userName: userName,
				firstName: firstName,
				lastName: lastName,
				password: password,
				userId: userId,
			});
			await user.save();
			next();
		} else {
			res.status(411).json({
				msg: 'Username or password already exists, change your credentials',
			});
		}
	} catch (error) {
		res.status(500).json({
			msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
		});
	}
}

router.post('/signup', signupMiddleware, (req, res) => {
	const firstName = req.body.firstName;
	const lastName = req.body.lastName;
	const jwtToken = jwt.sign(
		{
			userId: userId,
		},
		JWT_SECRET
	);
	res.status(200).json({
		msg: `signup donee for the user ${firstName} ${lastName} `,
		token: `${jwtToken}`,
	});
});

async function signinMiddleware(req, res, next) {
	const token = req.header.token;
	const userExists = await User.findOne({
		userName: userSchema.safeParse(req.body.userName),
		password: userSchema.safeParse(req.body.password),
	});
	const verifyToken = jwt.verify(token, JWT_SECRET);

	// credential logic
	try {
		if (!userExists && !verifyToken) {
			res.status(411).json({
				msg: 'error while logging in, wrong credentials, change em or if user not signed up, sign up first',
			});
		}
	} catch (error) {
		res.status(500).json({
			msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
		});
	}
	next();
}

router.post('/signin', signinMiddleware, (req, res) => {
	const firstName = req.body.firstName;
	const lastName = req.body.lastName;
	const token = req.header.token;
	res.status(200).json({
		msg: `signed in the user ${firstName} ${lastName} successfully`,
		token: token,
	});
});

async function updateMiddleware(req, res, next) {
	const userName = req.body.userName;
	const password = req.body.password;
	const updatedFirstName = req.body.updatedFirstName;
	const updatedLastName = req.body.updatedLastName;
	const updatedPassword = req.body.updatedPassword;
	const userExists = await User.findOne({
		userName: req.body.userName,
		password: req.body.password,
	});

	// credential logic
	try {
		if (userExists) {
			await User.findOneAndUpdate(
				{ userName: userName, password: password },
				{
					firstName: updatedFirstName,
					lastName: updatedLastName,
					password: updatedPassword,
				}
			);
			next();
		} else {
			res.status(400).json({
				msg: 'User does not exist, cannot be replaced. Create one first',
			});
		}
	} catch (error) {
		res.status(500).json({
			msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
		});
	}
}

router.put('/update', updateMiddleware, (req, res) => {
	res.json('updated successfully');
});

module.exports = router;
