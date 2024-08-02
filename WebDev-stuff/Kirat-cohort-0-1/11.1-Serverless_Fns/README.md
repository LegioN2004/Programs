# Week 11 = Serverless Functions

## **What are backends servers?**

![servers image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fa242503e-ad8f-4ea1-879b-0dfb70455cda%2FScreenshot_2024-02-10_at_2.34.36_AM.jpg?table=block&id=a6da43e6-4c09-4a26-862e-89c79720d413&cache=v2)

We have used `express` to create a Backend server, which is a server that runs on a certain port and listens for requests. It can be used to serve a website, an API, or even a mobile app. And using that everything till now ran locally which we will not be useful when we'll want users to use our app/website/etc. So we have host it into a servers on the internet so that other people can use it, but doing it on our own is pretty hard, expensive, etc etc and normal people cannot do it. So the big companies made sub-companies to provides servers for rent. And so to deploy it on the internet we nowadays use cloud providers like AWS, GCP, Azure, Cloudflare, etc.

Cloud means that we are using someone else's computer to run our code, and we can rent them to host our own code by paying some fees. We don't have a physical server with us but amazon and other companies has a lot of servers in all places like US, India, etc and we can rent them to run our code.

The way to run it usually is `node index.js` which starts a process on a certain port (3000 for example)

When you have to deploy it on the internet, there are a few ways -

- Go to aws, GCP, Azure, Cloudflare
  - Traditional way to deploy
    - Rent a VM (single Virtual Machine) and deploy your app
  - Production level deployment(renting more than one VM)
    - Put it in an Auto scaling group(change the servers and autoscale as per the load)
    - Deploy it in a Kubernetes cluster

why is it called VM: Because it is a very big physical machine that is divided into many small machines as per need be and people can get access to specific machines. The thing that we are getting access to is something virtual in a very big machine.

There are a few downsides to doing this -

1. Taking care of how/when to scale
2. Base cost even if no one is visiting your website
3. Monitoring various servers to make sure no server is down

What if, you could just write the code and someone else could take care of all of these problems?

## What are `serverless` Backends

"Serverless" is a backend deployment in which the cloud provider dynamically manages the allocation and provisioning of servers. The term "serverless" doesn't mean there are no servers involved. Instead, it means that developers and operators do not have to worry about the servers.

The name can be misleading, as there are still servers involved in the process. However, the cloud provider manages the servers, and we developers do not have to worry about them.

The cloud provider just makes sure that of autoscaling, monitoring, etc. If no one visits it will have pretty much no server running. As soon as someone visits, it will start a server and run the code. If there are 20 people visiting, it will start more servers. If a lot of people are visiting, it will start a lot of servers, no really servers but yeah.

Easier definition: What if you could just write your express routes and run a command. The app would automatically

- Deploy
- Autoscale
- Charge you on a per request basis (rather than you paying for VMs)

Problems with this approach

- More expensive at scale
  - Like if you hit facebook, or smaller like swiggy, zomato, etc which are good scaled applications, then a better appproach will be handling the servers yourself in the cloud, since the per request cost is very high. Other than that for smaller usecases serverless is a good approach.
- Cold start problem
  - If no one visits your website for a long time then they will not charge anything and as such there will not be a single miniscule server that will be running. The first person to visit will have to wait for the server to start. This is called a cold start.
  - To solve this there are some hacks like pinging the server every 5 mins so that it doesn't go to sleep; or warm pool which is like keeping a small server up everytime and then it can autoscale up or down depending on the traffic and load

### Famous serverless providers

There are many famous backend serverless providers -

