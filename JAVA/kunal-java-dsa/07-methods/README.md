# Methods (functions are known as methods in JAVA)

## All the basics about methods

- When we need to repeat a certain code block like a hundred or thousand times, then copy pasting will be very inefficient and almost impossible if more changes are to made in those copy pasted code, etc. So in such cases we follow the ***DRY****(Don't repeat yourself)* format by using **FUNCTIONS**.
  - If we put a function in a class then the function which is put inside the class is known as method. In case of JAVA, they are called **METHODS** because all the code that we write in Java are already under a ***class***. Since we put everything inside a class in Java, so the functions are called methods by default. By using the method we can use them to repeat a certain block of code without copy pasting.

- Methods has the following syntax:

```java
/* // main method will stay here and since it always runs first so after running it will call the funtion inside the main method and thus it runs in that manner

    main() {  
    return_type_name(); // here goes the respective method name, write it repeatedly to run the code under this method a no of times
    }

    access_modifier return_type_name(args){
    // body of the method
    return statement;
    }

// access modifiers(coming later in OOP videos)
*/
```

- Methods are written using a name followed with a pair of circle brackets. The name part is the one showing the name of the function and the brackets calls the function. For using the method they should be present in the main method (`main()`) i.e written under the main method's block with the braces so that we call them from the main method. We can also pass parameters in those brackets to get some values and also pass arguments in the method call part to pass those values to the method in order to do something. Thus we can call the method in the main method a no of times to make the code under that method repeat.

- Functions/Methods contains the following two things which are used all the time:
   1. Parameters: A variable used in the function declaration to represent a placeholder for the data that will be passed into the function.
   2. Arguments: The actual value or expression passed to the function during the function call, which is assigned to the corresponding parameter.
   3. Parameters refers to the list of variables in a method declaration. Arguments are the actual values that are passed in when the method is invoked. When you invoke a method, the arguments used must match the declaration's parameters in type and order.

- When we write the names of the methods by ourselves, these type of methods are called **user defined methods**.

## things to note from the example code block

- code block from the Sum.java file

``` java
public class Sum {
    public static void main(String[] args) {
        sum();
        // System.out.println(sum2());
        // sum2();
        // int ans = sum2();
        int ans1 = sum3(20, 40); // 2, pass in some values in the brackets in the order of the method declaration with the same method name, and assign it to a variable to print or directly output the method with the values
        System.out.println(ans1);
    }

    // pass the value of the numbers when you are calling the method in main()
    static int sum3(int a, int b) { // 1
        int sum = a + b;
        return sum;
    }

    static int sum2() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the 1st number: ");
        int num1 = in.nextInt();
        System.out.print("Enter the 2nd number: ");
        int num2 = in.nextInt();
        int sum = num1 + num2;
        return sum; // here "return" is used to return the value of this sum which is the return this method to the method call
    }

    static void sum() {
        // certain code block
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the 1st number: ");
        int num1 = in.nextInt();
        System.out.print("Enter the 2nd number: ");
        int num2 = in.nextInt();
        int sum = num1 + num2;
        System.out.println("The sum is: " + sum);
    }
}
```

- The above example shows the usage of Methods:
  - here we can add the `sum()` method call as many amount of times required to make it repeat as desired.
  - Also the changes that are made in the method will be affected everywhere that method is called.
  - In the brackets, we can also pass parameters as desired, but then it cannot be of the void type since void returns null value, void can only return

- Important points from the above example:

  1. About **return type** in a method: It means, when you will call the method, then what will the value of this method call going to be. The answer to this question is known as the return type. In return type when we are going to return a value of certain type we use the type or else if we don't need to return stuff we use the void type. It contains the following types for returning values:
     - **void return type**: The void return type in a method indicates that the method does not return any value. It is used when a method is intended to perform some actions or operations without producing a result that needs to be returned. It can perform various other tasks, such as modifying object state, printing output, updating data, or interacting with external resources.
     - **non-void return type**: If a method needs to return a value, you would specify a non-void return type (such as int, double, String, or any other data type), and the method would use the return statement to provide the value that the method call evaluates to. This is particularly useful when the method's result is needed for further computation or decision-making.

  2. method call: When the method(here `sum()`) is called it's code block runs line by line and it gets a value which then gets stored in the method call(the same `sum()`). And the value is going to be whatever the code block inside that specific method call returns(in our example it is `System.out.println("The sum is: " + sum);` i.e return the value of the sum variable).
  
  3. Always use the correct return type for the value of the method call, i.e the type for all the related things to the method must stay the same (in which the returned value gets stored. So here we are using the integer type and not the void type)

  4. *Here `return` is used to return the value of a variable to a method*. In this example we are returning value of the `sum` variable which returns the value of the code block in the method `sum2()` and this method can then be assigned to a variable to show the value or directly printed out using an output statement. *`return` also means that the work of the method is done and it will end now, so anything after that will be flagged as unreachable since it cannot be used it due to the return coming before that*.

  5. If you are returning a type in the method then you need to specifically show the `return method_name()` in the method code block otherwise it will show error.

  6. We can write a user defined method (*1) as integer (if we want to take an integer type as input, or any other type as desired) and then in the circle brackets block we can pass variables to store the values of that same return type and then the statement regarding that variables will be in that method and a return statement is also needed and then to pass in some values we can give parameters in the method call brackets inside of the main method and then directly print out the method call to show the return value or assign another variable to that.
  
     - **NOTE** that the variables can be different in the method call and some statements in that method here and there that are related than the variables found in the user defined methods.

  7. Since the main method contains static so anything that is under the static must also be static. More about static in later videos.

- Example code block, explanation for the following code block is after the code block

```
    main(){
        name = "human"; // 1
        greet(name);
    }
    greet(_datatype_ naam){ // 2 // here i have used naam but it doesn't matter what name you may use it'll do the same thing
        print(naam);
    }
```

Things to note here:

   1. human(*1) is an object in the heap memory and the `name` is a reference variable which is pointing to it.
   2. **when `name` is passed using the specific method(here greet()) in the method call, the value of the reference variable(here `name`) is passed.
   3. ***Remember**: In java there is no pass by reference, there is only pass by value.*
   4. The `naam`(*2)(can be any variable name) is a reference variable in the user defined method declaration and it gets a copy of the value of this name variable when it is passed and thus both the reference variable (name and naam) points to the same object as `name` i.e "human".

- The following is from the file PassingExample.java. This is an important code block, explanation for the following code block is after this.

```
    psvm(){
        name = "Kunal"; //1
        change(name);
        print(Kunal);
    }
    change(naam){ // 2
        naam = "Rahul"; //2
    }
```

Things to note here:

   1. `name` first points to "Kunal", and after the method call the `naam` variable also points to the "Kunal" object which is a copy, but after the new object "Rahul" is created then the `naam` variable changes its pointer to "Rahul". NOTE: it didn't change the original object which `name` was pointing to.
   2. Since the `naam` changes its pointer it is now pointing to a different object but it doesn't change the `name` variable pointer, `name` is pointing to the same "Kunal" object, hence when `name` is printed here it will show "Kunal" as the output.
   3. So Java only has pass by value and no pass by reference. In terms of objects like non-primitives, the references' copy is passed i.e the parameters both are going to be pointing to the same object
   4. Also any change in the method declaration reference variable will be shown in the method call's variable too, the only catch is that it must change the object. In the above example it is not changing the object but creating a new one so it doesn't change. More on the 4th point later on
   5. The method declaration reference variables are usable in that method's scope only i.e inside the method's brackets that variable is usable, it is undefined outside that specific method. This is called **method scoping** (more on that later on). This point is valid for main method too, the variables declared in the main method are in the main method scope only i.e it is usable inside that method only. Also we can use the declare the same variables(as used before like using a in main as well as another method) in another method and that will be valid for that method scope only, no other method can access another method's variable.
   6. Primitives like int, short, char, byte, etc for these pass by value is only possible and for objects and stuff it is passing value only but value of the reference variable.
   <a id="hello"></a>
   7. **NOTE:** strings are immutable in java for security reasons(in the final class or something), so it can't be created again. More on that in the coming lectures.

- Why did it not swap in the Swap.java example, Important code block, explanation is in the following

```java
psvm(){
    a = 10;
    b = 20;
    swap(a,b);
}
swap (num1, num2){
    temp = num1;
    num1 = num2;
    num2 = temp;
}
```

   1. Here a -> 10, b -> 20, num1 -> 10, num2 -> 20, They are primitivies so only the value is passed.
   2. Now it'll be a -> 10, num1 -> points to a's value 10
   <!-- 3. In this method's scope, temp is now having a value of 10 and num1 is going to have a value of num2 i.e 20 and -->
   3. If we do something like a = 10, b = 10, then it'll be upto java to do something with it, some optimizations may take place automatically from java's side.
   4. In the swap method's statements, temp has value of num1 i.e 10, num1 has the value of num2 i.e 20, and num2 has a value of temp i.e 10, So in the method's scope it is swapped but the original a and b are not swapped.
These are for primitive data types and for those type of datatypes it is only going to be of pass by value. But for objects and references i.e for complex datatypes pass by value of that reference variable takes place eg: both the reference variable pointing to the same object, so the change done in that object via one reference variable will reflect in the main object too(the example for this is in the next explanation)

- Now for the complex datatypes, in the next ChangeValue.java example

``` java
 public static void main(String[] args) {
  int[] arr = { 1, 3, 2, 45, 6 };
  change(arr);
  System.out.println(Arrays.toString(arr));
 }
 static void change(int[] nums) {
  nums[0] = 99;
 }
```

   1. The original array `arr` has an object pointing to `{1,3,2,45,6}`. Here the array is a reference and an object, so when it is passed in the method the reference copy is passed and the reference will contain the same object, in this example `nums` pointing to the same object `{1,3,2,45,6}`. This is not pass by reference but passed by the copy of the value of the reference.
   2. Secondly the change method modifies the value at the 0th index of the `nums` array to 99 and then the modified array is printed in the main method, it is changed after running the program. We may have this doubt that in the previous example Swap.java, the string didn't change but here it is changing. This is because we are creating a string which ultimately creates a new object there (note that strings cannot be created again if once created as said in the last point back [there](#hello) which also nullifies that change of object) and java doesn't let the main object get changed(since the array is pointing to the same object) but in this ChangeValue.java example, we are not modifying the string or creating something(like the above) but the array is only modified and as such if we make a change to the object via this reference variable same object will be changed
      - Strings in java are immutable(maybe for memory safety purposes)  which means their values cannot be changed once they are created. If you modify a string, a new string object is created.
      - Arrays in Java are mutable, which means their elements can be modified without creating a new array object.
   3. In short, when an object's reference `arr` is passed to this parameter `change(arr)` actually the reference itself is passed by call by value because the value that is being passed refers to the object `{ 1, 3, 2, 45, 6 }`. `nums` here is another value of this reference variable `arr` pointing to the object. These are all pass by value since in java we don't have pointers and so we don't get the address.
   4. Means in this type of cases where we have only modification of objects, the method call points to the same object and doesn't create a copy of it like it did earlier.

## Scoping (refer the file Scope.java for the example code and reference)

- Scope basically means where we can access our variables, it depends on where the variables are defined. If it is defined in a method's scope then it will be usable in that method's scope only and nowhere else same goes for normal block or class block or loop block(coming later in this). It also applies to the arguments and parameters that is defined inside the method brackets, or in the same way loops, normal blocks, class, etc.

### Block scoping

```java
int a = 10, b = 20;
{
    a = 20; // will show an error here
    int c = 99;
}
System.out.println(a); // a is changed from 10 to 20 since it is redefined inside the block and prints the same when printed outside the block
System.out.println(c); // c is not defined since it is outside of the block scope
```

- *The above is called a block which is written inside curly braces and inside the main method(can also be written inside a different method) and anything that has been defined in that block can be used in that block only, that is called* **Block Scoping**.
- In the example code, when we initialize a int variable `int a = 10` and we do another `int a = 20` we'll get an error like the variable a is already declared (or something like "variable a is already defined in the scope" in some ide's) which means that we cannot redeclare a reference variable that is already declared. We can however change/modify the value using `a = 30`.
- Also if you do some variable declaration inside the block then you can't do that again with the same variable outside right after the block although modification is possible(no chance of doing that before the block since that will be null) and also some other statements like i/o stuff, value change, etc is also not possible.
- If you want to give a value to a variable and you specifically want it to be inside of the block then it is only going to be used inside that block only. In more simpler terms, values that are initialized in this block are going to remain in this block.
- Also if a ref variable is first declared outside and before the block (eg: ref var `a`) and you modify the value in the following block then it will change the value when you try to print it after the block. It is being changed because we have changed the original one and haven't created a new one, to create a new one we need to initialize and declare it but since we are just modifiying the original object, so printing it out just shows the new modified object(i.e the value of the ref var).
- In short these are the rules:
   1. If we have initialized a variable inside this block then it'll be used within this block only.
   2. If something is initialized outside then we can definitely modify or update or use it as well inside and outside of the block and it'll be applied globally i.e original one will be changed in that method provided the structure follows the line by line execution.

