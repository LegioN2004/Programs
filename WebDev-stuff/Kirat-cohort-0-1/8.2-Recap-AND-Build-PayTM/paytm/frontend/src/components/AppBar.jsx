export const AppBar = () => {
	return (
		<>
			<div className="flex h-18 justify-between bg-white p-3 shadow-md">
				<div>
					<h1 className="text-2xl font-bold text-gray-800 ">Nakli-PayTM</h1>
				</div>
				<div className="flex">
					<div className="pt-4 px-2 font-semibold">Hello, User</div>
					<img
						className="w-10 h-10 rounded-full justify-end"
						src="https://images.unsplash.com/photo-1682407186023-12c70a4a35e0?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=2832&q=80"
						alt="Rounded avatar"
					/>
				</div>
			</div>
		</>
	);
};
