# CSS Fonts

**NOTE:** We are still using the internal css, since the css are shown in small codeblocks. But do not do that in actual use cases where you need to use css seriously

- **Fonts addition**
  - Firstly we are using the so called "web safe" fonts that comes pre installed in most of the operating systems here in the html file. They are called web safe since using them will never throw any errors as they are always available and it is good for the developer.
  - The ones which are not present natively on any computer are called ***web fonts*** and they need to be imported from the web.

  - About font-family with example: It specifies a prioritized list of font family names or generic family names. A user agent iterates through the list of family names until it matches an available font that contains a glyph for the character to be rendered.
    - the following example code block shows a ***font stack*** which applies the fonts in the a priority and availability manner

      ``` css
      font-family: 'Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;
      ```

    - We also have a very good website named [csscodestack.com](https://www.cssfontsstack.com) which tells us which ***web safe fonts*** is available and which can be used.

  - But the very good website for importing fonts in case of ***web fonts*** is from **[Google fonts](https://fonts.google.com)**
  - In this following example I have imported the Ubuntu font from google

  ``` html
  i<link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link href="https://fonts.googleapis.com/css2?family=Ubuntu:ital@0;1&display=swap" rel="stylesheet">
  ```

- **Font size**: Font size is added using the css property `font-size` and the value i.e the size can be in pixels. Remember 1 pixel is 1/96th of an inch

- **Line height**: Line height is the space that is present if there are above or below one another such as in this case(index.html) the height between the `h4` heading css fonts and the `p` tag
  - Here `em` has been used which one of the many units used in web. `em` here means how much the times of the font size of the parent font. The font size that becomes the multiple of the parent font size.(will be discussed properly later on)

- **Font weight**: Font weight is used to give weight to the fonts such as bold, light,etc and can be set using the `font-weight` property and its values can be bold, light, some number acc to weight, etc.

- To bold a certain word or paragraph use the `span` tags and followed by that add a span css selector styling and give it a `font-weight` property value as `bold`.

## All of these properties and elements and all should not be memorized but understood properly because a time will come when you may or may not remember everything but the understanding part will help you get your problem solved by just googling and quering if you know what it is.