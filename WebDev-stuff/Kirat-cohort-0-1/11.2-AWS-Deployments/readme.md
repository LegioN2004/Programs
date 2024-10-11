# AWS Deployments

## What is AWS

AWS is Amazon’s `cloud` service. Earlier datacenters were a thing that big companies had in order to store their data but cloud services weren't. We didn't have those websites where we can click a button and that provided us with the same services where we can rent servers, store our data and another company handles all other things for you.

It let’s you

1. Rent servers
2. Manage domains
3. Upload objects (mp4 files, jpgs, mp3s, ....... in something called S3 object store)
4. Autoscale servers
5. Create k8s clusters

The offering we will be focussing on today is `Renting servers`

## EC2 servers

VMs on AWS are called `EC2 Servers`. This was the biggest offering by AWS.

EC2 stands for Elastic compute Version 2.

1. `Elastic` - Can increase/decrease the size of the machine
2. `Compute` - It is a machine
3. `2` - It is the second version of the machine

**Compute** is a fancy word for a machine that can run code.

You can spin up a new EC2 instance from the aws dashboard. EC2 instances are virtual machines that run on AWS infrastructure. You can choose the size of the instance, the operating system, and the software that runs on the instance.

![ec2 image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Ff0ee3fa6-e989-4982-a580-e8039c48ae62%2FScreenshot_2024-02-11_at_6.33.46_AM.png?table=block&id=3dc2315f-4c68-4d34-995e-c56ba0d08feb&cache=v2)

In the dashbaord after going to instances,

- we need to click on `Launch Instance` to create a new instance.
- Then we need to choose the Ubuntu Machine Image which is the OS that we want to run on the instance.
- Then we need to choose the instance type which is the size of the instance.
- Then we need to configure the instance details like the number of instances, network, etc.
- Then we need to add storage to the instance.
- We'll then use the t2.micro which is the free tier eligible instance and enough for our small usecase.
- On clicking Launch instance, a new machine will be generated but to connect to it securely we need to create a key pair. It is one easy way to do it and more manageable. Then we can ssh into the machine using the key pair. We then get a downloade .pem file which we can use to connect to the machine, it should be super secret.

**Why the need for an cloud providers**: Basically means devs doesn't need to worry about where the code is running, we don't need to worry about the machines. There are very big tech companies that have their own data centers with tons of machines and compute deployed around the world and they provide consumers like individuals, companies and businesses with cloud services by renting those machines to anywhere in the world.

Why is this beneficial: We are simple people with some node.js code that we want to deploy on the internet and as such we won't be able to directly get access to a server rack that will run our code. So we go to cloud providers and ask to launch an instance like a small machine from your nearby data center so that people all around the world can access my code. We can't deploy it on our own machine such that people from anywhere can access it because we don't have what's called a public IP and it is limited. Anyone on the internet can access google.com because it has a public IP and going to google.com will redirect you to the IP of the server that is running google.com and we don't have those. So we need to rent a machine from a cloud provider to run our code.

### networking settings

Whenever we start a machine in the internet, when we run node index.js we go to localhost:3000, but how to access of this server publically on the internet. So every machine we start has a public IP and we can access it from anywhere in the world so the port will be like (say we have a public IP of 3.1.59.7) 3.1.59.7:3000. We'll be able to access this from anywhere in the world. What we do now is that we point a domain name to it.

So if we are running something in that port we need to specifically tell the machine to keep the port open. Let other people access that port

Firewall (security groups): A security group is a set of firewall rules that control the traffic for your instance. Add rules to allow specific traffic to reach your instance. Controls everything that we have exposed on the internet.

We have settings called security groups which has

1. allow SSH traffic: It stands for **secure shell** and is used to connect to the machine. We'll need to open the SSH port on the machine which by default is port 22. So the option is already selected in the security group.
2. Then we'll allow the https traffic from the internet part so that people can access it from anywhere
3. Then we'll allow the http traffic as well

What is https and http ports? Since we'll be running in a port of 3000, the website will be something like this with the domain "google.com:3000" but we don't see that actually cause this is hidden and the browser automatically redirects to the port **80 which is the http port** and **443 is for the https port** which is by default. So we need to open those ports as well. If we don't give anything after the colon, it is assumed to be those defaults.

