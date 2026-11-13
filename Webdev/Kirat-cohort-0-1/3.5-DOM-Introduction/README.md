# DOM Introduction

**D**ocument **O**bject **M**odel(DOM): A standard for how to get, change, add, or delete HTML elements

1. Quick intro to DOM
2. how dom represents an html document in memory
3. how to use APIs to create web content and applications

- If something doesn't make sense go to this [link](https://quickest-juniper-f9c.notion.site/Week-3-5-a22dfeab1af84ec4b453ca565c57b27a) and look up what is wrong.
- Also read all the html files in the directory, they're all related and contains info about the html, dom stuff, etc.

## What is DOM

- JS makes the HTML page interactive and dynamic via the _DOM_. Because HTML and JS in itself doesn't do much, so as to make them more useful in webpages, we can use DOM to make use of the both HTML and JS to make the webpage interactive and dynamic. So as such now JS will be able to know when the user is interacting, what is it clicking, etc and it does that by communicating with the browser using methods, properties, events, etc in the interface called the DOM. For example: you want to change the color of a button when someone hovers or clicks on it, etc.

- Things to remember:
  - DOM is not a programming language
  - It is a programming interface for web documents
  - It represents the page so that progams can change the document structure, style and content
  - The DOM is a tree-like representation of the web page that gets loaded into the browser
  - The DOM represents the documents as nodes and object
  - Without it, the JS language wouldn't have any model or notion of web
  - Web API is used to build websites
  - DOM is language independent

### Accessing the DOM

When you create a script, whether inline in a script tag, or included in the webpage, you can immediately start using the API for the document or window objects to manipulate the document itself

The DOM was designed to be independent of any particular programming language, making the structural representation of the document available from a single, consistent API

DOM represents the web page using a series of objects. The main object is the 'document object', which in turn house all the other 'objects' such as h1,p, form, etc, as children which also houses their own objects as sub-children and it gets nested so on and so forth.

eg:

```html
<!doctype html>
<html lang="en">
  <head>
    <title>Document</title>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link href="css/style.css" rel="stylesheet" />
  </head>
  <body>
    <h1>A heading</h1>
    <p>
      A paragraph, Lorem ipsum dolor sit amet, qui minim labore adipisicing
      minim sint cillum sint consectetur cupidatat.
    </p>
    <script>
      // this is how you would access the DOM from JS
      document.body.appendChild(Heading);
    </script>
  </body>
</html>
```

- The dom tree is accessed from JS using the dot operator
  the dom tree goes something like this, for the above example:

                                                         DOM
                                                          |
                                                          |
                                                          |
                                                         HTML
                                                      /       \
                                                     /         \
                                                    /           \
                                                  HEAD          BODY
                                                    |             |
                                                    |             |------------|
                                                    |             |            |
                                                  TITLE          H1            P
                                                    |             |            |
                                                    |             |            |
                                                    |             |            |
                                               "Document"      "Header"   "Paragraph"

- When a web browser is parsing an HTML doc, it builds a DOM tree and then uses it to display the document

#### The Document Object

This is the top most object in the DOM. It has properties and methods which you can use to get info about the document using a rule called the dot notation. The document object also has the similar tree like structure as shown above that consists lots of other html elements in the tree branches

```html
<!doctype html>
<html lang="en">
  <body>
    <form id="LoginForm" action="./action_page.php">
      First name: <input type="text" name="fname" value="Donald" /><br />
      Last name: <input type="text" name="fname" value="Duck" /><br />
      <input type="submit" value="Submit" />
    </form>
    <p>Click the "Try it" button to display the no of elements in the form</p>
    <button onClick="myFunction()">Try it</button>
    <p id="displayspace"></p>
    <script>
      function myFunction() {
        var x = document.getElementById("LoginForm").elements.length;
        var y = document.getElementById("LoginForm").elements[1].value;
        document.getElementById("displayspace").innerHTML =
          "Found " +
          x +
          " elements in the form " +
          " last name entered is: " +
          y;
      }
    </script>
  </body>
</html>
```

- The above codeblock created a html page, where we could find the last name as well as first name with the click of a button and some entry in the fields of the form. the code inside the form tag and the script tag are the main ones. `var x = document.getElementById("LoginForm").elements.length;` is the one that finds the length of value from the form tag using the `getElementById("id_name")`, and then gives the elements first or last value according to the index in which the entry may be present.

---

- **How to create elements**: We can create another heading or a paragraph, in order to do that we have another element called `createElement()` which creates a new element and inserts it into the DOM.
  - This is useful for cases where we want to display certain error messages, or certain notifications, only when a certain user action has happened. In order for us to do that, we need to first locate the element, fetch it and then apply the action be it anything(creation, deletion, addition of any element).

```js
const para = document.createElement("p"); // creates a paragraph element
para.innerText = "This is a paragraph to be added to the p tag"; // the paragraph that needs to inserted to the p tag
document.body.appendChild(para); // and the code to add the p tag to the dom. `appendChild(variable/directly the document.createElement)`
```

