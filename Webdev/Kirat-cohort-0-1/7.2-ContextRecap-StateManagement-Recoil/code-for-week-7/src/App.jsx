import { useContext, useMemo, useState } from 'react';
import {
	RecoilRoot,
	useRecoilState,
	useRecoilValue,
	useSetRecoilState,
} from 'recoil';
import { CountContext } from './context';
// import { countAtom, evenSelector } from "./store/atoms/count";
import { countAtom, evenSelector } from './store/atoms/count';

function App() {
	return (
		<div>
			<RecoilRoot>
				<Count />
			</RecoilRoot>
		</div>
	);
}

function Count() {
	console.log('Count re-rendered');
	return (
		<div>
			<Buttons />
			<CountRenderer />
		</div>
	);
}

function CountRenderer() {
	const count = useRecoilValue(countAtom);

	return (
		<div>
			<b>{count}</b>
			<br />
			<EvenCountRenderer />
			<br />
		</div>
	);
}

function EvenCountRenderer() {
	const isEven = useRecoilValue(evenSelector);
	// not using useMemo instead selectors
	// const isEven = useMemo(
	// 	() =>  (count % 2 == 0 ? `${count} is even` : `${count} is not even`),
	// 	[count]
	// );
	return (
	<div>
	{isEven ? "is even" : null}
	</div>
	)
}

function Buttons() {
	// const [count, setCount] = useRecoilState(countAtom); // don't need this now
	console.log('Buttons re-renedered');
	const setCount = useSetRecoilState(countAtom);

	return (
		<div>
			<button
				onClick={() => {
					setCount((count) => count + 1);
				}}
			>
				Increase
			</button>

			<button
				onClick={() => {
					setCount((count) => count - 1);
				}}
			>
				Decrease
			</button>
		</div>
	);
}

export default App;
