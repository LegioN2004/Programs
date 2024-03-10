const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');
const app = express();
const mainRouter = require('./routes/index');

app.use(express.json());
app.use(bodyParser.json());
app.use(cors());

app.use('/api/v1', mainRouter);
// app.use('/api/v2', mainRouter);

// app.get('/user', async (req, res) => {
// 	try {
// 		const users = await User.find();
// 		res.json(users);
// 	} catch (error) {
// 		res.status(500).json({ error: 'Internal server error' });
// 	}
// });

// error handling middleware, global catch
app.use((err, req, res, next) => {
	console.error(err.stack);
	res
		.status(500)
		.send(
			'Something went wrong with the server, refresh the page or try again!'
		);
});

app.listen(3000, () => {
	try {
		console.log('listening on the port 3000');
	} catch (e) {
		console.log(e);
	}
});
