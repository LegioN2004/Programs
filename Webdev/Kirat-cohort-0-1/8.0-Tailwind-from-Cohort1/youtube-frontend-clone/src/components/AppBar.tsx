import { SearchBar } from './SearchBar';

export const AppBar = () => {
	return (
		<div className="flex justify-between pt-2">
			<div className="inline-flex items-center">Youtube Logo</div>
			<div>
				<SearchBar></SearchBar>
			</div>
			<div className="inline-flex items-center">Sign in</div>
		</div>
	);
};
