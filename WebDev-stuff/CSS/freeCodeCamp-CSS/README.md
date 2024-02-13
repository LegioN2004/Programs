# CSS by freeCodeCamp: Dave Gray

This is a full CSS tutorial from freeCodeCamp by Dave Gray and this file contains the notes and stuff so yeah

## CSS selectors

- So we can use css selectors which are basically element wise selectors so that we can apply styles for specific set of elements, lets say applying red color to p applies red color to all the p elements, and they can be differentiated using classes/ids.
- It follows the inheritance approach, where if we apply some colors to the body and then we apply the a different style to specific element lets say a p tag, then the new styling will override the body one if present.
- For more specific styling we can use ids or classes that apply the styling to certain elements only, out of which classes are the most common.
- Reusing ids are a very bad practice
- We can group selectors using commas, like applying font colors to all the h1 and h2s, by doing `h1, h2 { color: red; }`
- Lets say we have some span elements in the para tags and we want to apply a gold background color to those spans, then we can use the main p tag and then follow it with the span tag(or any other tag which we want to apply the styling to inside the p tag) and then add the styling in that block. Or the other way to do this is by using the class tag and then applying the styling to that specific class and that makes our code more flexible, reusable.
- Then comes the * which is the universal selector and this applies the styling to every thing that is present in the page, and this can't be overridden by anything.
- CSS also does the top-down approach, so if we apply a lets say a color red styling to the p tag and then again apply a blue color to that same p tag again, then the page will show the blue color p tag since it picked up that last. So this is the top-down approach, that CSS follows
  - But that doesn't apply to the CSS classes since they have more specificity. So if we have three para tags out of which two of them has a class which has another color grey and then we apply the first p with red and the second with lightlblue to the para tags then the ones with no classes will still pick up the styling rule of the last i.e blue and the ones with classes will pick the color defined in the class grey no matter where they're kept since they give more specificity. So classes overrides the selectors
- Inheritance: That is where another element inherits the properties from its parent element. So the body element is parent to every other element, so when we set font to a certain style every element intherited that property. So anything related to font or typography, things like color, line height alignment all sorts of setting dealing with the fonts are inherited, but the others not dealing with them are not inherited
  - But the universal selector doesn't follow the inheritance since anything inside it is applied to whole of the DOM
  - This inheritance property inside the body helps us to not violate DRY
  - But since the other elements like form elements like button, input, textarea, select don't inherit the body styles so in order to inherit it, we can set it manually by using the value "inherit" to the property that we want to inherit.

    ```css
    button, select, textarea, input{
    font:inherit;
    }
    ```

  - We can also set the inherit properties in the html block styling as well instead of body but either would work. There are certain body specific styles so that can be separated between them for readability but both will apply inheritance

- Main element: It is a semantic element and it should appear only once per page, so we have to make sure that it selects things inside the of the main element. So when we set the main element as `font-family: monospace` then we'll see that the fonts inside of the main element changes to monospace which follows the inheritance as same as the body, i.e if we apply the same same to the body then all the things inside the body will change to that style. But if we have different font family in both the body and the main(that means different values for the same style) then the main style will apply only because that comes later on the styling rule and the ones outside of the main styling will get the body styling only provided the main is a child of the body.
- The specificity order: element selector < class selector < id selector (id although won't be used much in css).
- Dont use this but anyway: We can use the `!important`  after the property value without any spaces to apply a styling over the whole document overriding anything that comes in the way, like applying color purple to every other para even if other styling normally overrides by using `p { color: purple!important }`
  - We can also check element specificity online by using this website called [specificity-calculator](https://specificity.keegan.st/)
  - CSS validator checker website [css-validator](https://jigsaw.w3.org/css-validator/)

## CSS Colors

- html has 147 colors and they're all shown by vscode alphabetically
- We have to consider the contrast when picking colors to make it legible and readable, and accessible for our viewers and there are contrast ratios that are avaialable
- we can set a background color by saying `background-color: blue;` but  there is a shorthand which gives us many other options for styling on top of the background.
- We can change the font color using the property color like `color: darkblue;`.
- We have the `body` where we'll typically see all the font styling, colors for background and all setup. We can set the background to a lot of different elements and we often have fonts on top of those elements or inside of those elements but on top of the colors
- Another way to set colors is by using RGB(red, green, blue) values using `color: rgb(255, 0, 0);` which means colors in the form of values and it goes in the manner as the name suggests. The lowest value of the colors goes to 0 and the highhest goes to 255 and the max the value in one of them it gets set to that color and if 0 then that doesn't .
  - There is another style to do rgb which is rgba which means red, green, blue and the added alpha channel which guides the transparency and it has a value range of 0 to 1 where 1 doesn't apply anything i.e normal and the difference comes using the values in between where 0 makes the element completely transparent, 0.5 means 50% transparency and so on.
- And there is the most common way of setting colors using the hexadecimal values. They have their own set of rules of setting colors, it goes from 0 to 9 and also uses the letters A through F. The values are written with a pound symbol at the starting
  - The highest value is `#FFFFFF` which is white, and the lowest value is `#000000` which is black
