import { useEffect, useState } from 'react';

export function Timer() {
	const [count, setCount] = useState(0);

	useInterval(() => {
		setCount((c) => c + 1);
	}, 1000);

	return (
		<>
			<div> count is {count}</div>
		</>
	);
}

function useInterval(fn, timeout) {
	useEffect(() => {
		const interval = setInterval(() => {
			fn();
		}, timeout);
		return () => {
			clearInterval(interval);
		};
	}, []);
}
