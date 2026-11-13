import CourseForm from './components/CourseForm';
import CourseList from './components/CourseList';
import { useCourseStore } from './stores/courseStore';

/*
README (Data Flow in this App)
1) App renders form + list + summary panels.
2) Components read/write the same global Zustand store via useCourseStore selectors.
3) List loads data by calling fetchCourses() in useEffect.
4) Form dispatches addCourse/updateCourse and can clear selectedCourse.
5) CourseCard dispatches selectCourse/deleteCourse.
6) App displays derived values from store (total courses and total revenue).
*/

const App = () => {
	// This line SUBSCRIBES to the store and re-renders when these values change.
	const selectedCourse = useCourseStore((state) => state.selectedCourse);

	// Derived/computed values are exposed by store action-like getters for educational clarity.
	// This line SUBSCRIBES to the store and re-renders when these values change.
	const getTotalCourses = useCourseStore((state) => state.getTotalCourses);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const getTotalRevenue = useCourseStore((state) => state.getTotalRevenue);

	// Evaluate derived values each render. When dependencies in store change, selectors trigger re-render.
	const totalCourses = getTotalCourses();
	const totalRevenue = getTotalRevenue();

	return (
		<main className="min-h-screen bg-slate-50 p-6 md:p-10">
			<div className="mx-auto grid max-w-6xl gap-6">
				<header className="rounded-2xl border border-slate-200 bg-white p-6 shadow-sm">
					<h1 className="text-3xl font-bold tracking-tight text-slate-900">
						Course Manager (Zustand CRUD)
					</h1>
					<p className="mt-2 text-sm text-slate-600">
						Manage course records with clear Zustand patterns: selectors,
						actions, async loading, errors, and optimistic updates.
					</p>

					<div className="mt-4 grid gap-3 md:grid-cols-3">
						<div className="rounded-lg bg-slate-100 p-3">
							<p className="text-xs font-medium uppercase text-slate-500">
								Total Courses
							</p>
							<p className="text-2xl font-semibold text-slate-800">
								{totalCourses}
							</p>
						</div>

						<div className="rounded-lg bg-slate-100 p-3">
							<p className="text-xs font-medium uppercase text-slate-500">
								Total Revenue
							</p>
							<p className="text-2xl font-semibold text-slate-800">
								${totalRevenue}
							</p>
						</div>

						<div className="rounded-lg bg-slate-100 p-3">
							<p className="text-xs font-medium uppercase text-slate-500">
								Selected Course
							</p>
							<p className="text-sm font-medium text-slate-800">
								{selectedCourse ? selectedCourse.title : 'None selected'}
							</p>
						</div>
					</div>
				</header>

				<section className="grid gap-6 lg:grid-cols-2">
					<CourseForm />
					<CourseList />
				</section>
			</div>
		</main>
	);
};

export default App;
