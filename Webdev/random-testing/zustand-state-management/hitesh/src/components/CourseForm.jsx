import { useEffect, useState } from 'react';
import { useCourseStore } from '../stores/courseStore';

// We keep one reusable empty shape so reset logic is easy to read and maintain.
const emptyForm = {
	title: '',
	description: '',
	durationInHours: '',
	instructor: '',
	price: '',
};

const CourseForm = () => {
	// This line SUBSCRIBES to the store and re-renders when these values change.
	const selectedCourse = useCourseStore((state) => state.selectedCourse);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const isLoading = useCourseStore((state) => state.isLoading);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const addCourse = useCourseStore((state) => state.addCourse);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const updateCourse = useCourseStore((state) => state.updateCourse);

	// This line SUBSCRIBES to the store and re-renders when these values change.
	const clearSelectedCourse = useCourseStore(
		(state) => state.clearSelectedCourse,
	);

	// Local component state is used only for form input control (not global shared state).
	const [formData, setFormData] = useState(emptyForm);

	useEffect(() => {
		// This useEffect integration demonstrates reading Zustand state and syncing local UI state.
		// When selectedCourse changes in the store, we switch between edit-mode values and create-mode defaults.
		if (selectedCourse) {
			setFormData({
				title: selectedCourse.title,
				description: selectedCourse.description,
				durationInHours: String(selectedCourse.durationInHours),
				instructor: selectedCourse.instructor,
				price: String(selectedCourse.price),
			});
			return;
		}

		setFormData(emptyForm);
	}, [selectedCourse]);

	const handleChange = (event) => {
		const { name, value } = event.target;

		// Update exactly one field by name while preserving all other form fields.
		setFormData((previous) => ({
			...previous,
			[name]: value,
		}));
	};

	const handleSubmit = async (event) => {
		event.preventDefault();

		// Prepare normalized values before calling store actions.
		const payload = {
			title: formData.title.trim(),
			description: formData.description.trim(),
			durationInHours: Number(formData.durationInHours),
			instructor: formData.instructor.trim(),
			price: Number(formData.price),
		};

		// Basic guard so we do not send incomplete records.
		if (!payload.title || !payload.description || !payload.instructor) {
			return;
		}

		if (selectedCourse) {
			// This is a Zustand ACTION - it can mutate state directly through set(...).
			await updateCourse(selectedCourse.id, payload);
			// After update, return to create mode.
			clearSelectedCourse();
			return;
		}

		// This is a Zustand ACTION - it can mutate state directly through set(...).
		await addCourse(payload);
		setFormData(emptyForm);
	};

	return (
		<section className="rounded-2xl border border-slate-200 bg-white p-5 shadow-sm">
			<h2 className="mb-4 text-xl font-semibold text-slate-800">
				{selectedCourse ? 'Edit Course' : 'Create Course'}
			</h2>

			<form className="grid gap-3" onSubmit={handleSubmit}>
				<input
					name="title"
					value={formData.title}
					onChange={handleChange}
					placeholder="Course title"
					className="rounded-md border border-slate-300 px-3 py-2 text-slate-800 outline-none focus:border-blue-500"
				/>

				<textarea
					name="description"
					value={formData.description}
					onChange={handleChange}
					placeholder="Course description"
					rows={3}
					className="rounded-md border border-slate-300 px-3 py-2 text-slate-800 outline-none focus:border-blue-500"
				/>

				<input
					name="durationInHours"
					type="number"
					min="1"
					value={formData.durationInHours}
					onChange={handleChange}
					placeholder="Duration (hours)"
					className="rounded-md border border-slate-300 px-3 py-2 text-slate-800 outline-none focus:border-blue-500"
				/>

				<input
					name="instructor"
					value={formData.instructor}
					onChange={handleChange}
					placeholder="Instructor"
					className="rounded-md border border-slate-300 px-3 py-2 text-slate-800 outline-none focus:border-blue-500"
				/>

				<input
					name="price"
					type="number"
					min="0"
					value={formData.price}
					onChange={handleChange}
					placeholder="Price (USD)"
					className="rounded-md border border-slate-300 px-3 py-2 text-slate-800 outline-none focus:border-blue-500"
				/>

				<div className="mt-1 flex gap-2">
					<button
						type="submit"
						disabled={isLoading}
						className="rounded-md bg-emerald-600 px-4 py-2 text-sm font-medium text-white hover:bg-emerald-700 disabled:cursor-not-allowed disabled:opacity-60"
					>
						{selectedCourse ? 'Update Course' : 'Add Course'}
					</button>

					<button
						type="button"
						onClick={() => {
							setFormData(emptyForm);
							clearSelectedCourse();
						}}
						className="rounded-md bg-slate-200 px-4 py-2 text-sm font-medium text-slate-700 hover:bg-slate-300"
					>
						Reset
					</button>
				</div>
			</form>
		</section>
	);
};

export default CourseForm;