HTTPS is a more secure version of HTTP.

We want people to access our website from anywhere in the world and we need to open the ports so we do that by checking out those http and https boxes.

if we do app.listen(3000) in our node.js code, we need to open the port 3000 as well. So that doing the 1.3.4.5:3000 redirects to the server that is running the node.js process.

We can open more ports as well.

Good practice is to open the HTTPS port open and the rest should be closed. So if someone hits the ports `:33`, `:3000`, etc, AWS will reject the request and only the 443 will work. But if we make our code like `app.listen(443)`, and is our application secure and is someone hits the server on https, not exactly.

It also says this: **Rules with source of 0.0.0.0/0 allow all IP addresses to access your instance. We recommend setting security group rules to allow access from known IP addresses only.** Yeah we'll do that whenever necessary. But I have made it limited to my public ip, 0.0.0.0/0 means all IP addresses in the world can access it.

### instances

firstly

- name is the name of the instance
- instance id is the unique id of the instance
- instance state is the state of the instance, running or stopped
- instance type is the size of the instance, t2.micro, t2.small, c5 family etc
- status check tells us whether or not it is working
- cloud providers on login shows lots of locations that they have data centers in and this `availability zone` is the location of the data center where the instance is/will be running
  - There are a lot but we are using the one in Asia specificallly in Mumbai, `ap-south-1a`. availability zone means that inside the data center there are many availability zones far from each other and not connected to each other so that if one breaks the other can act as a backup
  - The one inside Asia Pacific (Mumbai) is `ap-south-1a`, a is the availability zone and 1 is the data center. There are many data centers in Mumbai and this is the first one. Basically this is how they have divided the data centers.
- And the public DNS
- And the public IP. Our machines don't have this public IP and so this is the main reason for creating in a server in the cloud since it has those public IPs.

Now if we hit the public IPs with the ports we have given access to be hit, we'll get unable to reach and the request will fulfill but if we try any other port we'll see that the request gets stuck. In order to make that specific port accessible we can select the server in the AWS console, go to security tab and make it accessible by adding it in the inbound rules.

Now to connect to the ubuntu machine, i.e SSH into it and so we need to use the downloaded key pair .pem file and then use the command `ssh -i key_file_name.pem ubuntu@the_public_ip` to connect to the machine.

google is something similar, it hits to something like `172.123.24.422:433` and then it redirects to the server that is running the google.com website. So we need to open the ports that we want to be accessible.

SSH says that first error, because it wants the file .pem to be secure and so we need to change the permissions of the file to be secure. So we need to do `chmod 700 key_file_name.pem` to make it secure and then we can connect to the machine. These chmod command defines the permissions of the file and 700 means that the file is only accessible by the owner and no one else can access it. So we need to make the file secure so that no one else can access it. If its a pem file it should be very restricted.

If there is no internet connection, go to the `/etc/resolv.conf` file in the server and add this `nameserver 8.8.8.8` to the file.

Inbound rules means the rules that are allowed to come in and outbound rules means the rules that are allowed to go out. So we need to open the ports that we want to be accessible. So the ports that will be set open in those rules will be availabile to be accessed from the internet.

Now on accessing in this format in the browser `public_ip:port_no` we'll get the results directly in the browser. Also we can use the url given by the AWS console to access the server but we'll have to beautify as well.

We should never make our node.js port listen on the default ports like 80 and 443 because they are reserved for the http and https ports.

ipv4 is smaller and ipv6 is bigger, companies like jio airtel use ipv6 so as to give out more IPs to people. So we can use ipv6 as well.

## Creating a new EC2 server\*\*

### **1. Click on `Launch a new instance`**

![first image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fce12b6eb-5d32-4cfa-bf79-049356382237%2FScreenshot_2024-02-11_at_6.35.37_AM.png?table=block&id=62284127-f634-49e1-8372-ae190cbe5e53&cache=v2)

### **2. Give a name**

![sec img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F99db06f8-46b8-4724-97b0-edf8eceddc2a%2FScreenshot_2024-02-11_at_6.40.08_AM.png?table=block&id=dc8d9b86-099f-43d9-b591-b73fba177838&cache=v2)

