const express = require('express');
const router = express.Router();
const jwt = require('jsonwebtoken');
const { User } = require('../db');
const { JWT_SECRET } = require('../dbConfig');
const {
	signupMiddleware,
	authMiddleware,
	signinMiddleware,
	updateMiddleware,
} = require('../middlewares/middleware');

router.post('/signup', signupMiddleware, (req, res) => {
	const firstName = req.body.firstName;
	const lastName = req.body.lastName;
	const userId = User.userId;
	const jwtToken = jwt.sign(
		{
			userId,
		},
		JWT_SECRET
	);
	res.status(200).json({
		msg: `signup donee for the user ${firstName} ${lastName} `,
		token: `${jwtToken}`,
	});
});

router.post('/signin', signinMiddleware, (req, res) => {
	const firstName = req.body.firstName;
	const lastName = req.body.lastName;
	const token = req.headers.authorization;
	const tokenArray = token.split(' ')[1];

	res.status(200).json({
		msg: `signed in the user ${firstName} ${lastName} successfully`,
		token: tokenArray,
	});
});

router.put('/update', updateMiddleware, (req, res) => {
	res.json({
		message: 'details updated successfully',
	});
});

// router.get('/bulk', authMiddleware, async (req, res) => {
router.get('/bulk', async (req, res) => {
	const param = req.query.filter || '';
	const userExists = await User.find({
		$or: [
			{
				firstName: {
					$regex: param,
				},
			},
			{
				lastName: {
					$regex: param,
				},
			},
		],
	});
	try {
		if (userExists) {
			res.status(200).json({
				user: userExists.map((user) => ({
					username: user.username,
					firstName: user.firstName,
					lastName: user.lastName,
					_id: user.userId,
				})),
			});
		} else {
			res.status(411).json({
				msg: 'You have a typo fix that and re-enter',
			});
		}
	} catch (e) {
		res.status(500).json({
			msg: 'unknown error occured',
		});
	}
});
module.exports = router;
