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
export default function Test(){
return(
    <div classNames="flex justify-between">
    <div classNames="bg-red-700">
    hi from red div
    </div>
    <div classNames="bg-green-700">
    hi from green div
    </div>
    <div classNames="bg-blue-700">
    hi from blue div
    </div>
    </div>
)}
```

## Grids

Another way to make the divs come next to each other side by side is by using grids. By using
