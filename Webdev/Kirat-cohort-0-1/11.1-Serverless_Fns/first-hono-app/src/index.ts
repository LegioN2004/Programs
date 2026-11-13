import { Hono } from 'hono';

const app = new Hono();

// ----------------- example get request --------------------------
// app.get('/', (c) => {
//   return c.text('Hello Hono!')
// })

// ----------------- example post request --------------------------
// app.post('/', async (c) => {
// 	const body = await c.req.json();
// 	console.log(body);
// 	console.log(c.req.header('Authorization'));
// 	console.log(c.req.query('param'));

// 	return c.text('Hello Hono!');
// });

async function authMiddleware(c: any, next: any) {
	if (c.req.header('Authorization')) {
		await next();
	} else {
		return c.text("You don't have proper access");
	}
}

app.use(authMiddleware);

export default app;