### Finding HTML elements

If we want to manipulate HTML elements, then we'll need to first find them and we can do that using multiple ways such as:

- Using id
- Using tag name
- Using class name
- Using CSS selectors
- Using HTML object collections

#### 1. Using ID

- HTML elements can be uniquely identified by their "id" attribute.
- JavaScript provides the `getElementById` method to find an element with a specific id.

```html
<!-- HTML -->
<div id="exampleDiv">This is a div with an id</div>
```

```javascript
// JavaScript
const elementById = document.getElementById("exampleDiv");
```

#### 2. Using Tag Name

- You can find HTML elements by their tag name using `getElementsByTagName`.
- This returns a collection of elements with the specified tag name.

```html
<!-- HTML -->
<ul>
  <li>Item 1</li>
  <li>Item 2</li>
</ul>
```

```javascript
// JavaScript
const listItems = document.getElementsByTagName("li");
```

#### 3. Using Class Name

- Use `getElementsByClassName` to find elements by their class name.
- It returns a collection of elements with the specified class.

```html
<!-- HTML -->
<p class="exampleClass">This is a paragraph with a class</p>
```

```javascript
// JavaScript
const elementsByClass = document.getElementsByClassName("exampleClass");
```

#### 4. Using CSS Selectors

- CSS selectors such as id, class names, types, attributes, values of attributes, etc, can be used with `querySelector` and `querySelectorAll` to find elements.
- `querySelector` returns the first matching element, while `querySelectorAll` returns a collection of the element specified i.e similar ones
- you need to add '.' before the class for accessing them using `querySelectorAll`.
- Also you can target different classes inside with same elements or simply different class, using `p.intro` or `p.subheading` and separating them with commas inside the double quotes
- If you pass an incorrect selector, then it'll just show syntax error, but doesn't affect the actual page by not showing anything

```html
<!-- HTML -->
<div class="exampleDiv">First div</div>
<div class="exampleDiv">Second div</div>
<p class="intro"></p>
<p class="subheading"></p>
```

```javascript
// JavaScript
const firstDiv = document.querySelector(".exampleDiv");
const allDivs = document.querySelectorAll(".exampleDiv");
// you need to add '.' before the class for accessing them using querySelectorAll.
```

```html
<!-- HTML -->
<div>div one</div>
<p>paragraph one</p>
<div>div one</div>
<p>paragraph two</p>
<div>another div</div>
```

```javascript
// JavaScript
var paragraphs = document.querySelectorAll("p");
//var paragraphs = document.querySelectorAll("p.intro"); // for the intro class p tag
paragraphs.forEach((paragraph) => (paragraph.style.backgroundColor = "red")); // al the paragraphs marked as red
```

#### 5. Using HTML Object Collections

- Elements like forms, images, links, etc., can be accessed using their corresponding HTML object collections.

```html
<!-- HTML -->
<form name="exampleForm">
  <!-- Form elements go here -->
</form>
```

```javascript
// JavaScript
const formElement = document.forms.exampleForm;
```

These methods provide ways to access and manipulate HTML elements, enabling dynamic and interactive web development. Choose the appropriate method based on the structure and attributes of the HTML elements you want to interact with.

##### About the index when accessing elements

In JavaScript, when you access elements in the DOM (Document Object Model) using methods like `getElementsByTagName`, `getElementsByClassName`, or `querySelectorAll`, you often get a collection of elements. The `index` refers to the position of an element within that collection. NOTE: On giving wrong or an index which doesn't exist, it'll print nothing in that place and the error shows up in the browser console

Here's a brief explanation:

1. **Single Elements:**

   - For methods like `getElementById` or `querySelector`, which return a single element, there is no need for an index.

   ```javascript
   const singleElement = document.getElementById("exampleId");
   ```

2. **Collections (Multiple Elements):**

   - When you get a collection of elements using methods like `getElementsByTagName`, `getElementsByClassName`, or `querySelectorAll`, you can access individual elements by their index.

   ```html
   <!-- HTML -->
   <ul>
     <li>Item 1</li>
     <li>Item 2</li>
     <li>Item 3</li>
   </ul>
   ```

   ```javascript
   // JavaScript
   const listItems = document.getElementsByTagName("li");

   // Accessing elements by index
   const firstItem = listItems[0];
   const secondItem = listItems[1];
   ```

3. **HTML Collections:**

   - Some collections, like `document.forms` or `element.children`, are HTML collections. They are not arrays, but they can be accessed by index.

   ```html
   <!-- HTML -->
   <form>
     <input type="text" name="username" />
     <input type="password" name="password" />
   </form>
   ```

   ```javascript
   // JavaScript
   const form = document.forms[0];
   const usernameInput = form[0]; // Accessing input by index
   ```

##### CSS Selectors

