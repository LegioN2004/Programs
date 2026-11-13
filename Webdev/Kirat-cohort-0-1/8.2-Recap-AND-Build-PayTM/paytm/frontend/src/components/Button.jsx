export const Button = ({ label, onClick }) => {
	return (
		<>
			<button
				onClick={onClick}
				className="text-white bg-gray-800 hover:bg-gray-900 font-medium rounded-lg text-sm w-full p-2 me-2 mb-2"
			>
				{label}
			</button>
		</>
	);
};
