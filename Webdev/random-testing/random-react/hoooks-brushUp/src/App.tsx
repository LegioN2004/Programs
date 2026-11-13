import { useState } from 'react';
import './App.css';

function CountItem() {
	console.log('run the function');
	return 0;
}

function App() {
	const [count, setCount] = useState(() => CountItem());

	function decrement() {
		// setCount(count - 1);
		// setCount(count - 1);
		setCount((prevCount) => prevCount - 1);
		setCount((prevCount) => prevCount - 1);
	}

	function increment() {
		// setCount(count + 1);
		setCount((prevCount) => prevCount + 1);
		setCount((prevCount) => prevCount + 1);
	}

	return (
		<>
			<div>
				<button onClick={decrement}>-</button>
				<span>{count}</span>
				<button onClick={increment}>+</button>
			</div>
		</>
	);
}

export default App;
