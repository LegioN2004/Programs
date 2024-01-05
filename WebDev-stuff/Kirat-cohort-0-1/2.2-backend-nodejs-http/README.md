# Node.js runtime(backend basically) and http(Hyper Text Transfer Protocol)

- Understand the node.js runtime and how it is different from the way browsers run javascript and how does it work
  - Why node.js was and is introduced
  - What is bun that was recently introduced, a competitor to nodejs and how is it different from nodejs
- Secondly http and is used in a bunch of places for frontend to talk to backend

## Node.js and its runtime

### What is ECMAScript and Javascript

ECMAScript is a scripting language specification on which javascript is based. ECMA International is the organization in charge of standardizing ECMAScript. There is a website which has all the specifications i.e documentation which says that how javascript should be written, what it should have, etc. They're a bunch of smart people who own the javascript standard. It is significantly different from the main javascript, but these documentation sort of guides people that whoever wants to write a compiler for javascript should follow these standards because it is the standard followed by everyone who writes javascript. It is continuously updated and the newly updated browsers support that, but the old ones get outdated pretty frequently if not updated so you need to follow the standards

JavaScript and ECMAScript (ES) are terms that are often used interchangeably, but they refer to slightly different concepts.

1. **ECMAScript (ES):**

   - **Definition:** ECMAScript is a scripting language specification standardized by ECMA International. It defines the core features that a scripting language must provide and serves as a foundation for scripting languages like JavaScript.
   - **Versions:** ECMAScript has different versions, each introducing new features and improvements. Some of the major versions include ES5, ES6 (or ECMAScript 2015), ES2016, ES2017, and so on.
   - **Standardization:** ECMAScript is a standard that provides guidelines on how a scripting language should behave. It ensures consistency and compatibility across different implementations.
   - **Implementation:** JavaScript is the most well-known implementation of ECMAScript, but other languages like JScript and ActionScript are also based on the ECMAScript standard.

2. **JavaScript:**

   - **Definition:** JavaScript is a programming language that was initially developed by Netscape for web development. It is one of the most widely used scripting languages for both client-side and server-side development.
   - **Implementation:** JavaScript is essentially an implementation of the ECMAScript standard. When people refer to writing JavaScript code, they are usually referring to the language based on the ECMAScript standard.
   - **Use Cases:** JavaScript is primarily used for enhancing web pages by adding interactivity, manipulating the DOM, handling events, and communicating with servers. With the advent of technologies like Node.js, JavaScript is also used for server-side development.
   - **Beyond ECMAScript:** Javascript includes additional features that are not the part of the ECMAScript specification like DOM manipulation, which is crucial for web development but is not defined by ECMAScript.

- Two most popular javascript compilers used in the real world are

1. V8 by Google: V8 is an open-source engine developed by the chromium project for Google and chromium based web browsers. It is written in C++ and and is responsible for copiling javascript code to native machine code before executing it, which greatly improves performance. V8 is also used by the nodejs.
2. SpiderMonkey by Firefox: It is also another javascript compiler written in C and rust.

### Node.js

Some smart people took out the V8 engine/compiler from the browser, added some backend functionality on top like readFile, writeFile, etc on top to create a runtime and as such they also turned it into a backend language. Javascript was never meant to be run in the backend but since it was easy to understand, alreadly learned by many people since it was a standard to write websites and was already very popular so people made it for the backend. It eventually became very popular and is a popular choice of runtime for the backend.

## Bun, the new runtime in the market meant to be significantly faster that nodejs

Other than the fact that JS is single threaded, nodejs is generally slow and so some people decided to rewrite the JS runtime for the backend and to make it very fast comparatively and as such introduced bun. Bun is written in Zig and it is significantly faster. It is still very new so it is catching up to node and it'll be the future for backend until something new comes up. The people at bun are make the backend runtime backwards compatible as much as possible so that every nodejs library out there is supported by bun. Also in the future developers will move to bun from node

### What can you do with nodejs

- Make a game
- create clis
- create video player
- create a video game
- create an **_http server_**: This is the main usecase in the workplace

#### what is an http server

- A protocol that is defined for machines to communicate
- Specifically for websites, it is the most common way for the website's frontend to talk to the backend.
- for eg: in the chatgpt website, the frontend talks to the backend like something when we write the query and press the enter button a request goes to the backend in the server of chatgpt and then the LLM runs it, generates a respons and sends it to the frontend that we see in front of our eyes.

