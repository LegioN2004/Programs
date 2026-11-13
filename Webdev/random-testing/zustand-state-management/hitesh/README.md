# zustand

## Intro

Everything is a hook in zustand. Whenever we create a store and it just says a
hook like useStore and we use just that to create a store. A store is a central
place of truth, if any component wants to know the current value of that
particular element it just goes to that store and asks from there.

For creating a store, we just use the `useStore` syntax that we use with react hooks
just like `useState` and `set` to set any variables.

## middleware

Middleware, if we want we can use as you can see in the following example. The
following code is used to persistently store the value of that counter(the one that we get in vite by default) after refreshes.

```js
const useStore = create(
    persist(
        (set) => ({
            count: 0,
            inc: () => set((state) => ({ count: state.count + 1 })),
        }),
        { name: "counter" },
    ),
);

function App() {
    const { count, inc } = useStore();
    return (
        <>
            // ....
            <button onClick={inc}>count is {count}</button>
            // ....
        </>
    );
}

export default App;
```

### Hitesh example

CRUD courses, can be done all from this.

- We will make a courses array, and addCourse will have all the logic to handle
  all those crud operations
- That state variable is responsible for doing any manipulation to this courses
  variable since it's a store variable and state will also have the most updated
  state of that courses variable.
- Then it puts the new `course` that it comes from the `addCourse` argument and
  then the existing value goes in the `courses` store

```js
const courseStore = (set) => ({
    courses: [],
    addCourse: (course) => {
        set((state) => {
            courses: [course, ...state.courses],
        })
    }
})
```

```js
const addCourse = useCourseStore((state) => state.addCourse);
```

The above is being used in the component form. And the cool thing is that it doesn't
affect anything in the other stores or components or states or anything, it just works with what it has got. This store will be attached to work only with this form.

# React + TypeScript + Vite

This template provides a minimal setup to get React working in Vite with HMR and some ESLint rules.

Currently, two official plugins are available:

- [@vitejs/plugin-react](https://github.com/vitejs/vite-plugin-react/blob/main/packages/plugin-react) uses [Babel](https://babeljs.io/) (or [oxc](https://oxc.rs) when used in [rolldown-vite](https://vite.dev/guide/rolldown)) for Fast Refresh
- [@vitejs/plugin-react-swc](https://github.com/vitejs/vite-plugin-react/blob/main/packages/plugin-react-swc) uses [SWC](https://swc.rs/) for Fast Refresh

## React Compiler

The React Compiler is not enabled on this template because of its impact on dev & build performances. To add it, see [this documentation](https://react.dev/learn/react-compiler/installation).

## Expanding the ESLint configuration

If you are developing a production application, we recommend updating the configuration to enable type-aware lint rules:

```js
export default defineConfig([
    globalIgnores(["dist"]),
    {
        files: ["**/*.{ts,tsx}"],
        extends: [
            // Other configs...

            // Remove tseslint.configs.recommended and replace with this
            tseslint.configs.recommendedTypeChecked,
            // Alternatively, use this for stricter rules
            tseslint.configs.strictTypeChecked,
            // Optionally, add this for stylistic rules
            tseslint.configs.stylisticTypeChecked,

            // Other configs...
        ],
        languageOptions: {
            parserOptions: {
                project: ["./tsconfig.node.json", "./tsconfig.app.json"],
                tsconfigRootDir: import.meta.dirname,
            },
            // other options...
        },
    },
]);
```

You can also install [eslint-plugin-react-x](https://github.com/Rel1cx/eslint-react/tree/main/packages/plugins/eslint-plugin-react-x) and [eslint-plugin-react-dom](https://github.com/Rel1cx/eslint-react/tree/main/packages/plugins/eslint-plugin-react-dom) for React-specific lint rules:

```js
// eslint.config.js
import reactX from "eslint-plugin-react-x";
import reactDom from "eslint-plugin-react-dom";

export default defineConfig([
    globalIgnores(["dist"]),
    {
        files: ["**/*.{ts,tsx}"],
        extends: [
            // Other configs...
            // Enable lint rules for React
            reactX.configs["recommended-typescript"],
            // Enable lint rules for React DOM
            reactDom.configs.recommended,
        ],
        languageOptions: {
            parserOptions: {
                project: ["./tsconfig.node.json", "./tsconfig.app.json"],
                tsconfigRootDir: import.meta.dirname,
            },
            // other options...
        },
    },
]);
```
