// custom hooks
import { memo, useCallback, useEffect, useState } from 'react';
import './App.css';

function useTodos() {}

function App() {
	const [todos, setTodos] = useState([]);

	useEffect(() => {
		axios.get('').then((res) => {
			setTodos(res.data.todos);
		});
	}, []);
	// var a = 1;

	return <>{todos}</>;
}
export default App;
