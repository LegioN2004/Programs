import { Link } from 'react-router-dom'; // link lets us go from one place to another using the `to` attribute

export const BottomWarning = ({ label, buttonText, to }) => {
	return (
		<div className="py-2 text-sm flex justify-center">
			<div>{label}</div>
			<Link
				onClick={'/'}
				className="text-blue-500 underline pointer pl-3"
				to={to}
			>
				{buttonText}
			</Link>
		</div>
	);
};
