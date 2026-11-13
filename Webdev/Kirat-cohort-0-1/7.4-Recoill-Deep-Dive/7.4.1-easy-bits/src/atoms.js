import { atom, selector } from 'recoil';

export const networkAtom = atom({
	key: 'networkAtom',
	default: 102,
});
export const jobsAtom = atom({
	key: 'jobsAtom',
	default: 0,
});
export const notificationsAtom = atom({
	key: 'notificationsAtom',
	default: 12,
});
export const messagingAtom = atom({
	key: 'messaingAtom',
	default: 0,
});

export const totalNotCount = selector({
    key: "totalNotCount",
    get: ({ get }) => {
        const totalCount = get(networkAtom) + get(notificationsAtom) + get(messagingAtom) + get(jobsAtom)
        return totalCount
    }
})
