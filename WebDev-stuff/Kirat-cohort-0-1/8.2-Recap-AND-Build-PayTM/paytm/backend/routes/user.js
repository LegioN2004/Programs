const express = require('express');
const router = express.Router();
const zod = require('zod');
const zodString = zod.string().max(9).min(3);
const zodPass = zod.string();

async function signupMiddleware(req, res, next) {
	const userName = req.body.userName;
	const firstName = req.body.firstName;
	const lastName = req.body.lastName;
	const password = req.body.password;
	const userExists = await User.findOne({
		userName: req.body.userName,
		password: req.body.password,
	});

	// credential logic
	try {
		if (!userExists) {
			const user = new User({
				userName: userName,
				firstName: firstName,
				lastName: lastName,
				password: password,
			});
			await user.save();
			next();
		} else {
			res.status(400).json({
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
	res.json({
		msg: 'signup doneeeeeeee',
	});
});

async function signinMiddleware(req, res, next) {
	const userName = req.body.userName;
	const firstName = req.body.firstName;
	const lastName = req.body.lastName;
	const password = req.body.password;
	const userExists = await User.findOne({
		userName: req.body.userName,
		password: req.body.password,
	});

	// credential logic
	try {
		if (!userExists) {
			res.status(400).json({
				msg: 'wrong credentials, change em or if user not signed up, sign up first',
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
	res.status(300).json({
		msg: 'signed in successfully',
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

module.exports(router);