All CSS Simple Selectors
| **Selectors** | **Example** | **Example description** |
| ----------------- | --------------- | --------------- |
| #id | #firstname | Selects the element with id="firstname" |
| .class| .intro | Selects all elements with class="intro" |
| element.class | p.intro | Selects only <p> elements with class="intro" |
| element | p | Selects all <p> elements |
| element,element,.. | div, p | Selects all <div> elements and all <p> elements |

Here are some common examples of using Query Selectors:

- **Selecting by Element Type:**

  ```jsx
  var paragraphs = document.querySelectorAll("p");
  ```

- **Selecting by Class Name:**

  ```jsx
  var elementsWithClass = document.querySelectorAll(".className");
  ```

- **Selecting by ID:**

  ```jsx
  var elementWithId = document.querySelector("#elementId");
  ```

- **Selecting by Attribute:**

  ```jsx
  var elementsWithAttribute = document.querySelectorAll("[data-custom]");
  ```

- **Combining Selectors:**

  ```jsx
  var complexSelection = document.querySelectorAll("ul li.active");
  ```

Query Selectors return either a NodeList (for `querySelectorAll`) or a single element (for `querySelector`). NodeList is a collection of nodes, which can be iterated through using methods like `forEach`.

#### Examples

```html
<body>
  <h2>aortnratn</h2>
  <p>arositneeeeeeeeeeeeeeeeeeeeeeeeee</p>
</body>

<p id="demo"></p>

<script>
  document.getElementById("demo").innerHTML =
    document.documentElement.innerHTML;
</script>
```

The above code utilises the html object collection to once write the text inside the body and then again copies the body and prints that again, that appears as the body.

### What is HTMLCollection and NodeList

Both `NodeList` and `HTMLCollection` are collections of nodes or elements in the Document Object Model (DOM) provided by the browser. They represent a set of nodes that you can interact with using JavaScript.

- NodeList:

  - A `NodeList` is a collection of nodes, typically returned by methods such as `querySelectorAll` or properties like `childNodes`.
  - It is not limited to elements; it can include various types of nodes such as elements, text nodes, comments, etc.
  - It is a static collection, meaning it is a snapshot of the nodes at the moment the `NodeList` is created. It does not automatically update if the DOM changes.

Example:

```javascript
// Get a NodeList of all paragraphs in the document
const paragraphs = document.querySelectorAll("p");

// Iterate through the NodeList
paragraphs.forEach((paragraph) => {
  console.log(paragraph.textContent);
});
```

- HTMLCollection:

  - An `HTMLCollection` is similar to a `NodeList` but is specifically a collection of HTML elements.
  - It is often returned by properties like `children` or methods like `getElementsByTagName`.
  - Like `NodeList`, it is also a static collection and won't automatically update if the DOM changes.

Example:

```javascript
// Get an HTMLCollection of all div elements with the class 'example'
const divElements = document.getElementsByClassName("example");

// Iterate through the HTMLCollection
for (let i = 0; i < divElements.length; i++) {
  console.log(divElements[i].textContent);
}
```

### Differences between a HTMLCollection and a NodeList

- HTMLCollection:

  - **Live Collection:**
    - **Live:** An HTMLCollection is live, meaning it is automatically updated when the underlying document changes. If elements are added or removed, the HTMLCollection is automatically updated to reflect these changes.
  - **Accessing Elements:**
    - **By Index:** Elements in an HTMLCollection can be accessed using numerical indices, similar to an array.
  - **Methods:**
    - **Limited Methods:** HTMLCollections have a more limited set of methods compared to NodeLists.
  - **Specific to Elements:**
    - **Element-Specific:** HTMLCollections are typically used for collections of HTML elements, such as those returned by `getElementsByTagName` or `getElementsByClassName`.

- NodeList:

  - **Live or Static:**
    - **Live or Static:** A NodeList can be live or static. If it's obtained using `querySelectorAll`, it's static and won't automatically update. If it's obtained by other means, like `childNodes`, it might be live.
  - **Accessing Elements:**
    - **By Index or forEach:** Like HTMLCollection, you can access elements by index. Additionally, NodeList supports the `forEach` method for iteration.
  - **Methods:**
    - **Richer Set of Methods:** NodeLists typically have a broader set of methods compared to HTMLCollections.
  - **Not Limited to Elements:**
    - **Node-Oriented:** NodeLists can include various types of nodes, not just HTML elements. They might include text nodes, comment nodes, etc.

#### Practical Considerations

- **Common Methods:**
  - For general purpose, when using methods like `querySelectorAll`, you will get a NodeList.
- **Live vs. Static:**
  - If you need a live collection that automatically updates, an HTMLCollection might be suitable.
  - If you want a static collection that won't change, or if you need a broader range of methods, a NodeList might be preferable.
- **Usage:**
  - HTMLCollections are often associated with specific methods like `getElementsByClassName` or `getElementsByTagName`.
  - NodeLists are often the result of more generic methods like `querySelectorAll` or properties like `childNodes`.

### Changing HTML Content

