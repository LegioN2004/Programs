# notes 

## stacks

head will be named null instead cause it's stack
at starting the 

## Queues

Queue is a collection where the insertion is possible from one end known as "rear" and deletion is possible from the other end known as "front". We can also consider insertion to be from the "front" then the deletion will happen from the "rear". We can choose any one but we'll need to follow the rules

Queues follows FIFO rule, so we'll need to enforce this rule here. Enqueue is insertion and Dequeue is deletion

We won't touch the front part, we'll always insert from the rear end. 


## Trees

<!-- - Trees will be like the DLL and the child which doesn't have any -->
- While entering data if you don't want to enter any child, then you can enter -1. If we return -1, then the it'll return 0 or we can say NULL.
- you will need to recursively call the create function since from one node you'll need to set the right or left child as per needed and so you will have to call the create function recursively