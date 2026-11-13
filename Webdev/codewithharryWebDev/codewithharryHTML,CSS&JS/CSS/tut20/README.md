# CSS Box Model

<img src="https://www.simplilearn.com/ice9/free_resources_article_thumb/CSS-Box-Model.png" alt="Box model" height=250px></img>

The above image shows a better representation of how to add margin, border and padding to an element and where, and this is covered by the box model topic of CSS.

## How to apply these

- Firstly we shall make some examples to try these so I have made some divs with some paragraphs and headings
- We can see the main content just appearing attached to the outer box, so we will apply the CSS property `padding: 9px` and we'll see that the main contain appears distant from the box, this is known as **padding**. As we continue increasing the padding pixels the outer box becomes bigger and the main content remains the same size but comes to the center eventually distant from the outer box. This outer box is known as **border**.
- Now we are also seeing that the borders appear attached to each other, so we'll apply margin to them so as to make them separate. The margin comes next to border and after applying a `margin: 12px`, we can see that they are separated from each other.
- Also we can do something like a margin or a padding that applies to only a certain direction as directed, they can be done by margin or padding shorthands, and it can be done by the following ways:
  - We can add directions to the padding by using the properties `padding-top: _px` or `padding-bottom: _px`, etc
  - Similarly we can add directions to the margin by using the `margin-top: _px` or `margin-bottom: _px`, etc
  - **NOTE**: And if we want to add all(by all it is top right bottom left) in one then we'll use the following syntax: `padding: 23px 56px 68px 78px; /* padding = top  right bottom left; */`
  - And same goes for margin too if we want to add all(by all it is top right bottom left) in one: `margin: 23px 56px 68px 78px; /* margin = top  right bottom left; */`

  - **NOTE**: ***Will be used often*** To add same pixels(dimensions) to both the top and bottom & left and right we can use the following syntax to do so: `padding: 34px 19px;`. This applies 34 pixels padding to both the top and bottom directions and 19 pixels padding to both the left and right side.

- So the **main content** is the blue box one in the diagram which is present in the center, **padding** is the spacing between the main content and the border, **border** is the outline that comes after the padding and margin is the outer space outside of the border and it comes after the border

- We can also add width to the by using the css property `width: 400px`, which changes the width. **NOTE** that when the we change the padding the width also changes even if it is fixed, this is because because the actual elements have all those dimensions margin, padding, border, etc properties added and as such changing one changes all the others relatively.
  - But if you don't want to happen, you can add the property `box-sizing: border-box;` and as such if something is changed it will adjust itself and will not change and and will change accordingly.

- You can use a universal selector to apply a property or properties to all the elements and the syntax is as follows: `*{ property_name: property_value; }`. Also you can also add certain properties to make those as the default style (with their respective values if needed) until you want to override them specifically under that block.

### Use the developer tools to set colors once property is written to get a better view directly in the webpage