The protocol is the way the client(frontend) talks to the backend, this is the http protocol.
But the server is the one that is able to read the request, the thing that is running in the server. The thing that 'exposes' the machine learning model to the world for usage, by exposes it checks for all the credentials, subscriptions, authentication etc other settings stuff and then sends a response.

In the end we can think of the http server as a function that takes an input runs the logic inside that and then returns an output as desired. HTTP server is just like that instead it takes an output from someone on the internet does soem computation and then returns it back.

- Arguments are something that the client sends
- Rather than calling a function using its name, the client uses the url
- Rather than the function body, the server does something with the request
- Rather than the function returning a value, the server responds with some data

## HTTP Protocol in details

### HTTP client side(sending a request)

Things that the client needs to worry about

- Protocol: what protocol you are using, http/https
- Address: address or the url of the backend of the server like https://www.google.com, this shows the frontend of the server but the response of the frontend comes from the backend of google.
- Route: Coming soon
- Headers, Body, and Query params:
- Methods:

Using the example of the chatgpt site

**https://chat.openai.com/backend-api/conversation**

- protocol: https(the first part before the domain name) is used
- Address: **'chat.openai.com'** which is also the domain name, is the `url` address
- Route: **'backend-api/conversation'** is the route, since chatgpt can do many things like open previous chats, create new chat, etc many different things so everything has its own route, so route specifies what are you trying to do, here we are creating a converation in the example so we have this.
- Headers, Body, and Query params
  - Headers: Headers send some important infomation like cookies which is authentication(one of the important ones) that shows you are logged in, what are your details, etc. The backend knows that I am logged in and we can add more stuff to the headers.
  - Body(most important): Whenever you sending a request to the backend, you are asking it to do something and you send some arguments. eg: The query that we send to the chatgpt is kept in a body and it contains this query as a data. Body is usually in JSON.
  - Query
- Methods: Methods specify what kind of request you are sending, do you want to send/write some data in the server, or do you want to get the data from the server. Here we have a GET request since we are getting/requesting something from the backend server of chatgpt

### HTTP server side(getting a request)

Things that the server needs to worry about

- Response headers:
- Response body:
- Status codes:

Using the example of the chatgpt site

**https://chat.openai.com/backend-api/conversation**

- Response headers: When we request the chatgpt, it gives out a response header, used only for authentication when you sign in and get the cookie and store it in the browser
- Response body: This is the response or the answer that we get to our request
- Status codes: eg: 200, 500, 404 error these are some status codes that the server responds with.

This is a good convention to follow, the people who wrote the protocol said that. You could totally mix stuff and send them together

- Things that happen when in your browser after you fire this request

  - Browser parses the url: finds the url, i.e where is it being sent
  - Does a DNS lookup(converts google.com to an IP): We are sending a request to google.com but under the hood the request goes to the IP address. IP is a way to find the server on the internet, i.e it is the address of a computer. IP looks something like 192.168.1.245
    - What is **DNS resolution**: When we go to chatgpt.com , first what happens it the Domanin Name Service(DNS) resolution. Even though we find the servers using ip, people found remembering IP very hard since it only consists of numbers, then they came out with something like people/org/institutions will buy domain names and they can map their ip with the domain names which made it easy to remember. So first thing the browser does when we search chatgpt.com is it gets the IP from the url. If you want to buy a domain of your own, then you will need to map the ip to the IP of your server
  - It then establishes a connection to the IP, does something called a handshake(computer networking stuff)

- Things that happen on the server after the request has been received.
  - (when you use a library like express.js or springboot which removes all the complex stuff)

1. You get the inputs(route, body, headers)
2. You do some logic on the input, circulate the output
3. You return the output body, headers and status code

### What are the common methods you can send to your backend server

1. GET: when you get something from the server, say the history view that we see in the left side of the landing page of chatgpt
2. PUT: When you are putting/updating something to the server, lets say changing some settings in the chatgpt
3. POST: When you are adding something to the server, lets say adding a converation to chatgpt.
4. DELETE: When you are deleting/removing something from the server then this handler is used.

These are all the methods and theirs best practices/conventions written aside, doesn't have to be as it is but it is good to follow them

### What are the common status codes the backend server responds with

1. 200: everything is ok
2. 404: page/route not found
3. 403: authentication issues, wrong/updated/changed cookie, i.e access to the requested resource is forbidden
4. 500: internal server error, something like the server crashes or some server related issues

