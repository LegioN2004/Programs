# YouTube clone in React from scratch using Tailwind

This is a recap class from Cohort 1 of understanding react and next.js by cloning the frontend of YouTube using Next.js and Tailwind as the styling library.

## Four important things we must know in a frontend framework

1. Flex
2. Grids
3. Responsiveness
4. Small things like: bg color, text color, changes styles on hover, etc

These things will make you framework agnostic

### Flex

If we set a parent div and children divs inside it then we get the divs one below the other, flex just makes the divs come next to each other side by side in the same line

Then the properties:

- justify-content: given that the children are in the same line, using flex how should we position them. The values are

1. **`flex-start`:**

   - Aligns items to the start of the container.
   - Children are positioned at the beginning of the main axis.

2. **`flex-end`:**

   - Aligns items to the end of the container.
   - Children are positioned at the end of the main axis.

3. **`center`:**

   - Aligns items at the center of the container.
   - Children are centered along the main axis.

4. **`space-between`:**

   - Distributes space evenly between items.
   - First item is at the start, and the last item is at the end.

5. **`space-around`:**

   - Distributes space evenly around items.
   - Equal space on both sides of each item.

6. **`space-evenly`:**
   - Distributes space evenly around and between items.
   - Equal space on both sides of each item and at the start and end.

Remember, these values apply to the main axis, which is determined by the `flex-direction` property. They control the alignment of items within a flex container along the main axis.

#### The way we do these in Tailwind

```jsx
export default function Test(){
return(
    <div style={{background: "flex"; justifyContent: "space-between";}}>
    <div style={{background: "red";}}>
    hi from red div
    </div>
    <div style={{background: "green";}}>

    hi from green div
    </div>
    <div style={{background: "blue";}}>

    hi from blue div
    </div>
    </div>

)
}
```

instead of using the above xml style(nearly html style CSS), we can use the following tailwind style css which includes adding the styles inside the `classNames` in case of 'jsx' and then adding inside the quotes `classNames="flex justify-between"`, defined in `class` in case of 'html' and normal 'css' like `class="justify-between"`. So in tailwind we have something like `justify-content: space-between` which is equivalent to `justify-between`, they're just shorthand named like this and there are a lot of others too, not possible to remember all of that, just google it on the go. And the colors have some rating with numbers for their intensity maybe.

```jsx
export default function Test() {
  return (
    <div className="flex justify-between">
      <div className="bg-red-700">hi from red div</div>
      <div className="bg-green-700">hi from green div</div>
      <div className="bg-blue-700">hi from blue div</div>
    </div>
  );
}
```

## Grids

Another way to make the divs come next to each other side by side is by using grids. There are many properties of grids and we can add them using the same `className="grid grid-cols-3"`(which is the same as flex and justify-between property to make the divs come side by side and and take equal spaces) on the parent such that the children under the parent div gets all the grid property applied to it.

- The number after cols part says the number of columns that you may have, and if you may see blank spaces if you give a higher number of grids columns and if there are not any div colored for that no of grids
- The `grid-cols-3` means that we will have 3 columns and they will take 3 spaces and if we add more number of cols then in the grid there will be more columns and they'll be adjusted accordingly with equal spaces.
- If we want to make the columns take different amount of spaces according to the no of columns defined like `grid-cols-12`, then we can do something like this in the children divs to take the no of columns as its own space by adding numbers after span like this `col-span-5`, and so this div will take 5 of the 12 columns that are present in the parent div. Similarly the rest of the two will take 5 and 2 respectively

```jsx
export default function Test() {
  return (
    <div className="grid gap-4 grid-cols-3">
      <div className="col-span-5" style={{ background: "green" }}>
        {" "}
        // this guy takes five columns space hi from green div
      </div>
      <div className="col-span-5" style={{ background: "red" }}>
        {" "}
        // this guy takes five columns space hi from red div
      </div>
      <div className="col-span-2" style={{ background: "pink" }}>
        {" "}
        // this guy takes two columns space hi from pink div
      </div>
    </div>
  );
}
```

## Responsiveness

Now we have just defined the max no of columns that will be present in the main div, but we'll have to change that based on the size of the current window just like youtube does when we resize the window it reduces the cards from mainly 4 to 3 to then 2 and lastly 1.