- AWS Lambda

  [https://aws.amazon.com/pm/lambda/?trk=5cc83e4b-8a6e-4976-92ff-7a6198f2fe76&sc_channel=ps&ef_id=CjwKCAiAt5euBhB9EiwAdkXWO-i-th4J3onX9ji-tPt_JmsBAQJLWYN4hzTF0Zxb084EkUBxSCK5vhoC-1wQAvD_BwE:G:s&s_kwcid=AL!4422!3!651612776783!e!!g!!aws lambda!19828229697!143940519541](https://aws.amazon.com/pm/lambda/?trk=5cc83e4b-8a6e-4976-92ff-7a6198f2fe76&sc_channel=ps&ef_id=CjwKCAiAt5euBhB9EiwAdkXWO-i-th4J3onX9ji-tPt_JmsBAQJLWYN4hzTF0Zxb084EkUBxSCK5vhoC-1wQAvD_BwE:G:s&s_kwcid=AL!4422!3!651612776783!e!!g!!aws%20lambda!19828229697!143940519541)

- Google Cloud Functions

  <https://firebase.google.com/docs/functions>

- Cloudflare Workers

  <https://workers.cloudflare.com/>

![cloudflare image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F863715ea-b0ef-40c0-b446-e45704d73d07%2FScreenshot_2024-02-10_at_2.48.34_AM.jpg?table=block&id=621a9360-0dc0-4d63-95e7-53681ace6195&cache=v2)

When should you use a serverless architecture?

- When you have to get off the ground fast and don’t want to worry about deployments
- When you can’t anticipate the traffic and don’t want to worry about autoscaling
- If you have very low traffic and want to optimise for costs

When should you not use a serverless architecture?

- When the scale increases
- When the team size increases, and costs go up
- It is slower than your own infrastructure.

## Cloudflare workers setup

What Cloudflare does is that it prevents what's called DDoS attack which stands for Distributed Denial of Service attacks. The main reason is this due to which Cloudflare is popular.

The dashboard is similar to a lot of the other cloud providers like GCP, AWS, etc, with a lot of buttons for different tasks and services which they offer. There will be a lot of different named buttons which their own style of naming something but these will be similar across other providers, in the end they're providing servers, containers, storage, kubernetes clusters, domain management, etc etc 10 to 15 things extra, so does others.

1. Domain registration section: If you have a domain, or want to buy one or want to point it to something else, we can go here.
2. Analytics & Logs: For tracking how many people visit the website and other data.
3. Turnstile: Works for preventing DDoS attacks, those capchas and all.

We'll be working with workers and pagers for today which _Builds serverless functions with Workers. Deploy websites and full-stack applications with Pages_. This is what happens when we just provide the code and the servers handle everything themselves.

```ts
export default {
  async fetch(request, env, ctx) {
    return new Response("Hello World");
  },
};
```

After pressing **Create new worker** in the **Workers & Pages** section this small code got hosted in some place with a [url](https://muddy-math-a156.milindabarua04.workers.dev/) and when opened the control reaches that code in the print line and then returns "hello world". This is similar to the `app.get` but it handles all the http requests for any routes. If you are going to show out some json object, then it'll print out that json object as is.
The same can be used to create fullstack backend applications and the best part is that you won't need a credit card or won't have to pay anything.

## **How cloudflare workers work?**

This is a very interesting topic to learn about but not that relevant, there is a blog post below that will take you through the nitty gritty of all that. It is much faster than AWS Lambda which they claim and what sort of architecture they use.

There is a detailed blog post - [https://developers.cloudflare.com/workers/reference/how-workers-works/#:~:text=Though Cloudflare Workers behave similarly,used by Chromium and Node](https://developers.cloudflare.com/workers/reference/how-workers-works/#:~:text=Though%20Cloudflare%20Workers%20behave%20similarly,used%20by%20Chromium%20and%20Node). This is a trimmed down version of that blog.

💡 Cloudflare workers DON'T use the Node.js runtime. They have created their own runtime. There are a lot of things that Node.js has.

So what they did is use a big runtime that takes all the things that is being asked to run as a worker and run them while scaling them using their own runtime since running with a new node.js process everytime will be very unoptimal. While the former does come with a few issues as well but that will be fixed.

![image from the blog](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F34612f53-8340-455b-9ea5-a7ecbfed76e7%2FScreenshot_2024-02-10_at_3.51.07_AM.jpg?table=block&id=05510132-8f7d-448b-bd2a-0a03319c647f&cache=v2)

They have their own runtime and they have bunch of their servers all around the world which are running this runtime. So whenever you start a process, it runs it on one of these servers based on the location and other parameters.

### **Isolates vs containers**

![image 2 from the blog](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Feac4cf16-3350-4f8b-aa6e-98322a23d7fa%2FScreenshot_2024-02-10_at_3.54.02_AM.jpg?table=block&id=dde817ce-f77f-4a17-add4-f8297d8107fe&cache=v2)

Isolates as shown in the pic is something like there will be either several node.js process that run the code separately but in Cloudflare there is something like one node.js process that will run one index.js file and that file will run all the code of different users separately without them interfering with each other, and also that run happens based on who specific region and its server. Why do we need to know: There has been a new custom JavaScript runtime from AWS as well to compete with this.

## **Initializing a worker**

To create and deploy your application, you can take the following steps -

- Initialize a worker
  `npm create cloudflare -- my-app`
  Select `no` for `Do you want to deploy your application`
- Explore package.json dependencies
  `"wrangler": "^3.0.0"`
  - wrangler is the only dependency here. This is the thing that is technically the cli for cloudflare workers. It is what lets us deploy our code to cloudflare, and brings the runtime locally to run it locally, etc. That is the only dependency here and we never need to install anything else, like express, etc. We don't need to write the port, etc stuff here and as such it is significantly different and easier from how we wrote code earlier, where we own the server logic. We will need to work with the http server, etc stuff here, but not about the port, etc stuff.
  - Notice `express` is not a dependency there
- Start the worker locally
  `npm run dev`
- How to return json?: We can put the line `return Response.json({message: "hi"})` and it will return the json object as is.

```ts
export default {
  async fetch(
    request: Request,
    env: Env,
    ctx: ExecutionContext,
  ): Promise<Response> {
    return Response.json({
      message: "hi",
    });
  },
};
```

Some explanation of the stuff that is provided after the cloudfare app initialization command runs:

- Firstly it lets you create a workers
- There is a durable object option which is like a serverless database, which is like a storage that goes up and down like eg: neon.db, they take care of the storage.
- website or web app: for normal websites or web apps
- Scheduled worker which means something that runs everyday or in some schedule, eg: let's say you want to send emails everyday to people; or you want to clean up the database every night. So we can use something like this called "cron jobs"
- Rest of can be tried later on for other usecases

```shell
> npx
> create-cloudflare my-app


using create-cloudflare version 2.22.3

╭ Create an application with Cloudflare Step 1 of 3
│
├ In which directory do you want to create your application?
│ dir ./my-app
│
╰ What type of application do you want to create?
  ● "Hello World" Worker
  ○ "Hello World" Worker (Python)
  ○ Website or web app
  ○ Example router & proxy Worker
  ○ Scheduled Worker (Cron Trigger)
  ○ Queue consumer & producer Worker
  ○ Co-ordination / multiplayer API (using Durable Objects)
  ○ API starter (OpenAPI compliant)
  ○ Worker built from a template hosted in a git repository
```

Then it'll ask for TS or not, it is recommended to choose TS.
And lastly if you are not connected to the cloudflare account through the terminal then you are supposed to press No to the deploy your application part since it'll not know where to deploy

### **Question - Where is the express code? HTTP Server?**

Cloudflare expects you to just write the logic to handle a request.
Creating an HTTP server on top is handled by "cloudflare" and handled by "wrnagler" locally on our machine

### **Question - How can I do `routing` ?**

In express, routing is done as follows - (we worry about the methods, headers, the body, the query parameters, etc)

```ts
import express from "express";
const app = express();

app.get("/route", (req, res) => {
  // handles a get request to /route
});
```

We cannot write code like this or install express in cloudflare workers. We will have to write the routing logic only.

How can you do the same in the Cloudflare environment? We'll have to write the following code in order to do that, and most of the server logic is pre-written by the cloudflare folks in order to make our life easier.
What we worry about are: the methods, headers, the body, the query parameters, etc

So whenever we write this function we get a **`request`** object which gives access to methods, headers, body, routes and many more which we'll see later on. The names may be different from  what we used in express but they have the same functionality

```ts
export default {
  async fetch(
    request: Request,
    env: Env,
    ctx: ExecutionContext,
  ): Promise<Response> {
    console.log(request.body);
 // some very complex code and regex for extracting the methods
  let url = 0;

  if (request.method === 'GET') {
   if (url === '/users') {
    console.log('hit the users endpoint');
   }   console.log(request.headers);
      // -----------------------

    if (request.method === "GET") {
      return Response.json({
        message: "you sent a get request",
      });
    } else {
      return Response.json({
        message: "you did not send a get request",
      });
    }
  },
};
```

On running the code we get the following output from the console, null here means that we did not send any body in the request and we will get different outputs for different requests like POST, PUT, DELETE, etc. But the thing is that we get all the details of the request and all but we'll have to write very complex code to extract that info and make the application properly as per need. This is how it was intended to be written at the starting but eventually libraries came into the picture that made it easier to write the code.

- misc stuff
  - Why do we have `Promise<Response>`?: Because the fetch function is an async function, and async functions return promises. The promise will resolve to a response object. Because eventually we'll have a async await usecase like taking data from the database which will be async and as such we'll have to await and so we'll surely have to return a promise. You don't need to specifically write `Promise<Response>` since it can infer automatically but it is a good practice to write it.

```shell
null
Headers(11) {                                                                                                                         
  'accept' => 'image/avif,image/webp,image/png,image/svg+xml,image/*;q=0.8,*/*;q=0.5',                                                
  'accept-encoding' => 'br, gzip',                                                                                                    
  'accept-language' => 'en-US,en;q=0.5',
  'dnt' => '1',
  'host' => '127.0.0.1:8787',
  'priority' => 'u=6',
  'referer' => 'http://127.0.0.1:8787/',
  'sec-fetch-dest' => 'image',
  'sec-fetch-mode' => 'no-cors',
  'sec-fetch-site' => 'cross-site',
  'user-agent' => 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:128.0) Gecko/20100101 Firefox/128.0',
  [immutable]: true
}
[wrangler:inf] GET /favicon.ico 200 OK (31ms)   
```

💡How to get query params - <https://community.cloudflare.com/t/parse-url-query-strings-with-cloudflare-workers/90286>

Cloudflare does not expect a routing library/http server out of the box. You can write a full application with just the constructs available above.

We will eventually see how you can use other HTTP frameworks (like express) in cloudflare workers.

## **Deploying a worker**

Now that you have written a basic HTTP server, let’s get to the most interesting bit — `Deploying it on the internet`. We'll see how we can use the `wrangler` cli to deploy the code to the cloudflare workers. We'll use the code `npx wrangler login` which will open up the browser from the cli to login to your cloudflare account. After that we will be logged in after allowing the warnings in the cloudflare site. Then we can publish the code using the `npm run deploy` which under the hood runs the command `wrangler deploy` and since it has access it'll publish the site to the account which will give us a url which we can use to access the code. So we have a backend application that is running for free on the internet for a very long time unless there is some heavy traffic hitting it. We can do this for a frontend application as well.

We use `wrangler` for this (Ref <https://developers.cloudflare.com/workers/wrangler/>)

![wrangler image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fede31e52-2585-4793-ae31-646e4011419b%2FScreenshot_2024-02-10_at_3.58.30_AM.jpg?table=block&id=dcd69cc6-23b5-4435-bad4-c64f959adef9&cache=v2)

- Step 1 - Login to cloudflare via the `wrangler cli`

    `npx wrangler loginCopy`

    ![wrangler second image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Ffa81c66a-188f-4a71-91a6-b7421430a811%2FScreenshot_2024-02-10_at_3.58.51_AM.jpg?table=block&id=f98b270f-48d4-44d5-bbf7-b0cf93758d18&cache=v2)

- Step 2 - Deploy your worker

    `npm run deployCopy`

    If all goes well, you should see the app up and running

### **Assigning a custom domain**

You have to buy a plan to be able to do this

You also need to buy the domain on cloudflare/transfer the domain to cloudflare

![wrangler image third](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F2cde6fd6-3b5e-40db-92dd-8dd42d78072b%2FScreenshot_2024-02-10_at_4.06.21_AM.jpg?table=block&id=48d79027-bffe-4c5a-a308-582671ab0098&cache=v2)

## **Adding express to it**

Why can’t we use express? Why does it cloudflare doesn’t start off with a simple express boiler plate?

### **Reason 1 - Express heavily relies on Node.js**

The following is the link to why Cloudflare workers don't support express, which says that they have a bunch of node.js things that the workers don't have i.e their runtime doesn't support, so they have provided some workarounds. Also express didn't work for a very long time in the other runtime that has been developed recently, "Bun.js" which had like a different javascript engine and as such it shows its deep dependency in node.js.

<https://community.cloudflare.com/t/express-support-for-workers/390844>

![thread image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F8c0620c6-3b41-468f-a76d-a34538aa78bb%2FScreenshot_2024-02-10_at_4.16.25_AM.jpg?table=block&id=fbfb6e8b-2ec7-48e8-bac9-cdb9f4caa9a0&cache=v2)

<https://github.com/honojs/hono>

### **You can split all your handlers in a file**

Sometimes there are people who use express for the backend but they want to move their application to Cloudflare workers. So what they do is they split all their handlers in a file and then they can use that file in the cloudflare workers. This is a good way to do it.

Create a generic `handler` that you can forward requests to from either `express` or `hono` or `native cloudflare handler`

![first image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fa683cec8-a81a-41cb-82b9-8a4b11c20101%2FScreenshot_2024-02-10_at_4.15.26_AM.jpg?table=block&id=7bfd09ff-3394-4025-a28e-ebc064ce2332&cache=v2)

- what is a classic serverless option here in the image: It is like a serverless thing which doesn't have its own runtime and can run any node.js application

![second image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fd56c54ff-12ee-4b9e-bda6-699641b27bea%2FScreenshot_2024-02-10_at_4.37.24_AM.jpg?table=block&id=44cd75c5-27b8-4e0b-bf94-d4c1bf546581&cache=v2)

If we look at the express router/ `app.get()` handler we will get three things there: the user id, the database call, and the data returned. So they suggested to make the code as generic as possible, i.e abstract out the 95% logic as much as possible in other file(s) that doesn't heavily rely on node.js and only does the DB calls since this works for both node.js and workers. And the rest of the 5% logic that doesn't work in workers you can add in the main file and then add the generic functions for the main logic usage and now we can deploy to cloudflare. So we'll need to write it twice the 5% part but the 95% part will be put together separately and structured in such a way so that we can easily move from one place to another. In the end we will use a library.

## **Using hono**

### **What is Hono**

<https://hono.dev/concepts/motivation>

![motivation](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Ff31ed7e5-5d53-40d5-81ef-f60e385a1867%2FScreenshot_2024-02-10_at_4.39.42_AM.jpg?table=block&id=09120297-ab1f-4094-b610-acf9e71e9e16&cache=v2)

It is not exactly an http server but a routing engine that routes the requests to certain places as per required and gives us an easier way to write code similar to express.

### **What runtimes does it support?**

![supported runtimes](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F9d9b7350-fb08-49b8-82d1-cffc4c73a349%2FScreenshot_2024-02-10_at_4.40.01_AM.jpg?table=block&id=5bf712cb-e458-40f2-a57f-a336d49faaed&cache=v2)

### **Working with cloudflare workers -**

1. Initialize a new app

```shell
npm create hono@latest my-app
```

2. Move to `my-app` and install the dependencies.

```shell
cd my-app
npm i
```

3. Hello World

- It is very similar to express, but with a few differences in the API.
<!-- - It has a `context` object that is passed to the handler function. This object has a lot of useful methods like `text`, `json`, `html`, etc. that can be used to send responses. It also has a `req` object that has methods to get the request body, headers, etc. It is very similar to the `req` object in express.  -->
- The `c` contains both request and response objects which is similar to express but not separately like in express.
  - You can do `c.text`, `c.json`, `c.html` etc to send responses in the corresponding formats.

```ts
import { Hono } from 'hono'
const app = new Hono()

app.get('/', (c) => c.text('Hello Cloudflare Workers!'))

export default app
```

### **Getting inputs from user**

```ts
import { Hono } from 'hono'

const app = new Hono()

app.get('/', async (c) => {
  const body = await c.req.json()
  console.log(body);
  console.log(c.req.header("Authorization"));
  console.log(c.req.query("param"));

  return c.text('Hello Hono!')
})

export default app
```

- The above shows how to get the body, headers, and query parameters from the request object in Hono.
  - firstly we'll need to async await on th req since it is getting converted to json.
  - Also we have the c object which can be used like `c.req.header("Authorization")` (replace the authorization header to other by just writing out the correct name in its place) to get the headers, `c.req.query("param")` to get the query parameters, etc.
- We must use the correct method as given in the code or else it'll throw 404 error. So after sending in the proper things we get the response correctly in the console. And we have access to everything that we had in express.

```shell
{ message: 'heloooooooooooo' }
123123
2
[wrangler:inf] POST / 200 OK (47ms) 
```

💡 More detail - <https://hono.dev/getting-started/cloudflare-workers>

### **Deploying**

Make sure you’re logged into cloudflare (`wrangler login`)

```shell
npm run deploy
```

## **Middlewares**

💡 <https://hono.dev/guides/middleware>

### **Creating a simple auth middleware**

```ts
import { Hono, Next } from 'hono'
import { Context } from 'hono/jsx';

const app = new Hono()

app.use(async (c, next) => {
  if (c.req.header("Authorization")) {
    // Do validation
    await next()
  } else {
    return c.text("You dont have acces");
  }
})

app.get('/', async (c) => {
  const body = await c.req.parseBody()
  console.log(body);
  console.log(c.req.header("Authorization"));
  console.log(c.req.query("param"));

  return c.json({msg: "as"})
})

export default app
```

```ts
async function authMiddleware(c: any, next: any) {
 if (c.req.header('Authorization')) {
  // do validation and other hundreds of things here
  next();
 } else {
  return c.text("You don't have proper access");
 }
}

app.use(authMiddleware);
```

- Here we can find out the types of c and next.
- using that `c` object we can authenticate the user and then use the `next()` just like we did in express to forward the code for the next set of statements, following it.
  - It is known as the context object which contains the context of the request, i.e both the request and response
- we can directly use the middleware like the one above which is `use` (it runs it for every request that comes after it, not recommended to use it like that tho) or we can pass it as a middleware function like we did in express.
- **NOTE**: It is required to await on the next function if there is some code written after it. Like in cases where we want to check how much time the next set of statements take to run.

💡 Notice you have to return the `c.text` value
