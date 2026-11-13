# Whole AWS revision and certificates management

> Important notes only

- for SSHing into the server, add a ubuntu@(or the machine you are using then @) before the ipv4 dns so that you can be connected otherwise there will be a continuous publickey denied error while connecting. Also give the key 700 permission
- What happens when no port is given to the traffic, in case of reverse proxy
  - http: it is equivalent to sending 80 by default
  - https: it is equivalent to sending 443 by default
    So in this way nginx forwards something from the port 80 to some other port in order to run different servers on the same machine which also provides with lots of shared resources, best savings when hosting and good traffic-resource management.

## Certificates

We have setup everything including the server, dns hosting, reverse proxy and domain names. Now we need to make it secure by having an certificates(we can see that by the huge **Not Secure** on the url bar on top). In the nginx file we'll have a listen on 443 in the end instead of 80 which is usually what the certificate is.

We can do that manually if we have a certificate already bought but we have a Certbot to do this, which works very properly with Nginx. Just need to install it and follow the instructions as per the certbox manual website. For better softwares like payments apps, we need to buy more sophisticated and famous certificates. Certbot gives one for free. SSL certificates can be gotten for free but you do get paid alternatives that are more trustworthy kind of. Then the **Not secure** tag will go off.

Using certbot will automatically assign the certificates to the required websites in the nginx server configuration file. It assigns everything to serve to the https traffic only i.e 443 and whichever one points to http i.e 80, it moves it to the https.

![something like this](./assets/Screenshot%20From%202025-01-15%2017-22-54.png)

And to run the process on the background so that the node index.js doesn't turn off when we turn off the machine can be done using the pm2, which is a process manager which runs the process on the background(pm2 start index.js).
