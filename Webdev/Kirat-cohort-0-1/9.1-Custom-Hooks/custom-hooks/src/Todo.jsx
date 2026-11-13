import axios from 'axios';
import { useEffect, useState } from 'react';

function useTodos(n) {
	const [todos, setTodos] = useState([]);
	const [loading, setLoading] = useState(true);

	useEffect(() => {
		const value = setInterval(() => {
			axios.get('https://sum-server.100xdevs.com/todos').then((res) => {
				setTodos(res.data.todos);
				setLoading(false);
			});
		}, n * 1000);
		console.log(value);
		axios.get('https://sum-server.100xdevs.com/todos').then((res) => {
			setTodos(res.data.todos);
			setLoading(false);
		});
		return () => {
			// the way to clear the interval
			clearInterval(value);
		};
	}, [n]);

	return { todos, loading };
}

export function Todo() {
	const { todos, loading } = useTodos(5);
	if (loading) return <div>Loading...</div>;
	return (
		<>
			{todos.map((todo) => (
				<Track todo={todo} />
			))}
		</>
	);
}

function Track({ todo }) {
	return (
		<div>
			{todo.title}
			<br />
			{todo.description}
		</div>
	);
}
