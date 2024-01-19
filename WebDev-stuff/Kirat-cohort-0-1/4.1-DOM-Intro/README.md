# DOM, Dynamic frontends, Connecting FE to BE

## DOM

The DOM(Document Object Model) API is a programming interface for web documents. It represents the page so that programs can change the document structure, style, and content. The DOM represents the document as a tree of objects; each object represents a part of the page.

## Again what was JavaScript

- It was an implementation of the ECMAScript spec. what is spec: It is a standard written by very smart people and again another set of smart people wrote the implementation of the spec such as the V8 engine at google which is the actual compiler for JS. But the browser people said that there need to be some other functions as well so as to make it of use in the web.
- for example: setTimeout, setInterval, fetch, document/DOM are what the browser provides, it is not present in the JS spec. Browser does all the extra things. setTimeout, http library, express on top of http library of node.js, whoever wrote those are also auxilliary APIs and is not of the JS spec. So node.js provides backend specific funtionality just like the browser provides a browser specific functionality
- If you try to write document in a node.js application it'll tell us that document is not present in it. But if we try to write it lets say for a website, then it'll work.
- DOM gives us a lot of functions and in that way we can manipulate DOM

## Dynamic Frontends

Making static websites are easy, but dynamic is hard.
What is dynamic website? : Any site that 1. Changing the elements on the website once the website is loaded 2. Actually calculating the sum based on the inputs and rendering it on the screen. To make a website dynamic we'll need to use JS, more specifically the DOM API using JS.

### id's and class's

- Classes is a part of html attributes and are not unique for every element in html. They are used to apply one kind of property to many different elements without repeating it everytime, lets say we define a type of styling for one class and using that class that styling can be applied to different elements as desired.
- But ids are unique, so one type of styling can be used in only one kind of elements.
- Classes gets rid of code repeatition
- id's lets you access elements via the DOM API
- We can use ids for CSS, but it is mainly used in JS

## All the DOM

- document is the global variable using which we can manipulate the DOM.

- with the example calculator

  - for input fields, we can take values by using `document.getElementById("id_name").value;`.
  - Also by default field inputs are string in type(due to browsers), so we need to convert them to integer by using `parseInt()` global function in js, otherwise when the strings are added they just get concatenated eg: "2" + "2" = "22"
  - to get internal value of input tags, you need to add the 'dot notation' followed by the 'value'

- What if the we don't have access to the calculation logic on the frontend (i.e no access to it on the frontend) and we need to hit the backend server to access it since it has some very complicated logic(also they don't want the logic to get exposed to the world).

  - Now we'll have to hit the backend server with our input using html instead of this `element.innerHTML = parseInt(a) + parseInt(b);`.
  - we can fetch and give the parameters using string concatenation, but since it is doing the thing in the backend it needs to be a promise and so we need to do add a `.then()` so that after the promise resolves we can do the next thing.

  ```js
  fetch("https://sum-server.100xdevs.com/sum?a=" + a + "&b=" + b).then(
    (response) => {
      console.log(response);
      response.text().then(function (ans) {
        console.log(ans);
      });
    }
  );
  ```

  - Fetch's syntax is very old and complex(but in the future we'll be trying out axios which is much easier to understand and send requests to a backend server). We need to know what type of data will be sent back with the response when using fetch. But we know here that the request that'll be sent is in the text format, so we'll just use the `response.text()` method.
    - Also we'll be using promise chaining, i.e chaining with `.then()` first we get the response back with from the backend using fetch, then we take in the response.text() since it is textual data and we again pass in the `.then` to log out the ans which we can just put it back in the elements using dom.
    - Why is the response inside fetch returning a promise, because it is how fetch is written. Whoever has written, said that when you tell me whether or not you want text or json, I'll do an async call to figure something out and what that is, is on me. So you need to await me or you will get a promise so you will have to wait till the promise resolves

## Debouncing and Throtlling

- What if we want to do that calculate sum problem but without having the button, i.e when we enter the values in two fields it auto calculates and returns the sum, we don't need to press the calculate button?
  - So what we can do here is use the oninput attribute in the element such that anytime there is a change in input the request automatically goes out to the server. On input syntax is something like `oninput="js_function()"`
  - So when we do something like this where everytime we enter an input a request goes out to the backend, so if we do the calculation by writing 1000 + 1000 a total of 8 requests goes out. Now how can we opitimize it so that it doesn't immediately send requests to the backend and instead waits for lets say 100ms, since the user will not always type very fast such that there is an immediate need of response, the user types a little and then waits then the request happens. So this is an application of debouncing, or delayed response to the user.
  - A near implementation will be using a setTimeout having the main logic inside and the setTimeout is inside another function that runs only when the oninput is triggered.
  - So it sets a timer when the parent function is invoked and waits for 100ms, if invoked again within 100ms it then stops the original clock and starts a new timer that runs for another 100ms for the whole of the function. Since setTimeout lets us to create a clock, there is another inbuilt function called clearTimeout that lets you clear a clock

#### chaptgpt ans to debouncing

Debouncing is a programming practice used to ensure that time-consuming tasks do not fire so often, making it more efficient. It is often used in scenarios where a function is repeatedly called in a short time frame, such as in response to user input like keystrokes or window resizing.

Here's how debouncing typically works:

1. **Event Triggered:** An event (like a button click or keypress) is triggered.
2. **Timer Set:** Instead of immediately executing the associated function, a timer is set for a short delay.
3. **Reset Timer:** If the event is triggered again before the timer elapses, the timer is reset.
4. **Execute Function:** Only when the timer elapses without the event being triggered again, the associated function is finally executed.

Debouncing is useful to prevent unnecessary execution of a function that might be computationally expensive or involve network requests, especially when the user is providing rapid or frequent input.

For example, if you're implementing an autocomplete feature in a search bar, debouncing can be applied to delay the search until the user has stopped typing for a brief moment, reducing the number of unnecessary search requests.
