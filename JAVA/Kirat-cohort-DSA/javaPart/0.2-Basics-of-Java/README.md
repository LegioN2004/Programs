# Basics of JAVA

## Data types

| Data Type | Size                          | Description                                                                                         |
| --------- | ----------------------------- | --------------------------------------------------------------------------------------------------- |
| byte      | 1 byte                        | Stores whole numbers from -128 to 127                                                               |
| short     | 2 bytes                       | Stores whole numbers from -32,768 to 32,767                                                         |
| int       | 4 bytes                       | Stores whole numbers from -10^9 to 10^9 (-2,147,483,648 to 2,147,483,647)                           |
| long      | 8 bytes                       | Stores whole numbers from -10^18 to 10^18 (-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807) |
| float     | 4 bytes                       | Stores fractional numbers. Sufficient for storing 6 to 7 decimal digits                             |
| double    | 8 bytes                       | Stores fractional numbers. Sufficient for storing 15 decimal digits                                 |
| boolean   | 1 bit(depends on the compiler | Stores true or false values                                                                         |
| char      | 2 bytes                       | Stores a single character/letter or ASCII values                                                    |

notes

- Let's say there is a very big number/constant, a trick in java to earn some points in the interviews is to add `_`(underscores) to make it more readable. For example, `int a = 1_000_000;` is the same as `int a = 1000000;` and the compiler won't throw any errors. Do note that the underscore can be added anywhere in the number, but not at the beginning or end of the number otherwise there'll be errors. This is just for code readability in the long/int variable, you can always separate out the

- In FAANG, interviews they give a lot of importance to the following :
  - code readability
  - naming of variables
  - naming of functions
  - code redundancy(again DRY, like whenever you see code repition, you should make a function out of it and call it wherever needed)
  - and more
- These comes under the clean coding practices which are fundamentally taught during our journey and these interviewers at these companies also check if we are following these practices or not.
  - eg: `int a = 1_000_000;` instead of `int a = 1000000;`, `int x = 2` instead of `int x=2` etc is more readable.

## Reference types

primitive data types have sometheing called reference types
In C we used to have structures, in C++ we used to have classes, in Java we started having classes and objects.
A class is not a physical entity, it is a blueprint and we can use this class to physically instantiate an object. In Java(**for now**) we can consider these objects as references.

difference between primitive and reference types(commonly asked in interviews of companies and bank companies in the java specific rounds):

- primitive types are stored in the stack memory
- reference types are stored in the heap memory

So in primitives we have the actual value stored in the memory, but in reference types we have the address of the memory location stored in the memory.

```java
int x = 2; // primitive type
int y = x; // primitive type
System.out.println(x + y); // 2+2 = 4
x = 4; // y value is still 2
System.out.println(x + y); // 4+2 = 6
```

Why the above happens like why is y still 2, because when we set x as 2 and we set y as x, a copy of x is made and so when the value of x is changed y still remains intact i.e 2. So when you making a copy or assiging a value to a variable, you are actually making something called a deep copy, deep copy as in copying it by value and you are making a separate place for that variable in the memory. As a result, if you change x it won't affect y.

But by using reference types, we can change the value of the object and it will reflect in all the references pointing to that object. What do we mean by reference data type, it means any object.

```java
// point is a class here
point p1 = new point(2, 3); // reference type
point p2 = p1; // reference type
System.out.println(p1 + p2);
// what happens here is that both p1 and p2 are pointing (2,3) and (2,3)
p1.x = 3;
p1.y = 4;
System.out.println(p1 + p2);
// the next time we print p1 and p2, it will be (3,4) and (3,4) and not (3,4) and (2,3)
```

What do we see here is that the value of the object is changed and it is reflected in all the references pointing to that object. This is the difference between primitive and reference types. Why does this happen: p1 points to 2,3 and p2 = p1, ideally what will happen is that p2 will also point/reference to 2,3, i.e the same memory object. So when we change the value of p1, p2 also changes because p2 is pointing to the same memory location as p1. Same goes for vice versa, this is known as shallow copy where when we are copying to reference types, we are not copying the values, we are actually copying the addresses of the variables. This is the difference between primitive and reference types.

So now there is a problem where if we change something in reference types, it will reflect in all the references pointing to that object. So how do we solve this problem, we solve this problem by using the `new` keyword. When we use the `new` keyword, we are actually creating a new memory location for that object and so when we change the value of that object, it won't reflect in all the references pointing to that object. So p2 now will point to a different location and since we have passed in the values of p1 but since we have allocated different memory locations for the different object it'll not affect the originals and as such we'll have a deep copy using reference types. There are different ways to achieve deep copy in java, but this is the most common way to achieve deep copy in java.

```java
point p1 = new point(2, 3); // reference type
point p2 = new point(p1.x, p2.y); // reference type
```

## JAVA Collections Framework

Just like we have STL in C++, we have the Java Collections Framework in Java, which lets us make the data structures in Java. So we can create a stack, a queue, a map, etc, because we cannot make them in an interview because some of them may be very algorithmic and creating from scratch on top of using that hard thing to solve a problem is not at all feasible. So we have the Java Collections Framework for that very use case. In an interview, we are not supposed to create those from scratch but we should know the internal workings of those data structures.

It is a set of classes and interfaces that implement commonly reusable collection data structures. It is a framework that provides a standard way to store and manipulate a group of objects. Java Collections can achieve all the operations that you perform on a data such as searching, sorting, insertion, manipulation, and deletion.

We already have the following data structures in Java and as such we can use them as is:

```java
Stack<Integer> Stack = new Stack <Integer> ();

Stack.add(1);
Stack.add(2);
Stack.peek();
Stack.pop();
Stack.push();
Stack.isEmpty();
```

In the DSA lab in the CS studies, you may get to create this on our own. But while solving DSA problems, it is not supposed to create this from scratch.

One thing to note here is that we are using wrapper classes like the one written above in the example code block "Integer" and not "int", the reason is further down the line, we can't use primitive types. Same goes for other data types like for double we will need to use "Double", "String".

So in java we have something called the **wrapper class** which is basically the reference implementation of the corresponding primitive types. For example: for `char` we have the reference implementation we have `Char`, i.e convert the first letter to a capital letter and also write the full name. And other functionalities remain the same.

| Primitive type | Reference type |
| -------------- | -------------- |
| char           | Char           |
| int            | Integer        |
| float          | Float          |
| long           | Long           |
| double         | Double         |
| boolean        | Boolean        |

Another thing is that in C/C++ any non zero value in conditionals and loops are treated as true, and zero value is considered as false.

interesting question: WAP to print your name without using semicolon. how to do that: By using the printf statement inside the if statement conditionals

But this is not possible in Java because it is a strongly type language. Here we have clear rules, so in a condition it must have a bool. So it'll throw an error saying that it expects only of bool type.

### Arrays

Arrays are reference data type. It is 0 based.
We can create arrays of different types be it float, int, char, etc.

Functions that you are supposed to know in arrays(taking the example following example):

```java
float arr[] = new int[5]; // explicitly defining the size of the array, then adding, method
arr[0] = 1;
arr[1] = 2;
arr[2] = 3;
arr[3] = 4;
arr[4] = 5;
// or
int arr[] = {1, 2, 3, 4, 5};
// or
int[] arr = {1, 2, 3, 4, 5};
```

- `arr.length` : returns the length of the array

But we also have this **`Arrays`** class in Java which has a lot of functions that we can use to manipulate the arrays. Some of the functions are:

- `Arrays.sort(arr)` : sorts the array in ascending order
- `Arrays.sort(arr, Collections.reverseOrder())` : sorts the array in descending order
- `Arrays.fill(arr, 10)` : fills the array with 10
- `Arrays.toString(arr)` : prints the array
- `Arrays.binarySearch(arr, 10)` : searches for the element 10 in the array

Note: In Java, array indexes only accept integers, so if you try to pass a long, it'll throw an error. In C++ it is possible to pass longs as indexes. It makes sense because in CP, the max array size goes till 10^6 which is similar to the max value of an integer in Java, so Java people find it correct to limit the value of indexes to int only.

- If there are cases where we had to take a long and then we had to use it in the array index part as well then in such cases we'll need to explicitly cast it to an int, using typecasting like `arr[(int) i]`.

Multidimensional arrays

```java
int[][] arr = new int[2][3];
arr[0][0] = 1;
arr[0][1] = 2;
// .......
// or
int arr[][] = {{1, 2, 3}, {4, 5, 6}};
```

Whenever we get `[]`, we must know that this is an array and it is of what type, of whatever type it is written on the very left. And the no of `[]` tells us the dimension of the array.

Preferably use this syntax for the start part `int[] arr`

Also you can initialize the array to size 0 like this: `int[] arr = new int[0];` but it can't store anything. If you try store anything in it, it'll throw an error because it is of size 0.

**`Integer`** wrapper class: It is a reference type and it is immutable. So if you change the value of the object, it'll create a new object in the memory and the old object will be garbage collected. So it is not recommended to use it in the loops because it'll create a lot of garbage objects and it'll slow down the program.

```java
String s = "1234";
int x = Integer.parseInt(s); // can also do this then add x to the sout
System.out.println(Integer.parseInt(s)); //prints out 1234
```

We have got similar functions for other data types as well like `Float.parseFloat()`, `Double.parseDouble()`, etc.

You can convert a reference type variable to a primitive type variable using the concept called boxing and unboxing. In boxing/wrapping, we convert(boxed) a primitive type to a reference type and in unboxing, we convert(unboxed) a reference type to a primitive type.

```java
Integer i = 10; // boxing
int j = i; // unboxing
```

### Typecasting

Typecasting is the process of converting one data type to another. There are two types of typecasting:

- Implicit typecasting: In this type of typecasting, the compiler automatically converts one data type to another. For example, if you assign an integer value to a float variable, the compiler will automatically convert the integer to a float.
- Explicit typecasting: In this type of typecasting, the user explicitly converts one data type to another. For example, if you assign a float value to an integer variable, you need to explicitly convert the float to an integer.

```java
double x = 1.1;
int y = x; // implicit
int y =(int) x; // explicit
sout(y); // 1
```

edge cases: Here we are getting loss of precision because the float can store more values than the int. So when we convert the int to float, we are losing some precision. So in such cases, we need to use explicit typecasting.

Here we can't use implicit version of typecasting since the compiler will throw error, so for forced typecasting we need to use explicit typecasting, do note that you must be okay that you are losing data doing so.

```java
long l = 123456789;
int i = (int) l;
```

But when converting from larger type to smaller type we can do something like the following, since there is no chance of data loss.

```java
int l = 1234;
long i = l; // implicit typecasting works perfectly
```

This throws error, since int can't be converted to int since 1 is considered int so can't do this. Why because the compiler will prevent data loss and as such it'll prefer putting the stuff in the bigger memory type one instead of the smaller between the two and hence the result of `first + 1` will always be int and so errrrrr.

```java
short first = 1;
short sec = first + 1;
System.out.println(sec);
```

To convert to float just add `f` at the end of the number, to convert to long add `l` at the end of the number.

### Strings

Java revolutionized the way we use strings. In C/C++ we used to have character arrays, but in Java we have the `String` class. Strings are immutable in Java, so if you change the value of the string, it'll create a new object in the memory and the old object will be garbage collected.

```java
String s = "Hello";
s = s + " World";
System.out.println(s); // Hello World
```

String is a reference type, i.e an array of characters, so we can access the characters of the string using the index. But we can't change the value of the characters of the string.

```java
String s = "Hello";
System.out.println(s.charAt(0)); // H
```

We are supposed to add a `new` keyword to create a new object in the memory, but we are not supposed to do that everytime even if we are creating a reference type and in this case of `String` we are not supposed to use the new keyword but follow the same old syntax.

NOTE: `arr.length` is a property and not a function, so it doesn't have `()` at the end. But for functions we need to have `()` at the end. But length for `Strings` needs brackets since we are using the `length()` which is a member function inside the `String` class.

For accessing the individual strings using indexes, we use array like syntax in C/C++ but in Java we use the `charAt()` function with the dot operator on which string we want to operate.

More use case:

1. Lets say we want to create a substring out of a string, for that we have a function for this which is `substring(first_index, second_index + 1)`. It can take one argument or two arguments. If we pass one argument, it'll return the substring from that index to the end of the string. If we pass two arguments, it'll return the substring from the first index to the second index. Do note that the second index is always exclusive, while the first arg is inclusive. And for that reason, we add 1 to the second index. Because the second index will be considered one index less than index.

```java
String s = "Hello World";
System.out.println(s.substring(6)); // World
System.out.println(s.substring(6, 8)); // Wo
```

If you check the equality using `==` operator, it'll check the reference of the object which is not what we want. So to check equality for the contents of the object, you need to use the `equals()` function.

```java
String s1 = "Hello";
String s2 = "heeee";
System.out.println(s1 == s2); // false, but this is not what you want since this checks the reference of the object
System.out.println(s1.equals(s2)); // false
```

We need to remember that when we are using primitive types we are good with using the `==` operator since they'll always check for value but not the reference but when we are using reference types when we want to check for value we need to use the `equals()` method.

Yes, your statement is correct for Java. In Java, when you compare primitive types using the `==` operator, it checks if the values of the operands are equal. However, when you compare reference types using the `==` operator, it checks if the references (memory addresses) of the operands are the same, not their values.

To compare the values of reference types, you should use the `equals()` method provided by the class or interface. The `equals()` method is typically overridden in classes to compare the values of the object's attributes.

Here's an example to illustrate the difference:

```java
// Comparing primitive types
int a = 10;
int b = 10;
System.out.println(a == b); // Output: true

// Comparing reference types
String str1 = "Hello";
String str2 = "Hello";
String str3 = new String("Hello");

System.out.println(str1 == str2); // Output: true (str1 and str2 refer to the same object)
System.out.println(str1 == str3); // Output: false (str1 and str3 refer to different objects)
System.out.println(str1.equals(str3)); // Output: true (values are equal)
```

In the example above:

- Comparing primitive types `a` and `b` using `==` checks their values and returns `true`.
- Comparing reference types `str1` and `str2` using `==` checks if they refer to the same object and returns `true` because they both refer to the same string literal in the string pool.
- Comparing reference types `str1` and `str3` using `==` checks if they refer to the same object and returns `false` because they refer to different objects (one from the string pool and one created using `new`).
- Comparing reference types `str1` and `str3` using `equals()` checks their values and returns `true` because the `equals()` method in the `String` class compares the characters in the strings.

So, in summary, for primitive types, you can use `==` to compare values, but for reference types, you should use `equals()` to compare values, unless you specifically want to check if two references point to the same object.

### for each

We just get rid of the index iteration part and we just say to the compiler that using the variable `i` iterate over the array `arr`, which puts the values of the array one after the another in i and then we can use that `i`(new set variable to iterate with) for different tasks inside the for block.

It'll be used where we don't have any use of the index of the array, we just need the value of the array. If we try to change the content of the array using this loop, we can't do that.

The syntax is something like the following where we have the for loop and then in the parentheses, the type of the variable to iterate with and then the original array name to iterate on and then the block of code that we want to execute using that new variable.

```java
for (int i : arr) {
  System.out.println(i);
}
```
