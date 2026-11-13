import { useCallback, useEffect, useRef, useState } from 'react';

function App() {
	const divRef = useRef();
	const [incomeTax, setIncomeTax] = useState(20000);

	useEffect(() => {
		setTimeout(() => {
			// document.getElementById('incomeTaxContainer').innerHTML = 10;
			divRef.current.innerHTML = 10;
		}, 5000);
	}, []);

	return (
		<div>
			hi there, your income tax returns are <div ref={divRef}>{incomeTax}</div>
			{/* hi there, your income tax returns are
			<div id="incomeTaxContainer">{incomeTax}</div> */}
		</div>
	);
}

export default App;
