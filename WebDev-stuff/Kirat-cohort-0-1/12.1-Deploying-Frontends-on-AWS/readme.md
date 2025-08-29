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

The famous CDN from AWS is **CloudFront**.
