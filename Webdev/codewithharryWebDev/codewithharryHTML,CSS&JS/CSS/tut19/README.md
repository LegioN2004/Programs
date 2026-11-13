# Height, width, Borders and Backgrounds

- **Height**: We can add height using the property `height` and they take values in pixels(can be others too haven't used till now)
- **Width**: We can add width using the property `width` and they take values in pixels(can be others too haven't used till now)
- **Borders**: We can add borders using properties css and those properties are(note: this is the order of styling the borders but it doesn't matter to the css parser)
  - `border-width`: for giving a border width and give some size to it to make it visible, defaults to invisible until a explicit style is defined i.e `border-style`.
  - `border-style`: for giving style to a border and it defaults to the black color.
  - `border-color`: for giving colors to a border and it defaults to the black color.
  - `border-radius`: for giving radius to a border to make it curvy around the corners and as the value increases it curves out the borders near to the corners as well edges.
  - **NOTE** = To make writing the above styling regarding the borders easier we can directly use the `border:` property and add those styles to all the four borders serially and the same style can be achieved.
- **NOTE** = If you want to add styles to borders left, right, top and bottom individually then you can use these properties: `border-top` ; `border-bottom`; `border-left`; `border-right` .
- Like the above you can also trigger individual level styling the corners and making it curvy using properties like :
  1. `border-top-left-radius`: the name itself tells that it'll make the top left border radius/corner by this/that much curved acc to the pixel given as value
  2. `border-top-right-radius`: the name itself tells that it'll make the top right border radius/corner by this/that much curved acc to the pixel given as value
  3. `border-bottom-left-radius`: the name itself tells that it'll make the bottom left border radius/corner by this/that much curved acc to the pixel given as value
  4. `border-bottom-right-radius`: the name itself tells that it'll make the bottom right border radius/corner by this/that much curved acc to the pixel given as value

## Adding images and customization

- `background-image`: We can add images in css using the `background-image` property and the value can be anything. For adding images we can use the following:
  1. For files in the same folder we can use `./` to show the actual directory where the file is located and its name as well,
  2. We can use `url('')` where we will put the url of the image inside the single quotes.

- `background-repeat`: After adding the background image we can see that it repeats itself a no of times according to the height and width given so we'll need to stop the repeating for which we can use the property `background-repeat` and its values are the following and they represent some rules:
  1. `repeat-x` : repeats the image only on the x axis
  2. `repeat-y` : similarly y repeats the image only on the y axis
  3. `no-repeat` : as the name suggests it doesn't let the image repeat itself and only shows once

- `background-position`: It is used to give position to the background image using the x and y axis. It's values goes like this: `center top` ;`center center` ; `center bottom` ; `center right` ; `px px` . The first part in the value gives the x axis orientation and the second part gives the y axis orientation. So if we give the `center top` it will first center the image acc to the x axis and it'll align it to the top direction in the y axis. We can also use pixels for aligning, using something like `12px 12px` will make the image go 12px from the left to right x axis and from top to bottom y axis
- **NOTE**: The `width` and `height` of the image will change according to the `background-positon` i.e these two properties are interdependent and changing the one effects the other. Eg: when the position is center center the image wil auto resize itself keeping the main content at the center when the width and height of the image is changed and when the position is center top the width change happens from the right and the height change happens from the opposite i.e from the bottom, which means _it maintains the position given according to the width or height being adjusted_.
- **Also NOTE** we cannot write top top as it doesn't make sense. We can use top left/right ; bottom left/right ; etc i.e in the second part we can use only the ones that makes sense.
