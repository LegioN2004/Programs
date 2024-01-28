import {useContext, useState } from 'react';
import { CountContext } from './context';

function App() {
	const [count, setCount] = useState(0);
	return (
		<>
			<div>
				hi there
				<CountContext.Provider value={{count, setCount}}>
					<Count></Count>
				</CountContext.Provider>
			</div>
		</>
	);
}

function Count() {
	return (
		<div>
			<CountRenderer />
			<Buttons></Buttons>
		</div>
	);
}

// this part is of prop drilling and context api
function CountRenderer() {
	const { count } = useContext(CountContext);
	return <div>{count}</div>;
}

function Buttons() {
	const { count, setCount } = useContext(CountContext);
	return (
		<div>
			<button onClick={() => setCount(count + 1)}>Increment</button>

			<button onClick={() => setCount(count - 1)}>Decrement</button>
		</div>
	);
}

export default App;