Tailwind does this using breakpoints: Using responsive utility variants to build adaptive user interfaces. ​
Every utility class in Tailwind can be applied conditionally at different breakpoints, i.e there are some points/line defined at the dom where after or before the line there'll be different CSS and that breakpoints are the ones described below

There are five breakpoints(popular ones) by default, inspired by common device resolutions:

| Breakpoint prefix | Minimum width | CSS                         |
| ----------------- | ------------- | --------------------------- |
| `sm`              | 640px         | (min-width: 640px) { ... }  |
| `md`              | 768px         | (min-width: 768px) { ... }  |
| `lg`              | 1024px        | (min-width: 1024px) { ... } |
| `xl`              | 1280px        | (min-width: 1280px) { ... } |
| `2xl`             | 1536px        | (min-width: 1536px) { ... } |

To add a utility but only have it take effect at a certain breakpoint, all you need to do is prefix the utility with the breakpoint name, followed by the : character:

```html
<!-- Width of 16 by default, 32 on medium screens, and 48 on large screens -->
<img class="w-16 md:w-32 lg:w-48" src="..." />
```

This works for every utility class in the framework, which means you can change literally anything at a given breakpoint — even things like letter spacing or cursor styles.

The Tailwind does things mobile-first fashion/breakpoint system. So by default, Tailwind uses a mobile-first breakpoint system, similar to what we might be used to in other frameworks like Bootstrap.

What this means is that unprefixed utilities (like uppercase) take effect on all screen sizes, while prefixed utilities (like md:uppercase) only take effect at the specified breakpoint and above.

- meaning of the above para with more clarity

**Targeting mobile screens**

Where this approach surprises people most often is that to style something for mobile, you need to use the unprefixed version of a utility, not the sm: prefixed version. Don’t think of sm: as meaning “on small screens”, think of it as “at the small breakpoint“.

_Don’t use `sm`: to target mobile devices_

```html
<!-- This will only center text on screens 640px and wider, not on small screens -->
<div class="sm:text-center"></div>
```

Use unprefixed utilities to target mobile, and override them at larger breakpoints. What the line means is that we shouldn't target small screen directly for responsiveness in the tailwind usecase, instead we can make it default to `text-center` for mobile devices and then when the window crosses the `sm` breakpoint(bigger than mobile screen) then the next style will kick in which does the `text-left`.

The above wrong example `sm:text-center` does the opposite, i.e making the text centered when the screen is greater than the small breakpoint and then not centered when big screen

```html
<!-- This will center text on mobile, and left align it on screens 640px and wider -->
<div class="text-center sm:text-left"></div>
```

For this reason, it’s often a good idea to implement the mobile layout for a design first, then layer on any changes that make sense for sm screens, followed by md screens, etc

#### Way to make the divs responsive

Use `col-span-12` so that in a 12 col grid, the space taken by the columns are 12 spaced by defualt when they don't pass the `md` breakpoint and if passed then the `col-span-5` becomes 5 spaced for the first two and 2 for the third. So the syntax for the `md` break point will have the one that should stay like that until the screen size becomes small `md:col-span-5` (or something else) and the one sizing property outside is the one which will be when the window passes the md breakpoint, kind of a reverse input(maybe)

```jsx
export default function Test() {
  return (
    <div className="grid grid-cols-12">
      <div
        className="col-span-12 md:col-span-5"
        style={{ background: "green" }}
      >
        // this guy takes five columns space hi from green div
      </div>
      <div className="col-span-12 md:col-span-5" style={{ background: "red" }}>
        // this guy takes five columns space hi from red div
      </div>
      <div className="col-span-12 md:col-span-2" style={{ background: "pink" }}>
        // this guy takes two columns space hi from pink div
      </div>
    </div>
  );
}
```

#### Tailwind Color System

Tailwind includes an expertly-crafted default color palette out-of-the-box that is a great starting point if you don’t have your own specific branding in mind.

They have a very big range of colors ranging from 50th shade and to 950th shade and we can use them by using these values which represent intesity w.r.t the colors and also we can define them ourselves eg: the 50th shade red should be something else rather than the default value. There is a config file where we can define these parameters and usually the by default provided colors are good enough for most usecases.

Now how to use them is a little similar to the normal CSS but tailwind uses some kind of abbreviations or short form for the properties

```jsx
// vanilla CSS way of doing colors
export default function Test() {
  return (
    <div style={{background: "green"; color: "red";}}>
    Hi there from the first div
    </div>
  );
}

// Tailwind CSS way of doing colors
export default function Test() {
  return (
    <div className="bg-green-500 text-red-500">
    Hi there from the first div
    </div>
  );
}
```

