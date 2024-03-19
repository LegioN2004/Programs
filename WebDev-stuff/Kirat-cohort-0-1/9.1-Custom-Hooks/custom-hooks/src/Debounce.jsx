import { useEffect, useState } from 'react';

function useDebounce(value, timeout) {
	const [debouncedValue, setDebouncedValue] = useState(value);
	useEffect(() => {
		let hello = setTimeout(() => {
			setDebouncedValue(value);
			console.log(value);
		}, timeout);
		return () => {
			clearTimeout(hello);
		};
	}, [value]);
}

export const Debounce = () => {
	const [inputValue, setInputValue] = useState('');
	const debouncedValue = useDebounce(inputValue, 500); // 500 milliseconds debounce delay

	// Use the debouncedValue in your component logic, e.g., trigger a search API call via a useEffect

	return (
		<>
			debouncedValue is {debouncedValue}
			<input
				type="text"
				value={inputValue}
				onChange={(e) => setInputValue(e.target.value)}
				placeholder="Search..."
			/>
		</>
	);
};
