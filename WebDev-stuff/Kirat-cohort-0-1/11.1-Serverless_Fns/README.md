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
