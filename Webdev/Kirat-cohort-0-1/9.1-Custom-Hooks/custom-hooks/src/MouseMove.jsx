import { useEffect, useState } from 'react';
export function MouseMove() {
	const mousePointer = useMousePointer();
	return (
		<>
			<div>
				x is {mousePointer.x} and y is {mousePointer.y}{' '}
			</div>
		</>
	);
}

function useMousePointer() {
	const [mouse, setMouse] = useState({ x: 0, y: 0 });

	const handleMouseMove = (e) => {
		setMouse({ x: e.clientX, y: e.clientY });
	};
	useEffect(() => {
		window.addEventListener('mousemove', handleMouseMove);
		return () => {
			window.addEventListener('mousemove', handleMouseMove);
		};
	}, []);
	return mouse;
}
