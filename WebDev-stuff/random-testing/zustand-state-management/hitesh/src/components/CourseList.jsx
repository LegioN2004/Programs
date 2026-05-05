import { useEffect } from 'react';
import { useCourseStore } from '../stores/courseStore';
import CourseCard from './CourseCard';

const CourseList = () => {
	// This line SUBSCRIBES to the store and re-renders when these values change.
	// Selector pattern: we subscribe to only the courses array.
	const courses = useCourseStore((state) => state.courses);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const isLoading = useCourseStore((state) => state.isLoading);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const error = useCourseStore((state) => state.error);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const fetchCourses = useCourseStore((state) => state.fetchCourses);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const clearError = useCourseStore((state) => state.clearError);

	useEffect(() => {
		// useEffect + Zustand integration:
		// On first component mount, call the store action to load initial data.
		// Zustand automatically tracks dependencies - no useCallback needed for store actions here.
		fetchCourses();
	}, [fetchCourses]);

	return (
		<section className="rounded-2xl border border-slate-200 bg-white p-5 shadow-sm">
			<div className="mb-4 flex items-center justify-between">
				<h2 className="text-xl font-semibold text-slate-800">All Courses</h2>
				{isLoading && (
					<span className="text-sm text-slate-500">Syncing...</span>
				)}
			</div>

			{error && (
				<div className="mb-4 rounded-md border border-rose-200 bg-rose-50 p-3 text-sm text-rose-700">
					<p className="mb-2">{error}</p>
					<button
						type="button"
						onClick={clearError}
						className="rounded bg-rose-600 px-3 py-1 font-medium text-white hover:bg-rose-700"
					>
						Dismiss
					</button>
				</div>
			)}

			{courses.length === 0 && !isLoading ? (
				<p className="text-sm text-slate-500">
					No courses yet. Add one from the form.
				</p>
			) : (
				<div className="grid gap-3">
					{courses.map((course) => (
						<CourseCard key={course.id} course={course} />
					))}
				</div>
			)}
		</section>
	);
};

export default CourseList;
