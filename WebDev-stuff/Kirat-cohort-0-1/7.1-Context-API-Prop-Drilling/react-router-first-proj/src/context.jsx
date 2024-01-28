import { createContext } from 'react';

// this is the teleport thing that we have created
export const CountContext = createContext({
	count: 0,
	setCount: () => {} 
});
