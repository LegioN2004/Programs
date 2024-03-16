import axios from 'axios';
import { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { Button } from './Button';

export const Users = ({ balance }) => {
	const [users, setUsers] = useState([]);
	const [search, setSearch] = useState('');

	useEffect(() => {
		axios
			.get('http://localhost:3000/api/v1/user/bulk?filter=' + search)
			.then((response) => {
				setUsers(response.data.user);
			});
	}, [search]);

	// return (
	// 	<>
	// 		<div className="relative pt-5 pl-6">
	// 			<h2 className="text-2xl font-bold text-gray-800 pt-5">
	// 				Your balance: &nbsp;₹{balance}
	// 			</h2>
	// 			<h2 className="text-2xl font-bold text-gray-800 pt-5">Users</h2>
	// 			<div className="pr-6">
	// 				<input
	// 					placeholder="Search for users"
	// 					onChange={(e) => {
	// 						setSearch(e.target.value);
	// 					}}
	// 					className="w-full bg-gray-50 border border-gray-300 text-gray-900 text-sm block p-2 rounded-md border-b-1 my-2"
	// 				></input>
	// 			</div>
	// 			<div>
	// 				{users.map((user) => {
	// 					<User user={user} />;
	// 				})}
	// 			</div>
	// 		</div>
	// 	</>
	// );

	return (
		<>
			<h2 className="text-xl font-bold text-gray-800 pt-5">
				Your balance: &nbsp;₹{balance}
			</h2>
			<div className="font-bold mt-6 text-lg">Users</div>
			<div className="my-2">
				<input
					onChange={(e) => {
						setSearch(e.target.value);
					}}
					type="text"
					placeholder="Search users..."
					className="w-full px-2 py-1 border rounded border-slate-200"
				></input>
			</div>
			<div>
				{users.map((user) => (
					<User user={user} />
				))}
			</div>
		</>
	);
};

function User({ user }) {
	const navigate = useNavigate();
	return (
		<>
			<div className="flex justify-between">
				<div className="flex">
					<div className="rounded-full h-12 w-12 bg-slate-200 flex justify-center mt-1 mr-2">
						<div className="flex flex-col justify-center h-full text-xl">
							{user.firstName[0]}
						</div>
					</div>
					<div className="flex flex-col justify-center h-ful">
						<div>
							{user.firstName} {user.lastName}
						</div>
					</div>
				</div>

				<div className="flex flex-col justify-center h-ful">
					<Button
						onClick={(e) => {
							navigate('/send?id=' + user.id + '&name=' + user.firstName);
						}}
						label={'Send Money'}
					/>
				</div>
			</div>
		</>
	);
}