### method scoping

- In the example code, we can't access a or b in the `random()` method as well as the `num` variable's value from the `random()` method in the main method. We can print num in the random method but not in the main method, *this is first scope of a method known as the* **method scope** i.e ***if you have defined variables or anything inside a method you can access those inside the method only and not anywhere outside***. This also holds true for all the arguments that will be provided inside the brackets of the method
- This is also shown in the Swap.java example, where we can't change any object of the main method due to the a and b variables written inside another method and it just stays inside that method scope only and is unusable anywhere outside(doesn't mean we can initialized the same variable outside of the scope, that is possible btw).
- But if you do by passing of the value of the reference variable, in that case if you make any changes then the original object will also be changed.

### Loop Scope(the rules of normal block scope also applies similarly to the loops block scope)

- Scoping in for loops also has the same rules and they follow whatever we said earlier for the declaration ones.
   1. We cannot reinitialize a variable again which has already been declared outside (or method, etc) and before the for loop block, but we can definitely modify anything declared outside and before the block and it'll be visible inside the method whenever we try to use it.
   2. We cannot use a variable which has been declared inside of the loop, outside. Eg: The 'i' which we use in the for loops are usable only within the loops' block and not outside.

- Common rules for scoping(these are enough):
  - Anything that is initialized outside and before a block cannot be reinitialized inside the block, but anything that has been initialized inside the block can be reinitialized outside after the block due to the block scoping, since outside it doesn't know if there is any same variable inside the block.
  - Anything that is initialized outside a block can be used/modified/changed inside the block, but anything that is initialized inside the block can be used for any purposes inside the block only & cannot be done anything outside that block.
  - Anything that is initialized outside of the block can be modified inside the block and that will modify the original value also i.e whenever we try to access that value it will give us the modified one anywhere inside the method.
  - Outside the for loop block or a normal block but inside the same method, something that has been initialized cannot be reinitialized in that block or that loop again.
  - **More stuff**: (ref from Shadowing.java)
    - Anything that is initialized inside a method block like right after the main method line above everything, that will be available and usable everywhere inside that method block be it any loop or normal block or etc. Eg: var `a` in the Scope file is usable/available everywhere inside everything that is in the block of a.
    - Similarly the `x` var is going to be availabe to everything that is in the block of x.