### **3. Select an OS**

![third img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F3d164ebc-9528-40fe-a313-669a9346657e%2FScreenshot_2024-02-11_at_6.40.15_AM.png?table=block&id=1b5a057c-15c7-4306-9c7c-b777110ce930&cache=v2)

### **4. Select size**

![4th img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F4fad1e6c-5929-4619-87c9-6dd50bc4dc79%2FScreenshot_2024-02-11_at_6.41.19_AM.png?table=block&id=688a2e65-4d63-4976-a9e8-9b0a64038ae5&cache=v2)

### **5. Create a new Key pair**

![5th img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fb988d06e-447a-476f-9599-b1b98a561f11%2FScreenshot_2024-02-11_at_6.42.11_AM.png?table=block&id=1f313b84-ebcc-4ac1-a118-7abcd4f33e13&cache=v2)

### **6. Select Size**

![6th img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F4f28c0ac-7f35-4200-a0e6-21df5ac982b3%2FScreenshot_2024-02-11_at_6.38.05_AM.png?table=block&id=f32975d3-a6ee-4a3b-a666-33eb338ff4fe&cache=v2)

### **7. Allow traffic on http/https**

![7th img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Faa98e7a1-aedf-4a1a-8e53-edb938b1b476%2FScreenshot_2024-02-11_at_6.37.57_AM.png?table=block&id=7f497c85-0715-467d-adcf-1bfc99fe7791&cache=v2)

# SSH into server

1. Give ssh key permissions\*\*

```sh
chmod 700 kirat-class.pem
```

**2. ssh into machine**

```sh
ssh -i kirat-class.pem ubuntu@ec2-65-0-180-32.ap-south-1.compute.amazonaws.com
```

**3. Clone repo**

git clone https://github.com/hkirat/sum-server

> 💡If your aws machine shows you the following error, your aws machine doesn’t have access to the internetSolution - https://www.tecmint.com/resolve-temporary-failure-in-name-resolution/

**4. Install Node.js**

https://www.digitalocean.com/community/tutorials/how-to-install-node-js-on-ubuntu-20-04

**5. Install all dependencies**

```sh
cd sum-server
npm install
```

**6. Start backend**

```sh
node index.js
```

![img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fd91828ba-3177-4433-bdd4-7cbb5cca3841%2FScreenshot_2024-02-11_at_6.48.19_AM.png?table=block&id=fbe9df04-332b-43a8-89e2-e1bed09efa74&cache=v2)

### Reverse proxies and Nginx

We have deployed our code on the internet which is running on the port 8080 but the url is very ugly like `ec2....amazonaws.com:8080` and we want to make it look like `mywebsite.com` and so we need to use a reverse proxy.

And also we have one process already running on the port 80 and we can't run another process on the same port if we want to have 2 backends deployed in the same machine. So to run in this way it makes sense to use the reverse proxy.

Let's say we are running one process on 8080 and another on 8081 having url backend1.com and backend2.com, then we'll run something else on port 80 which is called a reverse proxy and this can decide that when backend1 gets hit then the request should go to 8080 and when backend2 gets hit then the request should go to 8081. This is called a reverse proxy. So we can have multiple backends on multiple ports running on the same machine and the reverse proxy will decide which backend to hit.

Port 80 thing is not node.js process or another process.

Proxy: A proxy server is a server that acts as an intermediary for requests from clients seeking resources from other servers. Sometimes in a college network or some org network we can see that we can't access certain websites and that happens because the requests gets routes through a proxy which rejects that request. A VPN is a similar example where it allows certain requests which are blocked in your country by working as a proxy and it routes the request through another IP which is able to access that.

Inside the final service that works, the thing that listens on port 80 is a reverse proxy

When we provide a normal url it always goes to the reverse proxy(http or https/ 80 or 443 port) whose job is to route the requests as per the domain to their respective backends(something that it may have more than one).

## clone and setup the repo

Clone the repo https://github.com/hkirat/sum-server

## Step 6 - Try hitting the server**

You have an ip/DNS that you can hit to access your ec2 server