| **Property**                          | **Description**                               |
| ------------------------------------- | --------------------------------------------- |
| element.innnerHTML = new HTML content | change the inner html of an element           |
| element.attribute = new value         | change the attribute value of an html element |
| element.style.property = new style    | changes the style of an html element          |
| **Method**                            | **Description**                               |
| element.setAttribute(attribute,value) | change the attributevalue of an html element  |

Changing HTML elements dynamically is a fundamental aspect of web development, and JavaScript provides several methods to achieve this. Here are some commonly used methods for changing HTML elements:

1. **`innerHTML`:**

   - **Purpose:** Changes the HTML content (including tags) of an element.
   - **Example:**

     ```jsx
     document.getElementById("myElement").innerHTML = "New content";
     ```

2. **`textContent`:**

   - **Purpose:** Changes the text content of an element, excluding HTML tags.
   - **Example:**

     ```jsx
     document.getElementById("myElement").textContent = "New text content";
     ```

3. **`setAttribute`:**

   - **Purpose:** Sets the value of an attribute on an element.
   - **Example:**

     ```jsx
     document.getElementById("myElement").setAttribute("class", "newClass");
     ```

4. **`style`:**

   - **Purpose:** Modifies the inline styles of an element.
   - **Example:**

     ```jsx
     document.getElementById("myElement").style.color = "blue";
     ```

5. **`classList`:**

   - **Purpose:** Provides methods to add, remove, or toggle CSS classes on an element.
   - **Examples:**

     ```jsx
     document.getElementById("myElement").classList.add("newClass");
     document.getElementById("myElement").classList.remove("oldClass");
     ```

6. **`appendChild`:**

   - **Purpose:** Adds a new child element to an existing element.
   - **Example:**

     ```jsx
     var newElement = document.createElement("p");
     newElement.textContent = "New paragraph";
     document.getElementById("parentElement").appendChild(newElement);
     ```

7. **`removeChild`:**

   - **Purpose:** Removes a child element from its parent.
   - **Example:**

     ```jsx
     var childToRemove = document.getElementById("childElement");
     document.getElementById("parentElement").removeChild(childToRemove);
     ```

8. **`setAttribute`:**

   - **Purpose:** Sets or changes the value of an attribute on an HTML element.
   - Also can change the type from one element type to another
   - if the attribute specified doesn't exist, then it is created first
   - **Example:**

     ```jsx
     document.getElementById("myElement").setAttribute("src", "new-image.jpg");
     ```

9. **`write`:**

   - **Purpose:** writes the value in a html output field directly.
   - placement matters, if you place between two p tags then it'll appear inside those 2 p tags
   - shouldn't be used after the document has been loaded, since it'll overwrite the entire document
   - **Example:**

     ```jsx
     document.write(Date()); // add the function inside the write parentheses
     ```

These methods provide a diverse set of tools for us developers to manipulate HTML elements dynamically, whether it's updating content, changing styles, or modifying attributes. The choice of method depends on the specific requirement and the nature of the change you want to apply.

### Example - using **`setAttribute`** to change an input field to a button

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Change Input to Button Example</title>
  </head>
  <body>
    <input type="text" id="myInput" value="Type Something" />
    <button onclick="changeToButton()">Change to Button</button>

    <script>
      function changeToButton() {
        // Get the input element
        var inputElement = document.getElementById("myInput");

        // Create a new button element
        var buttonElement = document.createElement("button");

        // Set attributes for the new button
        buttonElement.setAttribute("type", "button");
        buttonElement.setAttribute("onclick", "alert('Button Clicked!')");
        buttonElement.innerHTML = "Click Me";

        // Replace the input with the new button
        inputElement.parentNode.replaceChild(buttonElement, inputElement);
      }
    </script>
  </body>
