const express = require('express');
const {
	signinMiddleware,
	authMiddleware,
} = require('../middlewares/middleware');
const router = express.Router();
const { Account } = require('../db');
// TODO: why does using Account instead of object destructuring show an error saying that  in the Account.findOne line findOne is not a function
const mongoose = require('mongoose');

router.get('/balance', authMiddleware, async (req, res) => {
	const userId = req.body.userId;
	const account = await Account.findOne({
		userId: userId,
	});
	if (account) {
		res.json({
			message: 'balance fetched successfully',
			balance: account.balance,
		});
	} else {
		return res.status(404).json({
			message: "coundn't retrieve balance, check the userId",
		});
	}
});

// router.post('/transfer', async (req, res) => {
// 	const session = await mongoose.startSession();

// 	await session.startTransaction();

// 	const { amount, to } = req.body;
// 	const account = await Account.findOne({
// 		userId: req.body.userId,
// 	}).session(session);

// 	if (!account || account.balance < amount) {
// 		await session.abortTransaction();
// 		return res
// 			.status(400)
// 			.json({ message: 'Insufficient balance or account not found' });
// 	}

// 	const toAccount = await Account.findOne({ userId: to }).session(session);

// 	if (!toAccount) {
// 		await session.abortTransaction();
// 		return res.status(400).json({ message: 'Account not found' });
// 	}

// 	await Account.updateOne(
// 		{ userId: req.body.userId },
// 		{ $inc: { balance: -amount } }
// 	).session(session);
// 	await Account.updateOne(
// 		{ userId: req.body.to },
// 		{ $inc: { balance: amount } }
// 	).session(session);

// 	res.json({
// 		message: 'transfer successful',
// 		from: `${account.userId} with balance ${account.balance}`,
// 		balance: toAccount.balance,
// 	});
// });

router.post('/transfer', authMiddleware, async (req, res) => {
	const session = await mongoose.startSession();

	session.startTransaction();
	const { amount, to } = req.body;

	// Fetch the accounts within the transaction
	const account = await Account.findOne({ userId: req.body.userId }).session(
		session
	);

	if (!account || account.balance < amount) {
		await session.abortTransaction();
		return res.status(400).json({
			message: 'Insufficient balance',
		});
	}

	const toAccount = await Account.findOne({ userId: to }).session(session);

	if (!toAccount) {
		await session.abortTransaction();
		return res.status(400).json({
			message: 'Invalid account',
		});
	}

	// Perform the transfer
	await Account.updateOne(
		{ userId: req.body.userId },
		{ $inc: { balance: -amount } }
	).session(session);
	await Account.updateOne(
		{ userId: to },
		{ $inc: { balance: amount } }
	).session(session);

	// Commit the transaction
	await session.commitTransaction();
	res.json({
		message: 'Transfer successful',
	});
});

module.exports = router;