So the above two examples show the differences between the vanilla CSS way of doing styling and the Tailwind way of doing styling. And the TW does the `bg-green-500` bg=background, green = green color, and green-500 = 500th shade of the green color palette, so this line picks the 500th shade/variant of the green color for the background. And the `text-red-500` does the same with picking the 500th shade of the red color palette and applying it to the text.

#### text sizing

The text sizing works in a different manner where like the breakpoints we have the text size defaults already set up by the tailwind devs but if we want to change the defaults then we'll need to change the config file.
Utilities for controlling the font size of an element. Below are the utilities which are the defaults for setting up sizes and their equivalent css are written under the properties heading

Quick reference
| Class    | Properties                          |
|----------|-------------------------------------|
| text-xs  | font-size: 0.75rem;                 |
|          | line-height: 1rem;                  |
| text-sm  | font-size: 0.875rem;                |
|          | line-height: 1.25rem;               |
| text-base| font-size: 1rem;                    |
|          | line-height: 1.5rem;                |
| text-lg  | font-size: 1.125rem;                |
|          | line-height: 1.75rem;               |
| text-xl  | font-size: 1.25rem;                 |
|          | line-height: 1.75rem;               |
| text-2xl | font-size: 1.5rem;                  |
|          | line-height: 2rem;                  |
| text-3xl | font-size: 1.875rem;                |
|          | line-height: 2.25rem;               |
| text-4xl | font-size: 2.25rem;                 |
|          | line-height: 2.5rem;                |
| text-5xl | font-size: 3rem;                    |
|          | line-height: 1;                     |
| text-6xl | font-size: 3.75rem;                 |
|          | line-height: 1;                     |
| text-7xl | font-size: 4.5rem;                  |
|          | line-height: 1;                     |
| text-8xl | font-size: 6rem;                    |
|          | line-height: 1;                     |
| text-9xl | font-size: 8rem;                    |
|          | line-height: 1;                     |

#### Tailwind border radius

The following are the Utilities for controlling the border radius of an element.

| Class           | Properties                |
|-----------------|---------------------------|
| rounded-none    | border-radius: 0;         |
| rounded-sm      | border-radius: 0.125rem;  |
| rounded         | border-radius: 0.25rem;   |
| rounded-md      | border-radius: 0.375rem;  |
| rounded-lg      | border-radius: 0.5rem;    |
| rounded-xl      | border-radius: 0.75rem;   |
| rounded-2xl     | border-radius: 1rem;      |
| rounded-3xl     | border-radius: 1.5rem;    |
| rounded-full    | border-radius: 9999px;    |

Important ones are `rounded`, `rounded-md`, `rounded-lg`, `rounded-full` to apply different border radius sizes to an element.

1. **rounded-none**: Removes all border-radius, resulting in sharp corners.

   ```html
   <div class="rounded-none p-4 bg-gray-200">No rounded corners</div>
   ```

2. **rounded-sm**: Applies a small border-radius, making the corners slightly rounded.

   ```html
   <div class="rounded-sm p-4 bg-gray-200">Slightly rounded corners</div>
   ```

3. **rounded**: Applies a default border-radius, providing a moderate amount of rounding to the corners.

   ```html
   <div class="rounded p-4 bg-gray-200">Moderate rounded corners</div>
   ```

4. **rounded-md**: Applies a medium border-radius, offering more rounding compared to the default `rounded` class.

   ```html
   <div class="rounded-md p-4 bg-gray-200">Medium rounded corners</div>
   ```

5. **rounded-lg**: Applies a large border-radius, resulting in significantly rounded corners.

   ```html
   <div class="rounded-lg p-4 bg-gray-200">Large rounded corners</div>
   ```

6. **rounded-xl**: Applies an extra-large border-radius, offering even more rounding to the corners.

   ```html
   <div class="rounded-xl p-4 bg-gray-200">Extra-large rounded corners</div>
   ```

7. **rounded-2xl**: Applies a very large border-radius, providing even more rounding compared to `rounded-xl`.

   ```html
   <div class="rounded-2xl p-4 bg-gray-200">Very large rounded corners</div>
   ```

8. **rounded-3xl**: Applies an extremely large border-radius, resulting in highly rounded corners.

   ```html
   <div class="rounded-3xl p-4 bg-gray-200">Extremely large rounded corners</div>
   ```