</html>
```

In this example, an input field with the id "myInput" is initially present, alongside a button labeled "Change to Button." Clicking this button triggers the **`changeToButton`** function, wherein a new button is dynamically created using **`createElement`**. Key attributes (type and onclick) are set via **`setAttribute`**, and the input field is promptly replaced by this newly fashioned button using **`replaceChild`**. The outcome is a dynamic transformation, demonstrating the capability to swap an input field for a button upon clicking "Change to Button," complete with an onclick attribute for interactive functionality.

## Adding HTML Elements

1. **`createElement` Method:**

   - **Purpose:** Creates a new HTML element.
   - **Example:**

     ```jsx
     var newElement = document.createElement("div");
     ```

2. **`appendChild` Method:**

   - **Purpose:** Appends a new child element to an existing element.
   - **Example:**

     ```jsx
     var parentElement = document.getElementById("parent");
     parentElement.appendChild(newElement);
     ```

3. **`insertBefore` Method:**

   - **Purpose:** Inserts a new element before a specified existing element.
   - **Example:**

     ```jsx
     var existingElement = document.getElementById("existing");
     parentElement.insertBefore(newElement, existingElement);
     ```

4. **`innerHTML` Property:**

   - **Purpose:** Sets or gets the HTML content inside an element.
   - **Example:**

     ```jsx
     parentElement.innerHTML = "<p>New content</p>";
     ```

5. **`insertAdjacentHTML` Method:**

   - **Purpose:** Inserts HTML into a specified position relative to the element.
   - **Example:**

     ```jsx
     parentElement.insertAdjacentHTML("beforeend", "<p>New content</p>");
     ```

## Deleting HTML Elements

1. **`removeChild` Method:**

   - **Purpose:** Removes a child element from its parent.
   - **Example:**

     ```jsx
     var childElement = document.getElementById("child");
     parentElement.removeChild(childElement);
     ```

2. **`remove` Method (Modern Browsers):**

   - **Purpose:** Removes the element itself.
   - **Example:**

     ```jsx
     var elementToRemove = document.getElementById("toRemove");
     elementToRemove.remove();
     ```

3. **`replaceChild` Method:**

   - **Purpose:** Replaces a child element with a new element.
   - **Example:**

     ```jsx
     var newChildElement = document.createElement("span");
     parentElement.replaceChild(newChildElement, oldChildElement);
     ```

4. **`innerHTML` Property (Setting to an Empty String):**

   - **Purpose:** Sets the HTML content inside an element to an empty string, effectively removing its content.
   - **Example:**

     ```jsx
     parentElement.innerHTML = "";
     ```

5. **`outerHTML` Property:**

   - **Purpose:** Replaces an element with its HTML content.
   - **Example:**

     ```jsx
     var newHTML = "<p>New content</p>";
     parentElement.outerHTML = newHTML;
     ```

## DOM Node & Methods

The DOM (Document Object Model) is a programming interface that represents the structure of a document as a tree of objects, where each object corresponds to a part of the document. A DOM Node is a fundamental interface in the DOM hierarchy, representing a generic node in the tree structure. All elements, attributes, and text content in an HTML or XML document are nodes.

Here are some key points about DOM Nodes and their methods:

### Key Points

1. **Node Types:**
   - Nodes can have different types, such as elements, text nodes, attributes, comments, etc.
   - The `nodeType` property is used to determine the type of a node.
2. **Hierarchy:**
   - Nodes are organized in a hierarchical structure, forming a tree.
   - The `parentNode` property allows you to access the parent node of a given node.
   - The `childNodes` property provides a NodeList of child nodes.
3. **Traversal:**
   - The `nextSibling` and `previousSibling` properties allow traversal to adjacent nodes.
   - The `firstChild` and `lastChild` properties give access to the first and last child nodes.

### Types Of Nodes

In the DOM (Document Object Model), nodes represent different parts of an HTML or XML document, forming a tree structure. There are various types of nodes, each serving a specific purpose. Here are the common types of nodes in the DOM:

1. **Element Nodes:**

   - **Description:** Represent HTML or XML elements.
   - **Access:** Accessed using methods like `getElementById`, `getElementsByTagName`, or `querySelector`.
   - **Example:**
     The `<div>` element is an example of an element node.

   ```html
   <div id="example">This is an element node</div>
   ```

2. **Attribute Nodes:** (deprecated)

   - **Description:** Represent attributes of an HTML or XML element.
   - **Access:** Attributes can be accessed through the `attributes` property of an element node.
   - **Example:**
     In this example, `src` and `alt` are attribute nodes of the `<img>` element.

     ```html
     <img src="example.jpg" alt="Example Image" />
     ```

3. **Text Nodes:**

   - **Description:** Contain the text content within an HTML or XML element.
   - **Access:** Accessed through the `textContent` or `innerText` property of an element node.
   - **Example:**
     The text "This is a text node" is a text node within the `<p>` element.

   ```html
   <p>This is a text node</p>
   ```

4. **Comment Nodes:**

   - **Description:** Represent comments within the HTML or XML document.
   - **Access:** Accessed through the `comment` property of a comment node.
   - **Example:**
     The content within <!-- and --> is a comment node.

     ```html
     <!-- This is a comment -->
     ```

5. **Document Node:**

   - **Description:** Represents the entire document.
   - **Access:** The document node is the entry point for accessing the DOM tree.
   - **Example:**
     The `<html>` element serves as the document node in this example.

     ```html
     <!doctype html>
     <html>
       <head>
         <title>Document Node Example</title>
       </head>
       <body>
         <p>This is the document node.</p>
       </body>
     </html>
     ```

6. **Document Type Node:**

   - **Description:** Represents the document type declaration.
   - **Access:** Accessed through the `doctype` property of the document node.
   - **Example:**
     The `<!DOCTYPE html>` declaration is a document type node.

     ```html
     <!doctype html>
     ```

### How to access the nodes

We can access any element by using the following properties with the node object

- node.childNodes – accesses the child nodes of a selected parent‌‌
- node.firstChild – accesses the first child of a selected parent‌‌
- node.lastChild – accesses the last child of a selected parent.‌‌
- node.parentNode – accesses the parent of a selected child node.‌‌
- node.nextSibling – accesses the next consecutive element (sibling) of a selected element.‌‌
- node.previousSibling – accesses the previous element (sibling) of a selected element

#### some errors regarding DOM processing

A common error in DOM processing is to expect an element node to contain text.

```html
<title id="demo">tutorial</title>
```

to extract the text in the title tag, we can use any one of the following methods.

```js
myTitle = documet.getElementById("demo").children[0].nodeValue;
// or
myTitle = documet.getElementById("demo").firstChild.nodeValue;
// or
myTitle = documet.getElementById("demo").childNodes[0].nodeValue;
```

### some examples related stuff from the video

---

In the provided HTML and JavaScript code, there is an attempt to replace the text content of the second `<li>` element in the list with the text "Juice" when the "Replace" button is clicked. Let's break down the relevant parts:

1. `document.getElementById("my-list").children[1]`:

   - This line retrieves the second child (index 1, as indices are zero-based) of the element with the ID "my-list." In this case, it is the second `<li>` element.

2. `document.createTextNode("Juice")`:

   - This line creates a new text node containing the text "Juice." A text node is a DOM object representing a piece of text within an HTML or XML document.

3. `element.replaceChild(newNode, element.childNodes[0])`:

   - This line replaces the first child node of the selected `<li>` element with the newly created text node.

   - `element` refers to the second `<li>` element retrieved earlier.
   - `newNode` is the text node created with the content "Juice."
   - `element.childNodes[0]` refers to the first child node of the selected `<li>` element, which is the existing text node containing the current text content.

So, the overall effect of clicking the "Replace" button is to replace the existing text content of the second `<li>` element with the text "Juice." The use of `document.createTextNode` creates a new text node, and `replaceChild` replaces the existing text node with the new one.

However, there is a small issue in the provided code: `element.childNodes[0]` is used to reference the existing text node, but it would be more appropriate to use `element.firstChild` or `element.childNodes[0]` directly, as `childNodes[0]` is already a reference to the first child node.

---

## DOM Events

DOM events are interactions or occurrences that take place in a web page, such as a user clicking a button, pressing a key, resizing the browser window, or the content of an input field changing. The HTML DOM (Document Object Model) allows JavaScript to respond to these events, enabling developers to create interactive and dynamic web applications. Here's an overview of DOM events and how JavaScript can react to them:

### Key Concepts

1. **Event Types:**
   - Events can be triggered by various actions, such as mouse clicks (`click`), keyboard presses (`keydown`, `keyup`), form submissions (`submit`), document loading (`load`), and more.
2. **Event Targets:**
   - Events are associated with specific HTML elements, known as event targets. For example, a `click` event might be associated with a button, and a `change` event might be associated with a form input.
3. **Event Handlers:**
   - JavaScript can respond to events by using event handlers. Event handlers are functions that get executed when a specific event occurs.

### Reacting to Events

1. **Inline Event Handlers:**

   - You can define event handlers directly within HTML elements using inline attributes like `onclick`, `onmouseover`, etc.

   ```html
   <button onclick="javascript_Function()">Click me</button>
   ```

2. **DOM Level 0 Event Handling:**

   - You can assign event handlers directly to JavaScript properties of DOM elements.

   ```jsx
   var button = document.getElementById("myButton");
   button.onclick = function () {
     // Handle the click event
   };
   ```

3. **DOM Level 2 Event Handling:**

   - The `addEventListener` method is used to attach event handlers to elements. This method provides more flexibility and allows multiple handlers for the same event.

   ```jsx
   var button = document.getElementById("myButton");
   button.addEventListener("click", function () {
     // Handle the click event
   });
   ```

4. **Event Object:**

   - Event handlers typically receive an event object that provides information about the event, such as the target element, mouse coordinates, key codes, etc.

   ```jsx
   button.addEventListener("click", function (event) {
     console.log("Button clicked!", event.target);
   });
   ```

### some examples from videos

- oninput: when we enter something and automatically the case changes to upper or lower

---

The reason the value doesn't turn to uppercase when you directly assign it to `x` is because you are assigning the uppercase value to a variable (`x`) that is not connected to the input element. In the provided code, `x` is just a variable storing the uppercase version of the input's value, but it doesn't update the actual input field.

```html
<body>
  Enter your name: <input type="text" , id="fname" , oninput="uppercase()" />
  <script>
    function uppercase() {
      const x = document.getElementById("fname");
      x.value = x.value.toUpperCase();
    }
  </script>