![image](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fc937d600-8c4e-4c69-8f94-b08d7f47b6af%2FScreenshot_2024-02-11_at_6.54.09_AM.png?table=block&id=39e74650-04ba-490c-9c29-f99dad477d0e&cache=v2)

### **Try visiting the backend**

```jsx
your_domain:3000
```

Notice you `can’t` visit the website during this time

![more img](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F90f755af-9a75-4875-a126-1410feef6917%2FScreenshot_2024-02-11_at_6.57.17_AM.png?table=block&id=334e0f49-6d1e-4eeb-bb9d-405efa43671e&cache=v2)

### **Security group**

![moree images](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F1b991aa0-bc28-4642-83b9-5101a4ba4f4d%2FScreenshot_2024-02-11_at_6.59.14_AM.png?table=block&id=45e8ee3d-7edd-4160-85c5-dccc8abb6df8&cache=v2)

You can either open port 8080, or process on port `80`

![moreee images](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Febe18a38-147c-4866-9a30-71bace5a829c%2FScreenshot_2024-02-11_at_7.01.21_AM.png?table=block&id=48e9db64-d800-4c6e-87e9-1b890aa215e3&cache=v2)

![moreeeee images](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F5cb4a372-d4db-4698-94c6-37ccaccf9fab%2FScreenshot_2024-02-11_at_7.02.59_AM.png?table=block&id=0c572982-e36c-4658-934d-6753620b7f93&cache=v2)

```jsx
http://your_domain:8080
```

## Step 7 - nginx

https://www.nginx.com/resources/glossary/nginx/

Nginx can be used for a lot of stuff but we'll primarily use it for reverse proxying

![](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F0263a8e2-e824-45b1-901c-34b635308f87%2FScreenshot_2024-02-11_at_7.05.48_AM.png?table=block&id=ff5b15cd-c123-4238-a3bb-aada54dd8407&cache=v2)

### **What is a reverse proxy?**

![](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F2f9a47c6-e0ae-4819-a24e-f9110af8afd6%2FScreenshot_2024-02-11_at_7.12.50_AM.png?table=block&id=e8fc9376-df68-4487-8363-6a3aa4a8ebd8&cache=v2)

### **Installing nginx**

```jsx
sudo apt update
sudo apt install nginx
```

This should start a `nginx server` on port 80. After installing nginx auto sets up and runs on the port 80 which we can see as well when we visit the ipv4 DNS or given url instead of node.js. Since we haven't told anything to do so it doesn't do anything.

Try visiting the website

![](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2Fbc6b7e9a-9119-43d1-bebf-b870fecf66bf%2FScreenshot_2024-02-11_at_8.24.36_AM.png?table=block&id=06f6c8ad-ebd4-485b-ad72-9be5f4b6d6da&cache=v2)

Then we can take the public IP and in the domain settings, point our custom domains to that IP.

### **Create reverse proxy**

The configuration of the nginx file is in the file `/etc/nginx/nginx.conf` which we see in when visiting the url. Since it can also do web-serving, so by default it can and shows an html page.
To make it a reverse proxy we need to make changes in the conf file

```jsx
sudo rm sudo vi /etc/nginx/nginx.conf
sudo vi /etc/nginx/nginx.conf
```

```jsx
events {
    # Event directives...
}

http {
	server {
    listen 80;
    server_name backend1.100xdevs.com;

    location / {
        proxy_pass http://localhost:8080;
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';
        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
    }
	}
}
// if we want more backends, we can copy paste and make the necessary changes for the new and add it in the file
```

After changing the configuration you need to restart and it can be done with the following cmd.

```jsx
sudo nginx -s reload
```

### **Start the Backend server**

```jsx
node index.js
```

### **Visit the website**

```jsx
https://backend1.100xdevs.com/
```

![](https://www.notion.so/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F085e8ad8-528e-47d7-8922-a23dc4016453%2F6f3c6675-2178-43e1-bbfe-a90e391db2f4%2FScreenshot_2024-02-11_at_8.50.59_AM.png?table=block&id=8a6d5e90-7897-498b-bdd3-bc2ab958c683&cache=v2)

# 11.3 Certificates, extension of the pervious video
