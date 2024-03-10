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
- The headers can be set like the above, just like methods

## Then comes axios

Axios is a much smarter library and as such we have less code and much cleaner syntax. There are a lot of things on top of fetch that we can do in axios but this difference is the first thing to notice

```js
async function mainAxios() {
 const response = await axios.get('https://sum-server.100xdevs.com/todos');
 console.log(response.data.todos);
}
```

- Here we are just calling the get request using axios and since it handles json data auto, so we doesn't need to using the json() function on the input.
- But whenever we are using axios, we'll get back this data object and so using that we can do different things
- The default syntax of fetch doesn't automatically do a get request, but we need to do a dot operator and then tell to do a get request.
- But for other requests, we can just do `axios.get` or `axios.put` or `axios.post`, etc
- for taking in textual data in axios we don't need to make any changes to the code, the library automatically does that conversion for us.
