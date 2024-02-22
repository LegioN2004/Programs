# Tailwind more practice

Things done till now are the Tailwind youtube clone done with react, tailwind, TS and react. In this we'll be creating a "dukaan", a startup's frontend clone with responsiveness

## The starting basics

These stuff regarding flex, grids, responsiveness, etc are already done using tailwindCSS, so we need to just setup tailwind in the project by just following the documentation which is how we'll do for most projects be it production or company or something else. For the first part we'll just install tailwind in the vite project by following the vite specific commands in the docs.

```bash
npm install -D tailwindcss postcss autoprefixer
npx tailwindcss init -p
```

After we enter these commands, then we'll get a tailwind specific file which is the config file for setting up some defaults or some other stuff that you would like to apply to the styling since tailwindCSS comes with some sane defaults initially but it works most of the time.

So you'll need to add the following lines of code to the generated tailwind.config.js file(if not generated create one) and also

```js
/** @type {import('tailwindcss').Config} */
export default {
  content: ["./index.html", "./src/**/*.{js,ts,jsx,tsx}"],
  theme: {
    extend: {},
  },
  plugins: [],
};
```

the following lines of code to the index.css file as well to setup tailwind in your vite project. Or else tailwind will not apply styling to the project.

```css
@tailwind base;
@tailwind components;
@tailwind utilities;
```

So in the config file, it is a json type file where in the content key we'll need to set the files like in our case it'll be the files with the extensions `.js, .ts, .jsx, .tsx` which tailwind will apply the styling to so tailwind will watch those files.

- The mobile-first approach: Since it follows the mobile-first approach we'll see the main unprefixed ones (like say `bg-red-500`) will apply globally to all devices but the mobile ones i.e small size(but we don't see it because by default our comp screen is big) and the prefixed ones (like `md:bg-blue-500`) styling will apply only when the screen width changes to that breakpoint and above(in our case comp screen is big, so reduce to mobile size and then increase it till the md breakpoint and see). So anything above 640px, only then the `sm:grid-cols-1` will take effect(and so on) or else the unprefixed one will apply the styling globally to all the mobile i.e small screen devices.
