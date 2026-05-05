import { useCourseStore } from '../stores/courseStore';

const CourseCard = ({ course }) => {
	// This line SUBSCRIBES to the store and re-renders when these values change.
	const selectCourse = useCourseStore((state) => state.selectCourse);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const deleteCourse = useCourseStore((state) => state.deleteCourse);

	return (
		<article className="rounded-xl border border-slate-200 bg-white p-4 shadow-sm transition hover:shadow-md">
			<div className="mb-3 flex items-start justify-between gap-3">
				<h3 className="text-lg font-semibold text-slate-800">{course.title}</h3>
				<span className="rounded-full bg-slate-100 px-2 py-1 text-xs font-medium text-slate-600">
					{course.durationInHours}h
				</span>
			</div>

			<p className="mb-3 text-sm text-slate-600">{course.description}</p>

			<div className="mb-4 grid grid-cols-2 gap-2 text-sm text-slate-700">
				<p>
					<span className="font-medium">Instructor:</span> {course.instructor}
				</p>
				<p>
					<span className="font-medium">Price:</span> ${course.price}
				</p>
			</div>

			<div className="flex gap-2">
				<button
					type="button"
					className="rounded-md bg-blue-600 px-3 py-2 text-sm font-medium text-white hover:bg-blue-700"
					onClick={() => {
						// This is a Zustand ACTION - it can mutate state directly through set(...).
						selectCourse(course.id);
					}}
				>
					Edit
				</button>

				<button
					type="button"
					className="rounded-md bg-rose-600 px-3 py-2 text-sm font-medium text-white hover:bg-rose-700"
					onClick={() => {
						// This is a Zustand ACTION - it can mutate state directly through set(...).
						deleteCourse(course.id);
					}}
				>
					Delete
				</button>
			</div>
		</article>
	);
};

export default CourseCard;