</body>
```

Here's what happens when you type in the input field:

1. The `oninput` event is triggered when there's an input change in the text field.

2. The `uppercase` function is called.

3. Inside the `uppercase` function, you correctly get the input element:

   ```javascript
   const x = document.getElementById("fname");
   ```

   `x` now represents the input element.

4. You then set the value of the input element to its uppercase version:
   ```javascript
   x.value = x.value.toUpperCase();
   ```
   This line modifies the `value` property of the input element (`x`), making the text uppercase.

If you were to use a separate variable, like in your example:

```javascript
const x = document.getElementById("fname").value;
x = x.toUpperCase();
```

In this case, you are storing the value of the input element in `x`, converting it to uppercase, and assigning it to a new variable `x`. However, this doesn't affect the actual input element on your page. To update the input field, you need to set its `value` property, as shown in your original function:

```javascript
const x = document.getElementById("fname");
x.value = x.value.toUpperCase();
```

Make sure there are no syntax errors in your HTML. Remove the commas (`,`) between attributes and use a single `oninput` attribute without commas:

```html
<body>
  Enter your name: <input type="text" id="fname" oninput="uppercase()" />
  <script>
    function uppercase() {
      const x = document.getElementById("fname");
      x.value = x.value.toUpperCase();
    }
  </script>
