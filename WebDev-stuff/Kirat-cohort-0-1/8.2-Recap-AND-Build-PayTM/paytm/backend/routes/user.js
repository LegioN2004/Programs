const express = require('express');
const router = express.Router();
const jwt = require('jsonwebtoken');
const { User } = require('../db');
const { JWT_SECRET } = require('../dbConfig');
const {signupMiddleware} = require( "../middlewares/middleware");
const {signinMiddleware} = require( "../middlewares/middleware");
const {updateMiddleware} = require( "../middlewares/middleware");

router.post('/signup', signupMiddleware, (req, res) => {
	const firstName = req.body.firstName;
	const lastName = req.body.lastName;
	const jwtToken = jwt.sign(
		{
			userId: User.userId,
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
	res.status(200).json({
		msg: `signed in the user ${firstName} ${lastName} successfully`,
		token: separateBearer,
	});
});


router.put('/', signinMiddleware, updateMiddleware, (req, res) => {
	res.json({
			message: 'details updated successfully',
		})
});

router.put('/bulk', async (req,res) => {
	const param = req.query.filter;
	const userExists1 = await User.findOne({
		firstName: param,
	})
	const userExists2 = await User.findOne({
		lastName: param,
	})
	try {
		if((userExists1 || userExists2)){
			res.status(200).json({
				users : [{
					firstName: User.firstName,
					lastName: User.lastName,
					_id: User.userId,
				}],
			})
		}else{
			res.status(411).json({
				msg: "You have a type fix that and re-enter",
			})
		}
	} catch (e) {
		res.status(500).json({
			msg: "unknown error occured",
		})
	}
})
module.exports = router;
