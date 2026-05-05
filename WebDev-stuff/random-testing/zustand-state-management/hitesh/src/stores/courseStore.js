import { create } from 'zustand';

/*
README (Data Flow Overview)
1) UI components call Zustand ACTIONS (for example: fetchCourses, addCourse, updateCourse, deleteCourse).
2) Each ACTION updates store state with set(...). Components that SUBSCRIBE to changed values re-render automatically.
3) Async work is simulated with setTimeout to mimic backend latency.
4) We use optimistic updates for create/update/delete: update UI first, then confirm with mock API, then rollback if API fails.
5) Components consume state with selectors like (state) => state.courses to avoid unnecessary re-renders.
*/

// This helper simulates network latency and optional failures so we can demonstrate loading/error handling.
const mockApi = ({ delay = 700, shouldFail = false, payload = null }) =>
	new Promise((resolve, reject) => {
		setTimeout(() => {
			if (shouldFail) {
				reject(new Error('Mock API failed. Try again.'));
				return;
			}
			resolve(payload);
		}, delay);
	});

// A small starter dataset so the user sees data immediately after the initial fetch.
const seedCourses = [
	{
		id: 1,
		title: 'React Fundamentals',
		description: 'Learn components, props, state, and JSX basics.',
		durationInHours: 12,
		instructor: 'Ava Stone',
		price: 99,
	},
	{
		id: 2,
		title: 'Zustand State Management',
		description: 'Understand stores, selectors, actions, and async patterns.',
		durationInHours: 8,
		instructor: 'Noah Reed',
		price: 79,
	},
];

// This is the single Zustand store for the entire Courses feature.
export const useCourseStore = create((set, get) => ({
	// Core state requested in your requirements.
	courses: [],
	selectedCourse: null,
	isLoading: false,
	error: null,

	// Derived/computed state example: stored as getters/actions for educational clarity.
	getTotalCourses: () => get().courses.length,
	getTotalRevenue: () =>
		get().courses.reduce((sum, course) => sum + Number(course.price || 0), 0),

	// This ACTION loads the initial list from the mock API.
	fetchCourses: async () => {
		// Start loading and clear old errors before the request starts.
		set({ isLoading: true, error: null });

		try {
			const result = await mockApi({ delay: 900, payload: seedCourses });

			// Commit server result into global store state.
			set({ courses: result, isLoading: false });
		} catch (error) {
			// Capture readable error text so UI can show feedback.
			set({ error: error.message, isLoading: false });
		}
	},

	// This ACTION marks one course as selected for edit/detail view.
	selectCourse: (courseId) => {
		const match =
			get().courses.find((course) => course.id === courseId) || null;
		set({ selectedCourse: match });
	},

	// This ACTION clears selected course so form returns to create mode.
	clearSelectedCourse: () => {
		set({ selectedCourse: null });
	},

	// CREATE with optimistic update.
	addCourse: async (newCourseInput) => {
		const previousCourses = get().courses;

		// Generate a client id immediately for optimistic UI rendering.
		const optimisticCourse = {
			id: Date.now(),
			...newCourseInput,
		};

		// Optimistically update UI first.
		set({
			courses: [optimisticCourse, ...previousCourses],
			isLoading: true,
			error: null,
		});

		try {
			// Simulate success/failure. Use title containing "fail" to test rollback behavior.
			await mockApi({
				delay: 700,
				shouldFail: optimisticCourse.title.toLowerCase().includes('fail'),
				payload: optimisticCourse,
			});

			// Keep optimistic state on success; just stop loading.
			set({ isLoading: false });
		} catch (error) {
			// Rollback to previous snapshot if request fails.
			set({
				courses: previousCourses,
				isLoading: false,
				error: error.message,
			});
		}
	},

	// UPDATE with optimistic update.
	updateCourse: async (courseId, updatedFields) => {
		const previousCourses = get().courses;

		// Create the optimistic next state in memory.
		const nextCourses = previousCourses.map((course) =>
			course.id === courseId ? { ...course, ...updatedFields } : course,
		);

		// Immediately render updated values.
		set({ courses: nextCourses, isLoading: true, error: null });

		try {
			const updatedCourse = nextCourses.find(
				(course) => course.id === courseId,
			);
			await mockApi({
				delay: 700,
				shouldFail: updatedCourse?.title?.toLowerCase().includes('fail'),
				payload: updatedCourse,
			});

			// If selected course was edited, sync selectedCourse so detail panel stays accurate.
			const selectedCourse = get().selectedCourse;
			if (selectedCourse?.id === courseId) {
				set({ selectedCourse: { ...selectedCourse, ...updatedFields } });
			}

			set({ isLoading: false });
		} catch (error) {
			// Rollback on failure.
			set({
				courses: previousCourses,
				isLoading: false,
				error: error.message,
			});
		}
	},

	// DELETE with optimistic update.
	deleteCourse: async (courseId) => {
		const previousCourses = get().courses;
		const nextCourses = previousCourses.filter(
			(course) => course.id !== courseId,
		);

		// Optimistically remove from UI.
		set({ courses: nextCourses, isLoading: true, error: null });

		try {
			await mockApi({ delay: 600, payload: true });

			// If deleted course was selected, clear selection to avoid stale detail UI.
			const selectedCourse = get().selectedCourse;
			if (selectedCourse?.id === courseId) {
				set({ selectedCourse: null });
			}

			set({ isLoading: false });
		} catch (error) {
			// Rollback on failure.
			set({
				courses: previousCourses,
				isLoading: false,
				error: error.message,
			});
		}
	},

	// Convenience ACTION to clear error after the user acknowledges it.
	clearError: () => {
		set({ error: null });
	},
}));