</body>
```

---

- Also don't write dom styles like css, like backgroundColor = blue, you need to add blue in double quotes

### Common Events

1. **Click Event:**
   - Triggered when a mouse button is clicked.
2. **Keydown and Keyup Events:**
   - Fired when a key on the keyboard is pressed or released.
3. **Submit Event:**
   - Triggered when a form is submitted.
4. **Change Event:**
   - Fired when the value of an input field changes.
5. **Load Event:**
   - Occurs when a resource (like an image or script) and the entire page have finished loading.

### Example

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Event Handling Example</title>
  </head>
  <body>
    <button id="myButton">Click me</button>

    <script>
      var button = document.getElementById("myButton");

      // Using DOM Level 2 event handling
      button.addEventListener("click", function () {
        alert("Button clicked!");
      });
    </script>
  </body>
</html>
```

In this example, a click event handler is attached to a button using the `addEventListener` method. When the button is clicked, an alert is displayed.

Understanding DOM events and how to handle them is crucial for creating interactive and responsive web applications. Developers use events to capture user actions and trigger appropriate JavaScript functionality in response.

## The `onload` and `onunload` functions

The `onload` and `onunload` events are part of the HTML DOM (Document Object Model) and are used to execute JavaScript code when a document or a page finishes loading (`onload`) or unloading (`onunload`). These events are commonly used to perform actions when a user enters or leaves a webpage.

### `onload` Event

The `onload` event is triggered when a document or a webpage has finished loading. This event is often used to ensure that all resources, such as images and scripts, have been fully loaded before executing specific JavaScript code.

Example:

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>onload Event Example</title>
    <script>
      window.onload = function () {
        // Code to execute after the page has fully loaded
        alert("Page loaded!");
      };
    </script>
  </head>
  <body>
    <h1>Hello, World!</h1>
  </body>
</html>
```

In this example, the `onload` event is used to display an alert when the page has finished loading.

## `onunload` Event

The `onunload` event is triggered just before a document or a webpage is about to be unloaded, such as when the user navigates away from the page or closes the browser tab. This event is often used to perform cleanup tasks or prompt the user for confirmation before leaving the page.

Example:

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>onunload Event Example</title>
    <script>
      window.onunload = function () {
        // Code to execute before the page is unloaded
        alert("Goodbye! Come back soon.");
      };
    </script>
  </head>
  <body>
    <h1>Thanks for visiting!</h1>
  </body>
</html>
```

In this example, the `onunload` event is used to display an alert just before the page is unloaded.

These events play a crucial role in managing the lifecycle of a web page and allow developers to execute code at specific points during the page's existence.

## DOM Event Listeners

DOM Event Listeners provide a more flexible and powerful way to handle events compared to traditional event attributes (e.g., `onclick`). Event Listeners allow you to attach multiple event handlers to a single event, making your code more modular and easier to maintain.

- Attaches an event handler to the specified element (without overwriting existing event handlers).
- You can add many event handlers(even of the same type) to one element.
- You can add event listeners to any DOM object not only HTML elements. i.e the window object.
- The addEventListener() method makes it easier to control how the event reacts to bubbling.
- When using the addEventListener() method, the JavaScript is separated from the HTML markup, for better readability and allows you to add event listeners even when you do not control the HTML markup.
- You can easily remove an event listener by using the removeEventListener() method.

### Using `addEventListener`

The `addEventListener` method is used to attach an event listener to an HTML element. It takes three parameters: the event type, the function to be executed when the event occurs, and an optional third parameter controls how the event is applied, whether its bubbling(means inside out) or the other way, outermost element to the innermost element. By default, bubbling is how the events are applied

### Syntax

```jsx
element.addEventListener(eventType, eventHandler, useCapture);
```

- **`eventType`**: A string representing the type of event (e.g., "click", "keydown", "change").
- **`eventHandler`**: A function that will be called when the event occurs.
- **`useCapture`**: (Optional) A boolean value indicating whether to use the capturing phase (`true`) or the bubbling phase (`false`, default).

### Example of Multiple Event Listeners

