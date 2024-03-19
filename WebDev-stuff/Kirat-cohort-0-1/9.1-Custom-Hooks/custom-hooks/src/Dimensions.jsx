import { useEffect, useState } from 'react';

export function Dimensions() {
	const { height, width } = useDimension();
	return (
		<>
			<div>
				your height is {height} and width is {width}
			</div>
		</>
	);
}

function useDimension() {
	const [height, setHeight] = useState(window.innerHeight);
	const [width, setWidth] = useState(window.innerWidth);
	useEffect(() => {
		window.addEventListener('resize', () => {
			setHeight(window.innerHeight);
		});
		window.addEventListener('resize', () => {
			setWidth(window.innerWidth);
		});
		return () => {
			window.addEventListener('resize', () => {
				setHeight(window.innerHeight);
			});
			window.addEventListener('resize', () => {
				setWidth(window.innerWidth);
			});
		};
	}, [height, width]);
	return { height, width };
}
