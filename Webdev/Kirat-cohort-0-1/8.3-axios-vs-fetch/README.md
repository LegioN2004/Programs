# Axios vs Fetch

Axios is a much better alternative to fetch which is an external dependency and we'll need to import that for using using npm whereas fetch is an inbuilt thing that node.js providse out of the box but we'll be using axios for the rest of our life(maybe) because it takes care of the trivial tasks and is a lot smarter than fetch for handling requests.

## how does fetch work

```js
async function main() {
 const response = await fetch('https://sum-server.100xdevs.com/todos', {
    method: "POST",
    body: {
        username: "username",
        password: "password",
    }
    headers: {
        "Authorization": "Bearer random_jwt",

    }
 });
 const res = await response.json();
 console.log(res);
}
```

- the above is the syntax of fetch where we are using the async await syntax instead of the promise syntax and then we are the json to log out whatever we get we are logging out
- for getting json data, we can do the above, but for textual data we'll need to add `.text()` in place of json part
- The default syntax of fetch automatically does a get request
- For other requests we need to define a method like the above, using comma then inside the braces we can do that
- The headers can be set like the above, just like methods, similarly body can be given just like the above.

## Then comes axios

Axios is a much smarter library and as such we have less code and much cleaner syntax. There are a lot of things on top of fetch that we can do in axios but this difference is the first thing to notice

```js
async function mainAxios() {
 const response = await axios.get('https://sum-server.100xdevs.com/todos');
 const response = await axios.post('https://sum-server.100xdevs.com/todos', {
   username: 'morpheus',
   password: 'pistol',
 },{
    headers: {
        "Authorization": "Bearer token",
    }
 });
 console.log(response.data.todos);
}
```

- Here we are just calling the get request using axios and since it handles json data auto, so we doesn't need to using the json() function on the input.
- But whenever we are using axios, we'll get back this data object and so using that we can do different things
- The default syntax of fetch doesn't automatically do a get request, but we need to do a dot operator and then tell to do a get request.
- But for other requests, we can just do `axios.get` or `axios.put` or `axios.post`, etc
- for taking in textual data in axios we don't need to make any changes to the code, the library automatically does that conversion for us.
- For headers in axios, we'll need to include it in the `axios.method_request()`  parentheses separated with a comma. So it goes like first the url, then the second object is the body with the details and the third object will be the headers with the details.
  - **note**:  But in a get request from axios, the second argument is the header since you cannot send a body in a get request. The others like put, post, delete that can send the body, there the second request is the body and third is the header

- The main things that we need to know
  - change request methods
  - send body
  - send headers

- Request config = It means that what do we want to send along with the url, it can be a bunch of things like body, headers, query params, etc.

- ***Another way to write the axios syntax*** like in single object body

```js
const response = axios({
    url: "https://httpdump.app/dumps/d5b31dd3-5d4b-45e5-83c2-f79e07b875b0",
    method: "PUT",
    headers: {
        "Authorization": "Bearer 123",
    },
    data: { // its just the way it is, in place of body we use data instead in this syntax.
        username: "Hello",
        password: "password",
    },
})
```

### Random doubts

```js
const axios = require('axios');
async function main() {
 const response = await fetch('https://www.boredapi.com/api/activity');
 const res = await response.json();
 console.log('-----------------------------');
 console.log(res);
}
async function mainAxios() {
 const response = await axios.get('https://reqres.in/api/users');
 console.log(response.data);
}

main();
mainAxios();
```

> I have made this code and the function runs in this manner like the calls that are given at the end but why do I get the second function's output first even though it has been run after the first function, does it has something to do with the async code, which but it should wait in the callback queue till the first async is resolved why does it run before the first. Help me visualize and understand what is going on here

In your code, you have two asynchronous functions: `main()` and `mainAxios()`. Both of these functions are called sequentially at the end of your script.

When an asynchronous function is invoked, it is added to the call stack and executed. However, if it contains an asynchronous operation such as fetching data from an API (using `fetch()` or `axios.get()`), JavaScript does not wait for this operation to complete before moving on to the next line of code. Instead, it continues executing the rest of the code in the function and returns a promise representing the eventual completion of the operation.

In your case, `main()` and `mainAxios()` are both called in sequence, but they both start executing immediately. `main()` performs a fetch operation using `fetch()`, and `mainAxios()` performs an API request using `axios.get()`. Since both of these operations are asynchronous, JavaScript doesn't wait for them to finish before moving on to the next function call.

The reason you're seeing the output of `mainAxios()` before `main()` is likely due to the fact that `axios.get()` may resolve faster than `fetch()`. This can happen for various reasons, such as differences in network latency or server response times.

To ensure that `mainAxios()` runs after `main()` and to see its output after the output of `main()`, you can `await` the `main()` function call before calling `mainAxios()`:

```javascript
async function run() {
    await main();
    mainAxios();
}

run();
```

This way, `mainAxios()` will be called only after `main()` has completed its asynchronous operation and the data has been fetched.
