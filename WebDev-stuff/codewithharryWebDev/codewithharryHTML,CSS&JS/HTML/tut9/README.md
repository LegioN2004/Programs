# Inline and Block elements

## Block element

Block-level elements, in contrast, start on a new line and occupy the full available width of their parent container by default. They create a block-level box that visually separates it from other elements. Examples of block-level elements include
 `<div>`, `<p>`, `<h1>` to `<h6>`, `<ul>`, `<li>`, and many more.

- **`paragraph`** is a block element, so it takes the whole width of the html doc and any new element always comes after this.
  - using the **`<span></span>`** tag here instead makes the sentences appear in a single line.
  - **i.e use inline elements to make a line or something come to a single line or use CSS to convert block elements to inline(detailed in later)**

## Inline element

Inline elements are those that do not start on a new line and only take up as much horizontal space as necessary to display their content. These elements flow within the text or other inline elements. Some common examples of inline elements are `<span>`, `<a>`, `<strong>`, `<em>`, and `<img>`.

- `span` is an inline element and so it prints sentences in a single line only since it only needs that much space.

### Inline styling using CSS

- we can add `style` attribute to add inline css
  - Coloured box around a line: In the opening p tag, use the `border: 2px solid red;` , `border` for border, `px` means the thickness and `solid red` is the color of the border and end line with ';' .