Here's a code snippet demonstrating the use of multiple event listeners on a button. In this example, we have a button that changes its color and displays a message when clicked, and it resets to its default state when the mouse leaves it:

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Multiple Event Listeners Example</title>
    <style>
      #myButton {
        padding: 10px;
        font-size: 16px;
        cursor: pointer;
      }
    </style>
  </head>
  <body>
    <button id="myButton">Click me</button>

    <script>
      // Get the button element
      var button = document.getElementById("myButton");

      // Event listener for the "click" event
      button.addEventListener("click", function () {
        // Change the button color
        button.style.backgroundColor = "green";
        // Display a message
        alert("Button clicked!");
      });

      // Event listener for the "mouseenter" event
      button.addEventListener("mouseenter", function () {
        // Change the button color on mouse enter
        button.style.backgroundColor = "yellow";
      });

      // Event listener for the "mouseleave" event
      button.addEventListener("mouseleave", function () {
        // Reset the button color on mouse leave
        button.style.backgroundColor = "";
      });
    </script>
  </body>
</html>
```

In this example:

- Clicking the button changes its color to green and triggers an alert.
- Hovering over the button changes its color to yellow.
- Moving the mouse away from the button resets its color to the default state.

Using multiple event listeners allows you to handle different aspects of user interaction separately, promoting cleaner and more organized code.

# Event Bubbling & Event Capturing

Event bubbling and event capturing are two phases of event propagation in the HTML DOM. When an event occurs on an HTML element, it goes through these two phases:

1. **Event Capturing (Capture Phase):**
   - In this phase, the event travels from the root of the DOM tree to the target element.
   - Event handlers attached with `useCapture` set to `true` are triggered during this phase.
2. **Event Bubbling (Bubbling Phase):**
   - In this phase, the event travels from the target element back up to the root of the DOM tree.
   - Event handlers attached without specifying `useCapture` or with `useCapture` set to `false` are triggered during this phase.

## Example of Event Capturing

In the following example, we have a nested set of div elements, and we attach event listeners to the document capturing phase (`useCapture` set to `true`). When you click on the innermost div, you'll see that the event handlers for the capturing phase are triggered from the root to the target:

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Event Capturing Example</title>
  </head>
  <body>
    <div id="outer" style="border: 1px solid red; padding: 10px;">
      Outer
      <div id="middle" style="border: 1px solid green; padding: 10px;">
        Middle
        <div id="inner" style="border: 1px solid blue; padding: 10px;">
          Inner
        </div>
      </div>
    </div>

    <script>
      document.getElementById("outer").addEventListener(
        "click",
        function () {
          console.log("Outer Capturing");
        },
        true,
      );

      document.getElementById("middle").addEventListener(
        "click",
        function () {
          console.log("Middle Capturing");
        },
        true,
      );

      document.getElementById("inner").addEventListener(
        "click",
        function () {
          console.log("Inner Capturing");
        },
        true,
      );
    </script>
  </body>
</html>
```

When you click on the "Inner" div, you'll see in the console that the capturing phase event handlers are triggered in the order: Outer Capturing, Middle Capturing, Inner Capturing.

## Example of Event Bubbling

In this example, event listeners are attached without specifying `useCapture` or with `useCapture` set to `false`. When you click on the innermost div, the event handlers are triggered in the bubbling phase from the target back up to the root:

```html
<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Event Bubbling Example</title>
  </head>
  <body>
    <div id="outer" style="border: 1px solid red; padding: 10px;">
      Outer
      <div id="middle" style="border: 1px solid green; padding: 10px;">
        Middle
        <div id="inner" style="border: 1px solid blue; padding: 10px;">
          Inner
        </div>
      </div>
    </div>

    <script>
      document.getElementById("outer").addEventListener("click", function () {
        console.log("Outer Bubbling");
      });

      document.getElementById("middle").addEventListener("click", function () {
        console.log("Middle Bubbling");
      });

      document.getElementById("inner").addEventListener("click", function () {
        console.log("Inner Bubbling");
      });
    </script>
  </body>
</html>
```

When you click on the "Inner" div, you'll see in the console that the bubbling phase event handlers are triggered in the order: Inner Bubbling, Middle Bubbling, Outer Bubbling.

In practice, event bubbling is more commonly used, and the `useCapture` parameter is often omitted or set to `false` when attaching event listeners. Event capturing is less commonly used and is mainly applicable in specific scenarios where capturing is explicitly needed.

#### Event bubbling or Event Capturing

There are two ways to propagate in the HTML DOM, bubbling and capturing.
Event propagation is a way of defining the element order, whether it is inside out or it is in the outermost element being handled first
Event propagation is a way of defining the element order when an event occurs. If you have a <p> element inside a <div> element, and the user clicks on the <p> element, which element's "click" event should be handled first?
In bubbling the inner most element's event is handled first and then the outer: the <p> element's click event is handled first, then the <div> element's click event.
In capturing the outer most element's event is handled first and then the inner: the <div> element's click event will be handled first, then the <p> element's click event
