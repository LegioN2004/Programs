import "./Column.css";
import Task from "./Task";

export default function Column({ state }) {
    return (
        <div className="column">
            <p>{state}</p>
            <Task title="todo" />
        </div>
    );
}
