import React, { useEffect, useState } from 'react';
import './App.css';
import { Dimensions } from './Dimensions';
import { MouseMove } from './MouseMove';
import { Online } from './Online';
import { Todo } from './Todo';
import { Timer } from './Timer';
import { Debounce } from './Debounce';

export default function App() {
	const [showComponent, setShowComponent] = useState(true);
	useEffect(() => {
		setTimeout(() => {
			// Perform setup or data fetching here
			setShowComponent(false);
		}, 2000);
	}, [showComponent]);
	// return <>{showComponent ? <MyComponent></MyComponent> : <div></div>}</>;
	return (
		<div>
			{/* <Todo /> */}
			{/* <Online></Online> */}
			{/* <MouseMove></MouseMove> */}
			{/* <Dimensions></Dimensions> */}
			{/* <Timer></Timer> */}
			<Debounce></Debounce>
		</div>
	);
}

function MySecComponent() {
	useEffect(() => {
		console.log('component mounted');
		// Perform setup or data fetching here
		return () => {
			// Cleanup code (similar to componentWillUnmount)
			console.log('component unmounted');
		};
	}, []);

	// Render UI
	return <h1>Hello World</h1>;
}

class MyComponent extends React.Component {
	componentDidMount() {
		// Perform setup or data fetching here
		console.log('component mounted');
	}

	componentWillUnmount() {
		// Clean up (e.g., remove event listeners or cancel subscriptions)
		console.log('component unmounted');
	}

	render() {
		// Render UI
		return <div>Hello World</div>;
	}
}

// function MyComponent() {
// 	const [count, setCount] = useState(0);

// 	const incrementCount = () => {
// 		setCount(count + 1);
// 	};

// 	return (
// 		<div>
// 			<p>{count}</p>
// 			<button onClick={incrementCount}>Increment</button>
// 		</div>
// 	);
// }

// ---------------------------------------------------------------------------
// same code of the above but by using class based components
// class MyComponent extends React.Component {
// 	constructor(props) {
// 		super(props);
// 		this.state = { count: 0 };
// 	}

// 	incrementCount = () => {
// 		this.setState({ count: this.state.count + 1 });
// 	};

// 	render() {
// 		return (
// 			<div>
// 				<p>{this.state.count}</p>
// 				<button onClick={this.incrementCount}>Increment</button>
// 			</div>
// 		);
// 	}
// }
