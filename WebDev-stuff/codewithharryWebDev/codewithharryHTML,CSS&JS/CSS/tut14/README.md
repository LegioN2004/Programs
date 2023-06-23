# CSS tutorial first (continuing from the vid #13)

- ***file referenced is always the index.html and style.css file present in the same directory***

- **You should not use inline CSS i.e direct single line css as it'll make the code so messy, that maintaining will become too cumbersome.**
- **So we'll stick to internal and external CSS as much as possible**
- you need to add inline css by adding as many properties and their values as possible in a single line like the following example which makes it unfeasible to do styling like that.

``` html
    <p style="color: red; background-color: "yellow"">This tutorial will teach you everything you will need to learn about HTML/CSS</p>
```

- Also in the file there we have added the internal css in the head tag and as we can see in the preview inline css is given more priority than internal css.

## External CSS

- You can add external css by using the link tag.
  - Here rel means: This attribute names a relationship of the linked document to the current document.
  - href means: We know it is used to link websites or files, so href links the file that is in the same directory and here it has been used to link the style.css file

``` html
 <link rel="stylesheet" href="style.css">
```

- This above link tag will take the contents of the style.css file and put it in the markup
  - Doing this or using the style tag with the contents of the file inside that tag means the same but it comes down to how manageable the file will be. If the css file contains a thousand lines of styling then the markup will be conjusted with unnecessary stuff which could be added in another file and then linked to the markup make it more feasible in termso maintenance.
- Btw, external css does't take priority over internal css.
- **NOTE: And the order goes like this: The one written after gets more priority so in my style.css link and the internal css, the one written after takes effect over the other i.e the external css** . Also  this doesn't effect
- **to give any one of the css as the priority order as 1 use the `!important` in the ending of the css styling inside the semicolon**
- **NOTE** = So overall internal css takes precedence over the other two i.e for inline and external css and then for them the one that comes after the other takes precendence over the other and vice versa.
   - What the browser does : The browser collects all the styles and sheets at one place, then parses and shows all the markups and after that puts styles on them, so the thing that comes afterwards overrides the previous one if important tag is not present in the tag used before
