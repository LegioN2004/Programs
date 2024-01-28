import { BrowserRouter, Route, Routes, useNavigate } from 'react-router-dom';
import './App.css';
// lazy load dashboard
import React, { Suspense } from 'react';
// or
const Dashboard = React.lazy(() => import('./OldComponents/Dashboard'));
const Landing = React.lazy(() => import('./OldComponents/Landing'));

function App() {
	return (
		<div>
			<div>this is the navbar</div>
			{/* main routing logic */}
			<BrowserRouter>
				<Routes>
					<Route
						path="/dashboard"
						element={
							<Suspense fallback={'loading ......'}>
								<Dashboard />
							</Suspense>
						}
					/>
					<Route
						path="/"
						element={
							<Suspense fallback={'loading ......'}>
								<Landing />
							</Suspense>
						}
					/>
				</Routes>
				{/* then navigate function called here  */}
				<AppRouter></AppRouter>
			</BrowserRouter>
		</div>
	);
}
// to use navigate properly
function AppRouter() {
	const navigate = useNavigate();
	return (
		<div>
			<button
				onClick={() => {
					navigate('/');
				}}
			>
				landing
			</button>
			<button
				onClick={() => {
					navigate('/dashboard');
				}}
			>
				dashboard
			</button>
		</div>
	);
}

export default App;
