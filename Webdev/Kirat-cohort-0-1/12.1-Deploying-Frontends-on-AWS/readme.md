# Deploying frontents on AWS

We are deploying on AWS and not vercel because 
- Although vercel and AWS's pricing is the same but on scale AWS gets a lot
cheaper than vercel and as such it is preferred
    - Yes Vercel is a free alternative and is much easier but on scale it gets
    hella expensive so AWS.
    - fun fact: Big compaines gets almost 95% discounts on their AWS bills due to
    high usage.

## storing of data

How Youtube stores videos, pinterest stores images, etc usually known as
objects, those companies store that not in the database but in something known
as **object storage**.

And the famous one is from **AWS** known as **S3** which stands from **Simple
Storage Service**. Every cloud provider has these.

It is like a google drive that gives you a dashboard, stores the media files and stuff, and then returns a link that can be used to give to the users, or use it somewhere. It is like a public google drive link but it has a twist that giving it away like that is not a good practice.

**buckets**: There are buckets that contain organized data, so youtube data will be
in the youtube bucket, pinterest in the pinterest one and so on. There will be
buckets for application wise. To add/store a new file it is easy in the AWS bucket,
it's just drag and drop. Now we get some links to access it, in the dashboard,
but sharing those links is not a good practice(and can't be accessed in some
cases if not allowed to, by default I think) as said above. So we have this
concept of **CDNs** which stands for **Content Delivery Networks**.

## CDNs

For distribution of those objects(or media/data) from object stores, we use
CDNs. It's job is to deliver content. Using an example: This object data is in a server in US but that data is being asked by a lot of people from India. So it would be nice if it can be first sent to a central part in India where it can then be cached and sent to all the other people residing in India.

It says that; There are many object stores in the world, let that be the source.
But as people ask don't share it directly from the S3 url, instead use my CDN
url and connect me to the source. CDN is the middleman in all of this and it says that give me the main location of the file first and I will deliver it to everyone near my location.

The source might be something like `s3.hkirat-cms.aws.com` and if someone comes
to the `cdn.hkirat.aws.com` for some data, it'll first take it from source,
cache it and then send it to the recipients. The returned cached url is
something like `d2svoiaArs2.cloudfront.net`

The famous CDN from AWS is **CloudFront**. It's source might be something
`harkirat-cms.s3.com` or something like that and the cloudfront gives back
something like `d2svoiaArs2.cloudfront.net`. Now if we go to that
gibberish.cloudfront.net, it knows that the source of truth(the place where the
required file on the main server) is `harkirat-cms.s3.com/a.mp4` and it'll do
something more. The CDN has multiple servers all around the world and whenever we fetch from let's say india then it'll first go to the closest server from india or near your location i.e the assam from mumbai, it will first fetch from the source of truth let's say from USA, come to the nearest location, cache in it and then give it to everyone that asks from India and nearby location. So the file now exists in both the places. The cache doesn't happen forever, it just stays under certain condition, let's say 4 hrs and then if no one asks for it the cache will be cleared. 
So CDN's put bunch of *POPs* i.e **point of presence**, and if anyone asks for
something from the cloudfront url, then the user gets served from the closest
pop and ask from the source of truth and cache and then give it. If the source
of truth is asked, it'll be very very slow. The source of truth might be US-east
and then the POPs are what is all around. If it has it serves it to nearby
people and if not then it asks from source of truth.

You can't cache backends but it's very user specific and for every user it'll be
very different for everyone. But *Edge networks* makes sense here which is like
servers near your location but there are no caching.

Now here the cloudfront serves only from normal html,css,js files or React apps
cause they can be converted to html,css and js files. They can't server special
server-sider rendering applications like Next.js. Also they can't be shown
normally, you need something called `serve` that'll be used to show the react
application properly and so we can use that to show the build `dist/index.html` file properly using the cli. You can go to the dist folder and run the serve command by using it globally or using node as the backend. `serve` helps you serve a static site, or your files that you want people to see. This is just we want to upload to **S3** for people to see.

Keep the Block all public access turned on by default, you can change how this
will for further on. It can be very expensive, you would want to just be
distributed by a cloudfront. All the files should be in the root directory, i.e
the index.html.

- First give it a `name` and such
- `S3 Origin` will be the bucket name and 
    - The `origin path` will be something like if you have the index.html file in
    a folder, then you can give the path to it from the root folder.
- In the `Origin Access Control`, the user can set how the cloudfront can access
a specific S3 bucket. It is not publically accessible.
    - If you create one, be sure to click sign requests cause it recommended and
    it is secure.
- The important thing on here is the default root object, which defines how
you'll serve the html file. You can set it to `index.html` so that whenever you
got to an url, you can show `google.com` instead of `google.com/index.html`. If
they don't give anything in the end, then by default it is pointing to the
index.html file. When you are distributing a file you don't want the file path
for it.
    - In the S3 bucket permissions section, you can edit the bucket access
    policy and you can set it to the cloudfront that you have created and as
    such it will be accessible through them only. It can't be accessed
    publically from anywhere else.

- Then the rest of the options like custom domain name and ssl certificates
needs to be added for your s3 to be on your own custom domain.
    - firstly custom domain for your own domain.
    - You can use custom ssl certificate or you can use another provider
        - Then your own custom ssl certificate to show that the domain is yours
        - DNS validation for amazon's way to verify that the site is yours.
        - you will have validation pending for amazon to know so go to the
        domain name provider and in their dns section you can tell where the
        domain points to and there you can point the domain to the cloudfront
        `CNAME name` against the `CNAME value`. **So you need to create a "CNAME"
        record from this subdomain i.e `CNAME name` to point to this value `CNAME value`** in the provider to say that you own that domain
            - So since the user was able to put the right value from the cloudfront to the domain name DNS section i.e the user is valid and owns it and it's been validated. So it'll generate a certificate for the user. Now we'll be able to attach the certificate in the ssl certificate section in the cloudfront settings. And the last thing to do is to point the url of your custom domain to the cloudfront url and it'll work normally.
    - We'll also see that once you hit a page that is not present in the s3, it
      shows up an error page. To make sure that all requests reach index.html,
    we can add an error page that points to the index.html. By default it shows
    something which doesn't properly denote what's wrong. Instead we can make a
    default error page which will properly show that this page doesn't exist. We
    can set this in the error pages section.
    - **Create invalidation**: Caching, a lot of data is cached and to make sure
      that we clear the cache, we can create invalidation that'll invalidate the
      cache, so that when a user enters there a real value comes instead of a
    cached value.
