# IMAGES and ANCHOR

## About Images and anchor tags

- About _`anchor`_ tags in the html file itself `<a href = "**the link to the website**"> _the button`
- _`image`_ tag is written as `<img src="name of the image" alt="describe the content of the image if image can't be loaded or processed"><br>`
- Use `target="_blank"` inside the opening anchor tag after the `href` part, it gives a property to the html file to go to new tab whenever the link button is clicked, also im using some line breaks, eg : `<a href="https://github.com/LegioN2004" target="_blank">Go to google </a><br>` `<br>` here is for line breaks
- Search engines also rely on the _`alt`_ attribute to understand and index the content of images. Providing descriptive and relevant alternative text can improve the accessibility and discoverability of your website's images in search engine result
- _`href`_ attribute is used to link a file or a website to a tag
- In the image tag `<img src="https://source.unsplash.com/random" alt="random images from unsplash" width="the no" height="the no"><br>` you can add `src` attrb to show the link or the location of the image file, then `alt` to prov info if `img` not shown, and width and height if image of the web is resizeable or forcefully resize in the html file itself. _this is not the recommended method to style the page use CSS_

### DO NOT USE HTML for STYLING, ONLY CSS IS USED FOR STYLING USE HTML FOR THE SKELETON ONLY

### Main difference between *`href`* and *`src`* attributes

- The **`src`** attribute is used in elements like **`<img>`**, **`<script>`**, and **`<iframe>`**. It specifies the source URL of the resource that should be embedded or displayed in the element. For example, in the case of an img tag, the src attribute specifies the URL of the image that should be loaded and displayed on the webpage. Example:

``` html
<img src="image.jpg" alt="Image">
```

- On the other hand, the **`href`** attribute is used in elements like **`<a>`**, **`<link>`**, and **`<area>`**. It specifies the destination URL or location of the linked resource. In the case of an `<a>` (anchor) tag, the href attribute specifies the URL of the webpage or resource that should be linked to. Example:

``` html
<a href="https://www.example.com">Visit Example.com</a>
```

- While both src and href deal with URLs, they are used in different contexts and have different behaviors.

## difference between attribute and tags

- In HTML, both attributes and tags are used to define and structure elements within a web page. However, they serve different purposes:

### Tags

Tags are the fundamental building blocks of HTML. They define the structure and semantics of elements on a web page. Tags are represented by angled brackets (< and >). They typically come in pairs: an opening tag and a closing tag, with content between them. The opening tag indicates the beginning of an element, and the closing tag denotes its end. For example, `<p>` is the opening tag for a paragraph element, and `</p>` is the closing tag. Tags define the type and behavior of elements, such as headings, paragraphs, lists, images, and more.

### Attributes

Attributes provide additional information or instructions about HTML elements. They are specified within the opening tag of an element and consist of a name-value pair. Attributes further define or modify the behavior, appearance, or functionality of an element. For example, the src attribute in an `<img>` tag specifies the source URL of the image, and the href attribute in an `<a>` tag determines the destination URL of the link. Attributes can be used to control various aspects of elements, such as dimensions, colors, alignment, responsiveness, accessibility, and more.
