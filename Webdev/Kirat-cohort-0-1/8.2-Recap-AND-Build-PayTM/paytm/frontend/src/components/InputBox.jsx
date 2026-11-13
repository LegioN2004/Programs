export const InputBox = ({ label, placeholder, onChange }) => {
	return (
		<>
			<div className="p-1">
				<div className="block mb-2 text-bold text-sm font-medium light:text-white text-black">
					{label}
				</div>
				<input
					type="text"
					onChange={onChange}
					placeholder={placeholder}
					className="w-full bg-gray-50 border border-gray-300 text-gray-900 text-sm block p-2 rounded-sm border-b-1 my-2"
				></input>
			</div>
		</>
	);
};
