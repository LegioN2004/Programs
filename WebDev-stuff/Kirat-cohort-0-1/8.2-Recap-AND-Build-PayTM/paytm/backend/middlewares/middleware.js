const jwt = require('jsonwebtoken');
const { JWT_SECRET } = require('../dbConfig');
const zod = require('zod');
const { User, Account } = require('../db');
const userSchema = zod.object({
	username: zod.string().min(3).max(30).email(),
	firstName: zod.string().max(50),
	lastName: zod.string().max(50),
	password: zod.string().min(6),
});

// const userId = Math.floor(Math.random() * 1000000);

async function signupMiddleware(req, res, next) {
	const username = req.body.username;
	const firstName = req.body.firstName;
	const lastName = req.body.lastName;
	const password = req.body.password;

	const parsedUsers = userSchema.safeParse({
		username: req.body.username,
		firstName: req.body.firstName,
		lastName: req.body.lastName,
		password: req.body.password,
	});

	const userExists = await User.findOne({
		username: req.body.username,
	});

	const randomBalance = Math.floor(Math.random() * 1000000);

	// credential logic
	try {
		if (!userExists && parsedUsers.success) {
			// const user = await User.create({
			const user = new User({
				// try with this as well
				username: username,
				firstName: firstName,
				lastName: lastName,
				password: password,
			});
			console.log(user);
			const userId = user._id;

			if (userId) {
				// const account = await Account.create({
				const account = new Account({
					// try with this as well
					userId,
					balance: randomBalance,
				});
				await account.save();
			}
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

async function signinMiddleware(req, res, next) {
	const token = req.headers.authorization;
	const username = req.body.username;
	const password = req.body.password;

	const signinBody = zod.object({
		username: zod.string().email(),
		password: zod.string(),
	});
	// TODO: check why using userSchema here instead of signinBody gives me this error `{ success: false, error: [Getter] }`
	const parsedUsers = signinBody.safeParse(req.body);
	const userExists = await User.findOne({
		username: username,
		password: password,
	});

	if (!parsedUsers.success) {
		return res.status(401).json({ msg: 'wrong inputs, check again' });
	}

	if (!token && !token.startsWith('Bearer ')) {
		return res.status(403).json({ msg: 'invalid token' });
	}
	const tokenArray = token.split(' ')[1];
	const verification = await jwt.verify(tokenArray, JWT_SECRET);

	// credential logic
	try {
		if (!userExists) {
			return res.status(411).json({
				msg: 'error while logging in, wrong credentials change em or if user not signed up, sign up first',
			});
		} else if (!verification) {
			return res.status(403).json({
				message:
					"Forbidden: Invalid token, or token doesn't exist get a new one by signing up :)",
			});
		} else {
			req.userId = tokenArray.userId;
			next();
		}
	} catch (error) {
		res.status(500).json({
			msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
		});
	}
	next();
}

// TODO: check if we need to use authentication using jwt token to do stuff like changing data or getting data, etc. If yes add the authMiddleware to everywhere other than signup, signin, or update

async function authMiddleware(req, res, next) {
	const authHeader = req.headers.authorization;
	if (!authHeader || !authHeader.startsWith('Bearer ')) {
		return res.status(403).json({
			message:
				"Forbidden: Invalid token, or token doesn't exist get a new one by signing up :)",
		});
	}

	const token = authHeader.split(' ')[1];

	try {
		const decoded = jwt.verify(token, JWT_SECRET);
		req.userId = decoded.userId;
		next();
	} catch (err) {
		return res.status(403).json({
			message: 'server error, refresshh the page :-<',
		});
	}
}

async function updateMiddleware(req, res, next) {
	const updatedBody = zod.object({
		firstName: zod.string().optional(),
		lastName: zod.string().optional(),
		password: zod.string().optional(),
	});

	const { success } = updatedBody.safeParse(req.body);
	try {
		if (!success) {
			res.status(411).json({
				message: 'Error while updating information',
			});
		}
		await User.updateOne({ _id: req.body.userId }, req.body);
		next();
	} catch (error) {
		res.status(500).json({
			msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
		});
	}
}

module.exports = {
	signupMiddleware,
	signinMiddleware,
	updateMiddleware,
	authMiddleware,
};
