# Introduction to CSS

CSS stands for Cascading Style Sheets. It is a style sheet language that is used to handle the presentation of the web page containing HTML. It makes our websites beautiful and modern looking

- CSS gives styles to raw HTML, ultimately styling our websites
  - raw HTML means the default style in which all the HTML tags appear
- CSS is used to make websites responsive, i.e to make it adaptible to different forms and types of devices
- HTML is used to structure the website only
- CSS takes responsibility of the design of the websites

## CSS syntax

The syntax is in this manner : selector -> property -> value

For example:

```css
p {
  color: blue;
}
/* add this property of color blue to the paragraph */
```

- here p is the selector , color is the property and blue is the value.
  1. First of all we write selector. It gives where to put the stuff, most apporipiately where to put the `property`, which `property` to change and where to put all the changes. Here for the prev example it'll be for the paragraph.
  2. Then comes property, which property to apply to say all the paragraphs, that will be acc to the example the `color` property.
  3. And the value, this value will be according to the property. In case of the above example, add the value of color as blue
  - So the above steps make up as : Apply the color property with value blue to all the paragraphs of the website.
    - you can add id's to make exceptions in those colors and other changes

- Main syntax

``` css
header, p.intro {
                    background-color : red;
                    border-radius : 3px;
                }
```

group^of^selectors | declaration^block   (this shows what are the above using the ^ sign)

- the property should end with a colon to show the value and the property with value line should end with a semi-colon which shows line ending.
- So this says that set the background-color to red and border-radius to 3px.

## Some more stuff regarding CSS

- Three ways to add CSS to the markup. (Note: HTML is normally be called as markup from here on out)
  1. Inline CSS : CSS is added to the elements directly using the style attribute
  2. Internal CSS : CSS is kept inside the `<head>` tags  in `<style>` tags
  3. External CSS : CSS is kept seaparately inside a .css style sheet file; done in 2 steps
     - Step 1 : Write the css in a .css file.
     - Step 2 : Include that .css file to markup.
