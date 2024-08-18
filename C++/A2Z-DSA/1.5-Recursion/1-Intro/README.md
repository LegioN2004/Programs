# Intro to Recursion

## What is Recursion?

**Recursion** is when a function calls itself when a specified condition is met

```pseudo
function(){
    if(condition){
        function();
    }
}
```

The following is an example of a recursive function that first goes to main, calls function f and then the function f prints 1 but then it gets recursive called so it continuously prints 1 1 1 1 ............ till infinity, since there is no stopping condition. This is called an **infinite recursion**.

```pseudo
void f(){
    print("1");
    f()
}
main(){
    f();
}
```

After running this, we'll get a memory error because the stack memory will be full and the program will crash. This is known as **stack overflow**.

- When there is no condition: When the function call happens, the function is pushed in the stack and then it waits for the function to complete(it doesn't execute the last line properly). But when the recurse function calls the same function again then it also waits in the stack. This goes on again and again and the stack memory is full and the program crashes. This continues for some time and it is dependent on the compiler for the particular OS. This is called **segmentation fault**.

- **Stack Space** is where the remaining non completed functions which is yet to be executed are stored. The stack memory is limited and when it is full, the program crashes. The stack memory is used to store the memory that is allocated to the function call. When the function is called, the function is pushed in the stack and then it waits for the function to complete. When the function is completed, the function is popped from the stack and the memory is freed. This is how the stack memory works.

- When a specific condition is met: It is called a **base condition**. When the base condition is met, the function stops calling itself and the stack memory is freed. This is the correct way to use recursion.
  - The following is an example of the finite recursion which needs a base condition to stop the recursion. Do note that it is still not finite. Once we add that if condition here we get the base condition which then stops the recursion. NOTE: The `return` keyword inside the function terminates its execution then and there. This is the correct way to use recursion.
  - execution procedure: Firstly main ran, then f ran, then firstly f() got store in the stack, then it printed 1, then it got called again and again and again and store in the stack one by one till the base condition is met.  Once the base condition is met, the stack memory is freed one by one from the end to the start and the program ends after the final f() call inside the main function.

```pseudo
a = 0;
void f(){
    if(a == 4){
        return;
    }
    print(a);
    a++
    f(a)
}
main(){
    f();
}
```

## Recursion Tree

It is something that we'll get to hear every now and then. Basically while explaning the recursion, instead of writing the entire function with the separate cases of if statements like above one by one which is like too repetitive, we just make one truncated version which represents everything and that thing is a recursion tree.

- The root node is the first function call.
- The child nodes are the function calls that are made by the root node.
- The leaf nodes are the function calls that are made by the child nodes.
- The leaf nodes are the base condition nodes.

![recursion tree](../assets/Screenshot%202024-08-18%20171631.png)