These are all the status codes and theirs best practices/conventions written aside, doesn't have to be as it is but it is good to follow them

## Creating a http server using node and express

- Firstly we got a taste of backend using the fs library which is inbuilt in the JS, it reads the content of the file.
- There are similar libraries like fs but bigger that does the heavy work for you so that you don't need to create one from scratch and the most famous of all is "express"
- A great exercise is to create an HTTP server from scratch in C/C++/Java/etc.

- Onto the main part
- Firstly we'll need the express library so we are going to import it by using the require statement in js but since it is not inbult in javascript like `fs` we'll need to install it using npm with the command `npm install express`
- This is how the high level simple http server is written.

```javascript
const express = require("express"); // this is the statement to import the express library
const app = express();
const port = 3000;

app.get("/", (req, res) => {
  res.send("Hello World!");
});

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});
```

```javascript
express_lib-api_object.method_name("route", arrow_function/anonymous_function/normal_callback/etc_function(variables_or_req, more_variables_or_res) => {
  // some logic to be written here
});
```

- The above examples show how to send a get request
- The first line imports the express library
- The second line `app` is an object which is initialized to the express library using the `express()` function and it holds all the APIs made to make our life easier by not making a http server from scratch and then using it. We can use the high level api to include our own logic and make other stuff without worrying about the low level stuff
- The port is what the server listens to
- The part `app.get` is the same as `fs.readFile`, first parameter in the parentheses is the one reading from the directory/route(the directory is the route in the way the app/website is structured to respond) and when true(it always is) after that it then runs the anonymous arrow function (or any other function) which is a callback and it gets two params req and res objects which contains the request and respond values ;it returns "hello world" to the port viewer. `res.send("")` is the syntax for sending a response, if you want to send JSON, then you can do something like `res.JSON()` to send the JSON data
- Inside the get method parentheses, we have the route to which the data must be sent and if the get request is successful then it'll run the following function logic
- And `app.listen` is used to listen to a port, the port number is given inside the parentheses and we can run more functions inside after that executes successfully to show something after it listens to the port
- The req and res as parameters inside the function of the methods is used to get certain values and they stand as request and respond respectively
- Also the `res.send` in the get request can also interpret/parse raw html because express is just sending a string but since we are passing html in that the browser thinks that since that is html and it can also parse that so it just shows the rendered html, so you can directly write inline html in the function

### Rest API vs HTTP

Whenever the term API is used it usually means that it is exposed not to be accessed from the browser but to be accessed from other nodejs processes and other stuff. So in HTTP all the devices can access the ip, but when the REST comes in, we can sort out who can access something(fix this using chatgpt)

- **How to send a post request**

```javascript
// post in the following
app.post("/conversations", (req, res) => {
  res.send("Hello World!");
});
```

- The post request is sent in the same way as the get request get
- In a post request you can also send data along, for example when we are sending data we can see in the dev tools that there is a body going out in the post request, how can we send that from the browser and how can the website see that, we will get how to send that soon but for now we can use the postman app to do something sort of and it'll make our life easier by not using that dev tools and opening arrow down and up over and over again
- So "Postman" is a software that helps us to send requests just like browser does, internally or externally or explicitly, etc. And as such it is a good tool to test different kind of requests and it has a good list of those already builtin
- Now how to handle a post request

```javascript
app.post("/conversations", (req, res) => {
  console.log(req.headers); // req headers eg
  console.log(req.headers["authorization"]); // req headers authorization key eg
  console.log(req.body); // req body eg
  res.send({
    msg: "2 + 2 = 4",
  });
});


// when listening on the port and postman sending post requests we get the following in the server side
Example listening on port 3000
{
  authorization: '123123123',
  'user-agent': 'PostmanRuntime/7.36.0',
  accept: '*/*',
  'postman-token': 'd472f04b-282f-49df-a6f3-30899870888a',
  host: 'localhost:3000',
  'accept-encoding': 'gzip, deflate, br',
  connection: 'keep-alive',
  'content-length': '0'
}

// second post request on requesting the authorization key itself
Example app listening on port 3000
123123123

// after the body example
Example app listening on port 3000
undefined

```

