# Methods (functions are known as methods in JAVA)

## All the basics about function

- When we need to repeat a certain code block like a hundred or thousand times, then copy pasting will be very inefficient and almost impossible if more changes are to made in those copy pasted code, etc. So in such cases we follow the ***DRY****(Don't repeat yourself)* format by using **FUNCTIONS** and in case of java, they are called **METHODS** since all the code that we write in Java are already under a ***class***. By using the method we can use repeat a certain block of code or any code without copy pasting.

- Methods has the following syntax:

```java
/* // main function will stay here and since it always runs first so after running it will call the funtion inside the main function and thus it runs in that manner

    main() {  
    return_type_name(); // here goes the respective function name, write it repeatedly to run the code under this function a no of times
    }

    access_modifier return_type_name(args){
    // body of the function
    return statement;
    }

// access modifiers(coming later in OOP videos)
*/
```

- Function is written using a name and with a pair of brackets, the name is the shows the name of the function and the brackets calls the function. For using the functions they should be present in the main function (`main()`) i.e written under the main function parenthesis with the braces to call them from the main function. We can also pass parameters in those brackets to So we can call the function in the main function a no of times to make the code under that function repeat.

- We are writing the names of the functions by ourselves, these type of functions are called user defined functions.

- The following example shows the usage of functions:
  - here we can add the `sum()` function call as many amount of times required to make it repeat as desired.
  - Also the changes that are made in the function will be affected everywhere that function is called.
  - In the brackets, we can also pass parameters as desired, but then it'll not be of the void type since void returns null value

- Important points:
  1. About return type in a function: It means, when you will call the function, then what will the value of this function call going to be. The answer to this question is known as the return type.
  2. Function call: When the function(here `sum()`) is called it's code block runs line by line and it gets a value which then gets stored in the main function's function call(the same `sum()`). And the value is going to be whatever the code block inside that specific function call returns(in our example it is `System.out.println("The sum is: " + sum);` i.e return the value of the sum variable).
  3. Use the correct return type for the value of the function call, i.e the type for all the related things to the function must stay the same (in which the returned value gets stored.So here we are using the integer type and not the void type)
  4. *Here `return` is used to return the value of a variable to a function*. In this example we are returning value of the `sum` variable which returns the value of the code block in the function `sum2()` and this function can then be assigned to a variable to show the value or directly printed out using an output statement. *`return` also means that the work of the function is done and it will end now, so anything after that will be flagged as unreachable since it cannot be used it due to the return coming before that*.
  5. If you are returning a type in the method then you need to specifically show the `return function_name()` in the method code block otherwise it will show error.
  6. We can write a user defined function (*1) as integer (if we want to take an integer type as input, or any other type as desired) and then in the circle brackets block we can pass variables to store the values of that same return type and then the statement regarding that variables will be in that function and a return statement is also needed and then to pass in some values we can give parameters in the function call brackets inside of the main function and then directly print out the function call to show the return value or assign another variable to that.
     - **NOTE** that the variables can be different in the main function's function call and some statements in that function here and there that are related than the variables found in the user defined functions.

``` java
public class Sum {
    public static void main(String[] args) {
        // sum(); // add this a no of times to make it repeat that many amount of times.
        // System.out.println(sum2());
        // sum2();
        // int ans = sum2();
        int ans1 = sum3(20, 40); // 2, pass in some values in the brackets in the order of the function declaration with the same function name, and assign it to a variable to print or directly output the function with the values
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
        return sum; // here "return" is used to return the value of this sum which is the return this function to the function call
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

## things to note from the example code

- If we put a function in a class then the function which is put inside the class is known as method. Since we put everything inside a class in Java, so the functions are called methods by default.

- Since the main function contains static so anything that is under the static must also be static. More about static in later videos.

- Important code block, explanation for the following code block is after the code block

```
main(){
    name = "human"; // 1
    greet(name);
}
greet(_datatype_ naam){ // 2 // here i have used naam but it doesn't matter what name you may use it'll do the same thing
    print(naam);
}
```

- Things to note here:
   1. human(*1) is an object in the heap memory and the `name` is a reference variable which is pointing to it.
   2. **when `name` is passed using the specific function(here greet()) in the main method function call, the value of the reference variable(here `name`) is passed. *In java there is no pass by reference, there is only pass by value*.**
   3. The `naam`(*2)(can be any variable name) is a reference variable in the user defined function declaration and it gets a copy of the value of this name variable when it is passed and thus both the reference variable (name and naam) points to the same object as `name` i.e "human".
- Also note the stuff in the next example

- Previous example PassingExample.java, Important code block, explanation for the following code block is after the code block

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

- Things to note here:
   1. `name first points to "Kunal", and after the function call the naam variable also points to the "Kunal" object which is a copy, but after the new object Rahul is created then the naam variable changes its pointer to Rahul. NOTE: it didn't change the original object which`name was pointing to.
   2. Since the naam changes its pointer it is now pointing to a different object but it doesn't change the `name variable pointer,`name is pointing to the same "Kunal" object, hence when `name is printed here it will show "Kunal" as the output
   3. So Java only has pass by value and no pass by reference. In terms of objects like non-primitives, the references' copy is passed i.e the parameters both are going to be pointing to the same object
   4. Also any change in the function declaration reference variable will be shown in the main function call's variable too, the only catch is that it must change the object. In the above example it is not changing the object but creating a new one so it doesn't change. More on the 4th point later on
   5. The function declaration reference variables are usable in that function's scope only i.e inside the function's brackets that variable is usable, it is undefined outside that specific function. This is called **function scoping** (more on that later on). This point is valid for main function too, the variables declared in the main function are in the main function scope only i.e it is usable inside that function only and we can use the same variables in another function and that will be valid for that function scope, no other function can access another function's variable.
   6. Primitives like int, short, char, byte, etc for these pass by value is only possible and for objects and stuff it is passing value only but value of the reference variable.
   <a id="hello"></a>
   7. **NOTE:** strings are immutable in java for security reasons(in the final class or something), so it can't be created anyhow. More on that in the coming lectures.

- Why did it not swap in the Swap.java example, Important code block, explanation for the following code block is after the code block

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
   <!-- 3. In this function's scope, temp is now having a value of 10 and num1 is going to have a value of num2 i.e 20 and -->
   3. If we do something like a = 10, b = 10, then it'll be upto java to do something with it, some optimizations may take place automatically from java's side.
   4. In the swap function's statements, temp has value of num1 i.e 10, num1 has the value of num2 i.e 20, and num2 has a value of temp i.e 10, So in the function's scope it is swapped but the original a and b are not swapped.
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

   1. The original array `arr` has an object pointing to {1,3,2,45,6}. Here the array is a reference and an object, so when it is passed in the function the reference copy is passed and the reference will contain the same object, in this example nums pointing to the same object {1,3,2,45,6}. This is not pass by reference but passed by the copy of the value of the reference.
   2. In function it says that 0th index should be changed to 99 and it is changed after running the programs. We may have this doubt that in the previous example Swap.java, the string didn't change but here it is changing. This is because we are creating a string which ultimately creates a new object there (note that strings cannot be created as said in the last point back [there](hello) which also nullifies that change of object) and java doesn't let the main object get changed(since the array is pointing to the same object) but in this ChangeValue.java example, we are not modifying the string or creating something but the array is only modified and as such if we make a change to the object via this reference variable same object will be changed
   3. In short, when an object's reference `arr` is passed to this parameter `change(arr)` actually the reference itself is passed by call by value because the value that is being passed refers to the object `{ 1, 3, 2, 45, 6 }`. `nums` here is another value of this reference variable `arr` pointing to the object. These are all pass by value since in java we don't have pointers and so we don't get the address of some variable.
   4. Means in this type of cases where we have only modification of objects, the function call points to the same object and doesn't create a copy of it like it did earlier.

## Scoping (refer the file Scope.java for the example code and reference)

### Function scoping

- Scope basically means where we can access our variables, it depends on where the variables are defined. If it is defined in a function's scope then it will be usable in that function's scope only and nowhere else, it also applies to the arguments and parameters that is defined inside the function brackets.
- In the example code, we can't access a or b in the `random()` function as well as the `num` variable's value from the `random()` function in the main function. We can print num in the random function but not in the main function, *this is first scope of a function known as the* **function scope** i.e *if you have defined variables or anything inside a function you can access those inside the function only and not anywhere outside*. This also holds true for all the arguments that will be provided inside the brackets of the function
- This is also shown in the Swap.java example, where we can't change any object of the main function due to the a and b variables written inside another function and it just stays inside that function scope only and is unusable anywhere outside.
- But if you do by passing of the value of the reference variable, in that case if you make any changes then the original object will be changed.

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

- *The above is called a block which is written inside curly braces and inside the main function(can also be written inside a different function) and anything that has been defined in that block can be used in that block only, that is called* **Block Scoping**.
- In the example code, when we initialize a int variable `int a = 10` and we do another `int a = 20` we'll get an error like the variable a is already initialized (or something like "variable a is already defined in the scope" in some ide's) which means that we cannot reinitialize a reference variable that is already defined. We can however change/modify the value using `a = 30`, but we cannot do something like `int a = 30` inside the block.
- Also if you do some variable declaration inside the block then you can't do that again outside right after the block although modification is possible(no chance of doing that before the block since that will be null) and also some other statements like i/o stuff, value change, etc is also not possible.
- If you want to give a value to a variable and you specifically want it to be inside of the block then it is only going to be used in this block. In more simpler terms, values that are initialized in this block are going to remain in this block.
- Also if a ref variable is first declared outside and before the block (eg: ref var `a`) and you modify the value in the following block then it will change the value when you try to print it after the block. It is being changed because we have changed the original one and haven't created a new one, to create a new one we need to write int or char or String or etc followed by the ref var to initialize it and since we are just modifiying the original object, so printing it out just shows the new modified object(i.e the value of the ref var). 
- In short there are 2 rules:
   1. If we have initialized a variable otusi