9. **rounded-full**: Applies a border-radius of 9999px, effectively creating a circular shape.

   ```html
   <div class="rounded-full h-24 w-24 bg-gray-200 flex items-center justify-center">Circular shape</div>
   ```

These examples demonstrate how different `border-radius` utility classes in Tailwind CSS affect the corners of elements, allowing you to achieve various styles and shapes.

## Onto the main assignment, YouTube frontend clone

It is generally a good thing to make individual components and then at the end glue them all together

We're using next.js and typescript(not fully but yeah a little here and there manageable for the beginners) here. So ran the command `npx create-next-app@latest` and then did no for the eslint and app router of next.js in the project bootstrap setup.

In the project folder we have 'src' directory which contains all the main code and all, and the 'api' folder has the parent index file called 'index.tsx'.

Now everything works just like the vite bootstrapped react-app, we have created a components folder which will have all the components.

The 'public' folder is the one that contains the images and other non code files

- The video card component
  - It has a main thumbnail image which takes some spaces, has some rounded corners and below that image we have round channel img, title, after that channel name, no of views and date added. So they're in a form of grid fashion, first thumbnail main grid, then channel img 1/3rd of the grid space and rest of the stuff in the other 2/3rd one below the other. Only date added is right to the no of views, in equal spaces in that 2/3rd space
  - Adjust the padding and all as per necessity
  - The channel image must be a square for tailwind to better round it using `rounded-full`.
  - You don't need to import the image otherwise it doesn't render, react/next.js knows that the assets stuff are inside the public directory so just writing the correct name in the props without any directory slashes works

- Now we'll create a video grid component in which we have a in memory variable that will contain the values that are supposed to be coming from the backend. And then in that VideoGrid we are going to iterate over the variable to find all the stuff and then put them in the VideoCard component imported from the files and render them from the main index.tsx file.
- Also we have the AppBar at the top which contains the logo, search bar and a sign in option, of which the search bar has been copied from another website to create one and then yoinked to its own component which then is imported to our main AppBar component
- The SearchBar component has the custom create search field created by hkirat and the search icon are some icons created by the tailwind people which are some svgs open sourced and free to use.
  - Also added `inline-flex` & `items-center` to make the things vertically center  to the main parent flex
  - Also you can make the appbar responsive too, recommended when it'll be sent to someone. There is an easy way to do using `sm:hidden` when not small and when it is small render only the search icon button and onclick(not the js event) expose the whole search bar which takes the whole space
  - And for hover pointer we can add cursor-pointer to the main parent div of the card to apply that.

### Errors encountered

- the export default error

The error you're encountering when using `export default` instead of `export` in your `VideoCard` component likely occurs because you're importing it with braces `{}` in your `index.tsx` file.

When you use `export default` in a module, you don't need to destructure it using braces `{}` during import. Instead, you can directly import it as:

```javascript
import VideoCard from '../components/VideoCard';
```

However, if you're using `export` without `default`, you need to destructure it during import:

```javascript
import { VideoCard } from '../components/VideoCard';
```

So, to resolve the error, you should either change your import statement in `index.tsx` to import `VideoCard` without braces, or change the export statement in `VideoCard.jsx` to `export` without `default`. Choose the approach based on your project structure and requirements.

- Why do we even need object destructuring in the first place

In JavaScript, when you use `export` with the `default` keyword, you're exporting a single value or function as the default export of the module. When importing a default export, you can choose any name you want for the imported value; you're not required to use the same name as the exported value. This flexibility allows you to import the default export without braces `{}` and to name it however you want during import.

For example, consider a module `example.js` exporting a default function:

```javascript
// example.js
export default function myFunction() {
  // Function implementation
}
```

You can import this default export as follows:

```javascript
// Importing the default export without braces
import myFunction from './example.js';
```

On the other hand, when using `export` without `default`, you're exporting named exports, which are explicit and named values or functions from the module. When importing named exports, you must use the exact names specified in the export statement. This is why you need to destructure the named export using braces `{}` during import.

For example, consider a module `example.js` exporting a named function:

```javascript
// example.js
export function myFunction() {
  // Function implementation
}
```

You can import this named export as follows:

```javascript
// Importing the named export with braces
import { myFunction } from './example.js';
```

This distinction between default and named exports allows for more flexibility and clarity in managing modules and their exports.
