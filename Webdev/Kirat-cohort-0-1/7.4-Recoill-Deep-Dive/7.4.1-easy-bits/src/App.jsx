import { useMemo } from 'react';
import { RecoilRoot, useRecoilValue, useSetRecoilState } from 'recoil';
import './App.css';
import {
	jobsAtom,
	messagingAtom,
	networkAtom,
	notificationsAtom,
	totalNotCount,
} from './atoms';
//RecoilRoot

function App() {
	return (
		<>
			<RecoilRoot>
				<MainApp></MainApp>
			</RecoilRoot>
		</>
	);
}

function MainApp() {
	const networkCount = useRecoilValue(networkAtom);
	const jobsCount = useRecoilValue(jobsAtom);
	const messageCount = useRecoilValue(messagingAtom);
	const notificationCount = useRecoilValue(notificationsAtom);
	const totalNotificationCount = useMemo(() => {
		return networkCount + jobsCount + messageCount + notificationCount;
	}, [networkCount, jobsCount, messageCount, notificationCount]);

	const selectorTotalCount = useRecoilValue(totalNotCount);

	return (
		<>
			<button>Home</button>

			<button>My Network ({networkCount >= 100 ? '99+' : networkCount})</button>
			<button>Jobs ({jobsCount >= 100 ? '99+' : jobsCount})</button>
			<button>Messaging ({messageCount >= 100 ? '99+' : messageCount})</button>
			<button>
				Notifications ({notificationCount >= 100
					? '99+'
					: notificationCount}){' '}
			</button>

			<button>
				ME (stateWalaCount{totalNotificationCount}) (selectorCount{selectorTotalCount})
			</button>
		</>
	);
}

//  logic to update when we have a backend
function MessageButton() {
	const setMessageCount = useSetRecoilState(messagingAtom);
	return (
		<button
			onClick={() => {
				setMessageCount((c) => c + 1);
			}}
		>
			Me
		</button>
	);
}

export default App;