## Shadowing (ref Shadowing.java file)

It is a practice of using two variables with the same name within the scope that overlaps. In the example we have the x variable which overlaps the entire block, i.e everywhere we can use x.

- Here we have initialized `int x` inside the public class, so x will be available everywhere inside that public class be it a loop, method, etc as long as it is inside that curly braces block.  
- Also in order to use anything in static(since we want to use x or we want it available in the scope in `psvm()` which is also static) you have to have it initialized as static and so it must be written like `static int x;` (will be taught about static is OOPs videos), basically static is object independent thing and `int x;` is an object dependent thing, so we cannot use object dependent things in object independent things and as such we need to use static while declaring x.
- ***Now we are writing the same variable x which is in the method scope and it overlaps the one that is in the higher level class scope, so the current value of the variable `x` gets modified in the method scope only and so when we run the file, the method level scope outputs are 90 but the one that is outside of the main method scope level i.e the `fun()` method's method call outputs the value as 40 which is of the higher class level scope.***
- The variable with a higher level scope is hidden after the modification of the value which is valid till the method scope only, this is called **Shadowing**, the lower level overriding the upper level.
- The scope of this local variable that shadows the class variable is not beginning at the point where the local scope begins, shadowing begins where the local variable is declared. What this means is that we can use it only when the variable is initialized and not before that. If you attempt to access the value between the declaration and initialization of a variable then it'll give an error.

