# NOTES random

## linked list from Jenny's lectures

linked list is a list of nodes that contain two parts of data inside it, namely the data and the address of the next node. The last node has a NULL value in the address part. The first node is called the head node. The last node is called the tail node.

we are considering the following linked list structure

![linked list](../../../assets/1linkedListPic.png)

Here we are creating a structure of the nodes of the linked list. Firstly we'll use `struct` to create the type of data it'll have(here int and an address) and then since it'll also contain the data of the next node which is a `struct` so we'll use the same `struct` type inside the original struct to create the node named `next` using a pointer which points to it so as to make that "link"ed list. In this way this linked list structure is created and it goes circle on and on like that recursion.

We also need to create one separately for the head and it'll be defined as null from the starting since it is not supposed to have something in it. It just points to the first node. We have used the struct type here as well because we write the data type of that variable whose address that pointer is going to store.

The memory is still not allocated for the linked list. We'll do that using the `malloc` function in C.

```c
struct node{
    int data;
    struct node *next;
}
struct node *head = NULL, *newnode;

head = (struct node*)malloc(sizeof(struct node));
```

Now to allocate memory we'll need to use the malloc function which is used to dynamically allocate memory in C. It is an inbuilt function which will take in the size which we want to allocate so we'll use the following syntax: `malloc(sizeof(struct node));`.

Data type is struct node which has int which is of size 4 bytes and one is pointer so 4 bytes is to be allocated, so all in all it is 8 bytes of complete block will be allocated.

The malloc function returns a void pointer. And also it will have an address so we'll use a pointer variable to store this. So we'll create another pointer variable `*newnode`, and we'll use this pointer variable whenever we want to create a new node.

Now we'll also have typecast the malloc function to the struct node pointer type. So we'll write `newnode = (struct node*)malloc(sizeof(struct node));`, because we are dealing with a pointer to a node.

And for the data part we can take inputs or we can give it directly. So we'll use `newnode` to access and insert data there since that is why we have created a `newnode` pointer variable. Syntax goes like this: `scanf("%d", &pointer_variable -> structure_data_name);`, i.e `scanf("%d", &newnode->data);`. We can also use the dot operator way, but this arrow way is easy to use

And to end the node, we'll use `pointer_var -> node_var = 0;` `newnode -> next = 0;` to access the address, so we have taken `newnode` as the pointer var and `next` for the address of next node so we can do that using pointer as well.

Now we also have to link the nodes to form a LL. Firstly we'll make the head point to the first node. So we'll need to store the address of the first node in the head so we'll simply do: `head = newnode;` and the head will point to the first node.

There may be cases when `head == NULL`, then we'll keep a if to check for that since we cannot point the head to the new memory address otherwise the previous one will lose its link and the new one will take its place. Else we'll do the next steps in the else part i.e we will be creating more nodes, the `newnode` will have the new addresses and so we'll connect the first one(prev) to the second one using the syntax `head -> next = newnode`

# linked list from CWH

## 14- Linked List creation and traversal

for context `head` is a struct pointer. To get the data of a struct we can use arrow operator to do so. `head -> data` will give us the data of the head node.

to link a second node to the first node we can use the arrow operator to access the next node of the first node and then assign the address of the second node to it. `head -> next = secondNode;`

## 15- Linked List insertion

### Case 1 - Insert at the beginning

### Case 2 - Insert in between

### Case 3 - Insert at the end

### Case 4 - Insert after a certain node