- This post request happens from the client-side to server-side
- We can use the postman software to send post requests by selecting the post button and the using the url in which it is to send, then at the center part we have the important stuff that is used to test out stuff such as headers, body preview, json, etc and using that we can send some of them too which makes it easy to send special server requests as well as test them live.

  - Also we can use send key value pair directly to give json inputs to the server
  - Headers(client-side): So here we have a `req` variable defined that takes the "request values" and using that we get an object called headers which lets us see all the headers by writing `req.headers` and loggin that out that is available on that port been sent as a post request. Also if we want to get specific values to the post request, we can specify a key and it will give the values. In the example 'authorization' is received because we specified the authorization key in the req headers parentheses.
  - We can also check for tokens to see if the user has access to those or not
  - Body(client-side): In the body part of postman, we can send json and receive the output using `req.body` inside and console.log if we want to print it. If we just leave it like that we can't receive the actual thing sent as a post request message in the body and as such it outputs as undefined, so we need to parse the json maybe, since the body is in json and javascript can directly parse json

    - This will be easier to understand with middlewares
    - Undefined got logged out, since there is not something right with the request(google/gpt it)
    - Whoever wrote express was like that it will handle post request, it'll handle headers, but it'll not handle body and just ignore it.

      - Under the hood, we are using the framework express.js which uses the framework http already in nodejs under the hood, which says that anytime a "request", a bunch of bytes together and somewhere in that is the body and the express library ignores the body. If someone wants to access the body they can use a different library and the common one known is 'body-parser'(we need to install it using `npm install body-parser` and then import it as well)
      - Why use body-parser: Because the body-parser module enables us to parse the incoming request bodies in a middleware. express.js server needs to know what type of data you're sending over the network, so it knows how to parse it.
      - So after importing and initializing an object we can use the middleware `app.use(bodyParser.json())` where bodyParser is the middleware maybe will be clearly written in the next note; Anytime body has some JSON it just extracts the json that gets sent from the request and puts it in the `body` header when called with the `req`(how it does that is a very different story)

      ```javascript
      const express = require("express"); // this is the statement to import the express library
      const bodyParser = require("body-parser");
      const app = express(); // then make an object
      const port = 3000;

      // middlewares code(will be explained later)
      app.use(bodyParser.json());
      ```

- #random-question: When the app.100xdevs.com website is pinged we get the 72.2.2.2 something something ip on the terminal and when we try to access that ip directly on the website we get nothing?
  - The advantages of domanins is that you can have a single server and it has a single ip address, and if a request comes to the server ip from the above mentioned domain, then it will have a "header" called "referer" that points to that ip with respect to the domain.
  - So there are multiple domains that points to the same ip and then it ultimately points to a single server machine(not single server but very close).
  - The backend of the ip checks where the request came from and based on that sends the correct request. Directly accessing the server using its ip will not be possible since the backend will not allow since it has certain domains attached to it to which it sends respond as per request
- #question2: How do I from a website send a request here
  - We use something called fetch which is a webAPI which as the name suggest allows to fetch data from somewhere
- How to send a status code, you just need to send it with the get request when doing the respond object like this `res.status(401).send("hello")` with the "status code" inside the parentheses

### MISC stuff but important stuff

- You can use 'nodemon' so that you don't have to rerun the node process again and again and just keep on live reloading once run on a file. Install it using the command `npm install nodemon` and just run it with the filename as `npx run nodemon`
- You can only run a single proces in a single port in the same machine, i.e you cannot run different processes in the same port
- You can set a environment variable to a certain port that you want to run using the command in the terminal as `export PORT=3000`, can be different for different shells but this is the standard bash syntax. So whenver you invoke the port variable inside js(or any other language,with the special syntax to listen to a port) you can directly initialize the port variable to take the env vars using the syntax `const port = process.env.PORT || 3000` (||, the or is to not show any errors when the port env var is not found in the machine)
- Sometimes you may have seen `https://localhost:3000/backend-api/conversations/?message=123&b=1&c=2` that the after the route ends there is some message stuff starting with ? question mark after the slash ends, this is another way to send a message to the backend. Why this way: whenever you are sending a get request the url bar in the browser doesn't have enough space to write so many stuff of the body, so we use query params, if there is a get request from the user 99% of the time you want something from the user you are using the query parameters which as the name suggests are a bunch of parameters in the query itself.
- Express,nodemon etc are external dependency or packages that are written by other smart people and people publish their code and libaries in npm registry. This external dependency can be installed by npm in directory wise or globally and can be invoked/run by npm/npx.