## Variable length arguments(ref VarArgs.java file)

**Variable length arguments**: When you create a method that takes a variable no of arguments, it is basically known as VarArgs method i.e when we do not know how many arguments we are taking.

- When we don't know how many arguments we will be providing, then the syntax we use is `int ...var_name` (type followed by 3 dots then the variable name together, can be any name).
  - This `int ...var_name` internally is taking an array of integers here( or char/String/float/etc, array is just a collection of integers/char/String/float/etc).
- Since it is of variable length, we can give as many nos of arguments as possible and it will print all of them and will also internally store them as an array.
- This is known as ***variable length argument***. Length is not constant here, it varies according to the input that is being provided.
- Also the type must be a correct one in the parameters of the methods and also in the method calls' arguments.
- *Basically the syntax is telling the compiler that this method `fun()` can be called via 0 or more than 0 arguments( when argument is 0, it prints out an empty list/array ). As a result, v is being implicitly declared as an array of type int(when we write int as the type, can be of other type, as in the example).*
- We can also do something like including normal arguments, then keyword arguments like the one done in the file `static void multiple(int a, int b, String ...v)`, and here we can give the input like this `multiple(2, 3, "kunal", "Rahul", "hello", "hi", "this", "is", "var", "length", "arg input");`. What we are doing here is that we are declaring normal args int a, b and then we are adding another VarArg and then in the arguments we are giving them accordingly to the type and order.
- **NOTE**: method arguments follow the same order as the one in the method parameters in the method declaration. If there is any error in some stuff such as the arguments are not written in the correct order or arguments are not of the correct type as of the parameters, or some arguments are not provided/skipped, etc.
- Also the VarArg must be the last in the parameter list otherwise it will not be possible to determine which argument is of which parameter, for example: If we declare a VarArg with int type and it is in the middle and we declare another var of the same type after that VarArg, then we wouldn't know which argument will be of the next var since VarArg can take any no of input. And for cases where the type may be different, then the function will assume that you have given a wrong type argument for the next var parameter after the VarArg with different type and as such it'll throw error.

## Method Overloading (refer file Overloading.java)

Basically it happens when two or more functions of the same name exists but the parameters are different

- When we call the function with an integer argument for the int type parameter function and a String argument for the String type parameter function, we get the output as desired.
- For method overloading it must be of two or more functions having the same name, but you need to consider two things for that:
   1. Either the no of arguments should be different or
   2. The type of arguments should be different if the no of arguments are same.
- How does it determine which function to call? : It is determined by the compiler when our program gets compiled i.e at compile time it decides which one to call. Eg: In the file, first function call `fun(67)` takes integer, so the compiler will be like which function call takes integer, then it will decide that that value should go to that specific integer taking method at the compile time itself.
- If we don't provide the function specific arguments to the overloaded functions, then the one not getting the arguments will not run. Eg: if we comment out the `fun(67)` line then it'll only run the String type function and the other integer type one will not run.
- If we do something like the `sum()` function where we have 2 of these functions overloaded with the same type that is integer but the no of ref variable to do the addition operation is different. In such cases we have to provide arguments with the same type with that many no of times as the no of parameters present and the function matching that many no of arguments will run, eg: `int ans = sum(3, 4, 88);`, if we give less than 2 or more than 3 inputs then it'll show error since no function can take this input(the `sum()` function in the example can take 2 or 3 inputs). Inputs with wrong type or wrong no of args will give error.
- Also the `demo()` function example, if we run that function with int arguments, the int type demo function runs and if we pass String type arguments, then the String type demo function runs.
- And if we don't pass in any arguments, then the function will not run. This is termed as **Ambiguity**. The VarArgs arguments can't be empty in this case since it is a function overloading case and at compile time it'll not be able to decide which function to run. It cannot be empty when you are overriding varargs, since it'll not know which one to run.

### Questions

- Finding the prime number:
  - Apparently it seems like I haven't solved this question before while doing the main function questions so might as well do it in functions
  - kunal's version of the solution :
    - *The Prime Check Loop part*(Fast forwarded to that part): The function then enters a loop to check for prime conditions. It starts with c initialized to 2 (the first prime number).The loop continues as long as the square of c is less than or equal to n. This condition is used because if c exceeds the square root of n, it is not necessary to continue checking, as all potential factors of n would have been checked by that point. Within the loop, it checks if n is divisible by c (i.e., n % c == 0). If it is divisible, the function immediately returns false, indicating that n is not a prime number. If n is not divisible by c, the value of c is incremented by 1, and the loop continues to the next iteration.
    - Final Check: After the loop, if the loop condition c * c > n is met, it means that n is not divisible by any integer from 2 up to the square root of n, which confirms that n is a prime number. In this case, the function returns true.
    - And the logic he is using: The code uses a loop to check for factors of the input number n within the range of 2 to the square root of n. If any factor is found, it concludes that n is not prime. Otherwise, it determines n to be prime. The code also handles cases where n is less than or equal to 1, as such values are not considered prime.

- Finding all the 3 digit armstrong numbers: We know the logic behind finding the armstrong numbers, deez nuts