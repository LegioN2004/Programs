# Arrays and Arraylist

## Why do we need Arrays

Lets say we want to store 3 roll nos we can do that by declaring and initializing that 3 roll nos to 3 variables but we can't do that 100 times, in such cases it would be much efficient to store this collection of data of the same datatype in a certain data structure and so the Arrays come into the picture.

## Arrays

### What is an array

An array is something where we can store a collection of datatypes which can be of the primitive, objects and even complex datatypes, whatever that we want to store we can store it in an array. Eg: below is an array of type int storing five roll nos

```java
// long method
int[] rollno = new int[5];
// which is similar to the following
int[] rollno; // Declare the array variable
rollno = new int[5];// Use the new keyword to allocate memory for the array and specify the size of the array in square brackets [] 

// Access and modify array elements and add the assign the values to the array using their indexes like the following way
rollno[0] = 1;
rollno[1] = 2;
rollno[2] = 3;
rollno[3] = 4;
rollno[4] = 5;

// or directly / easy method
int[] rollno = {23, 17, 9, 55, 7};


// misc stuff: for c people you can also do something like the following but it is not the java way to do it.
int rollno[] = new int[5];
```

### Syntax of an Array

- The syntax can of two types:

1. detailed one: `datatype[] variable_name = new datatype[size]`

- Here `datatype[]` will be something like `int[]` where datatype/type of the stuff to be stored inside the array is to be specified. **It means that the reference variable (i.e variable_name) is pointing to an array object (i.e new datatype[size) that contains type (i.e datatype specified, in eg: integer) elements**
- the first '[]' means that this reference variable is of an array
- then we'll write variable_name followed by equals
- then like Scanner class we will use new
- then write the datatype again with the size in brackets, size represents the no of stuff in the array
- NOTE: We can't store different types of data in a single array, data must of the same type throughout the array.

2. easy one: `datatype[] variable_name = {stuff to be stored in array separated by commas}`

- The first three points are the same as the above
- The only difference between the two is that we'll directly initialize the stuff to be stored in the array in curly braces to the array reference variable

### Array in details

- Breakdown of the steps of an array: `int[] arr = new int[5];`
- `int[] ros` is the declaration of an array, ros is getting defined in the stack
- when we do the next step `ros = new int[5];`, here the object gets created in memory(heap memory).
- The LHS part i.e initialisation part happens at the compile time whereas, the RHS part i.e declaration part happens at the runtime. Actual object creation in the heap memory gets done in the RHS part in the runtime. this is known as **dynamic memory allocation**.
- So what is *dynamic memory allocation*: At the runtime memory is allocated

- **Internally how does it work**:
- stack memory(in which all the function calls, ref vars, etc go) will hold the array , and the actual array object will be like {3,18,9,2} in the heap memory, and this array will point to this object.
- In many other languages, [3|8|19|12|7|28] these individuals act like a memory block and these blocks of memory are store continuously in C/C++, so arrays in C/C++ is like a *continuous memory allocation*. So it means that the ram/something in which they get stored, we'll have some cells [ | | | | | | ] there and each cell consists some address(pointers show that) and in the array all the cells of the array stores the memory continuously one by one and not like some in the first place some after 2 cells. But in Java, there is no concept of pointers and so you can't get the address of the memory and as such it totally depends on the JVM to handle these stuff.
- So Java doesn't have the concept of pointers because
- All the objects including arrays are stored in heap. If you dive deep into the language details like going to the JLS(java language specifications), you will get to know that there it has been specifically mentioned that in java heap objects are not continuous.
- Heap objects are not continuous. Heap is the runtime data area from which the memory for all the classes and instances of all the arrays is allocated. In C/C++ it means that if an array is allocated it will be allocated to continuous blocks of memory and not in an out of order fashion.
- And it has Dynamic Memory Allocation(DMA).
Hence array objects in java internally it may not be continuous, even though the definition of array says that it is a continuous data. JVM handles those stuff

- So arrays contain something called **index**(indices in plural) which represents the position of an array and it starts from 0. If we take the example from the above, print(arr[0]) is going to print 3, if index is given 3 it'll print 12 and so on. We can also change the values of an array using its index instead of just printing, like arr[0] = 99 then first position no will get changed to 99.

- What is the `new` keyword that we are always using? = `new` keyword is used to create an object in the heap memory. So if we do the above example `int[] rnos = new int[5]`, then it'll create an object in the heap memory of array size 5, it happens in the DMA. If we do the easy direct one directly assigning values to the array internally it works the same as the new keyword.

- By default, for an integer array the default value is 0, it is going to have all the 0 elements. So if we don't give any values to an array, the console output of that variable will be always 0. So internally, if it is of size 5 then it'll be something like this {0, 0, 0, 0, 0} and as such it prints 0 to every index output.

- If we try to print an empty String array with any index then it'll print null.

- About **null**:
- `null` means that it doesn't have any datatype and it is a special literal of null type. It's not a type nor an object, it is just a value assigned to any reference type and you can typecast null to any type as well but not to primitives.
- It can be assign/cast to any reference type i.e initialised eg: `String a = null;` but it can't be declared as a type eg `null a = something`.
- It is a separate thing in java and it doesn't like any database/etc and it can be compared to the `None` in python.
- It can only be initialized to non-primitives. It has null value.
- In simple words, any reference variable that you have that is not initialized to any value is by default going to have the null value.

- Primitives are stored in the stack memory only whereas all the other things/object are store in the heap memory

Internal working of object: eg `String[] arr = new  String[5];`

- arr is in the stack memory pointing to the array string in the heap memory which contains 5 elements. Each particular element is an object and each object will be stored in different parts of the memory.

- Each particular element of the array itself is an object here and they are going to be in different parts of the memory/heap memory. So this objects act like another reference variable that are pointing to those objects(the actual values that is given inside the array after initialization) and also they can be anywhere in the memory and since it is just declared so it is pointing to null for now. So it is actually and array of reference variables

- The long method will be very hard to store say like a thousand datas, very repititive so we can do something like using a for loop to take the input to the array as well as print those the array.
- Using the for loop:
- In the for loop we are using the (arr.length) method, which is used to find and print the length of an array and then we can simultaneously output them too in the same line like this

``` java
for (int i = 0; i < arr.length; i++) { // starting point is 0 following the index order of an array
    arr[i] = in.nextInt();
    System.out.print(arr[i] + " "); // we can also do something like this
}
```

- Using the **foreach** loop
- instead of using the loop two times we can use something called the for each loop which goes like this

``` java
for (int num : arr) { // for every element(num) in the array(arr), print the element
    System.out.println(num + " "); // here num represents element of the array
}
```

- Best and easiest way: Most easiest of them by using the **Arrays** class and then use a dot `.` and then `toString(var_name)` method to convert that string into an array. This to string converts it into a string and prints that string. Internally it is using the for loop only.

```java
for (int i = 0; i < arr.length; i++) { // starting point is 0 following the index order of an array
    arr[i] = in.nextInt();
}

System.out.println(Arrays.toString(arr));
```

- If we try to print an array of index that is greater than the declared size then it'll show error index out of bounds

#### Array of objects

``` java
// array of objects
String[] str = new String[4];
for (int i = 0; i < str.length; i++) {
    str[i] = in.next();
}

// can modify any, we have changed the 3rd index i.e 2's value
str[0] = "tera helooooooooooooooooooo"; // you are accessing the reference variable and directly changing its object hence the original also changes
System.out.println(Arrays.toString(str));
```

#### Behaviour of arrays in functions

- In java there is only pass by value and when we try to pass an object's reference it is going to take a copy of that object's reference which points to the same object.

```java
public class PassingInFunction {
    public static void main(String[] args) {
        int[] nums = { 3, 4, 5, 12 };
        System.out.println(Arrays.toString(nums));
        change(nums);
        System.out.println(Arrays.toString(nums));
    }

    static void change(int[] arr) {
        arr[0] = 99;
    }
}
```

- So here `nums`(ref var) is pointing to the object { 3, 4, 5, 12} and due to pass by value property, the copy `arr`(ref var copy, inside the function) is there too which is formed in the function but it points to the same original object, so when the 0th index value is changed in the function then it'll also change the original object as such affecting the main array after function call. This is called **mutable** behaviour.
- **Mutability**: It means the object can be changed. **NOTE** *Arrays are mutable in Java whereas Strings are not i.e* **immutable**.

### Multidimensional Array

#### 2D Array

- 2D arrays are something like matrix
- It's syntax is similar to that of an array but it takes two square brackets pairs instead of 1 something like this `int[][] arr = new int[rows][columns]`. So 1D array goes with one pair of square braces whereas 2D array goes with 2 pairs of those braces
- The square braces part after new and int will take values as rows and columns in order just like in any matrix formation style
- The columns part is not mandatory but we can add something to it whereas but the rows part is mandatory to be specified otherwise it'll show error
- The easy syntax method just as the 1D array is something like this

```java
int[][] arr = { // (easy way) directly adding the values
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
};
```

- Internal working of an array:
- In C/C++ 2D arrays are also continuous memory allocations but in Java it is different

```java
int[][] arr = { // (easy way) directly adding the values
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
};
```

- now the above matrix is in the heap and the ref var arr is in the stack memory.
- How is it being stored in the memory? = Every single array here represents an individual like data, like array of arrays. So every index here is an array i.e the first array consisting of '1, 2, 3' is of the index 0, the second '4, 5, 6' is of index 1 and the last one is of index 2. Basically it is stored like this arr is in stack pointing to the main array in the heap memory and the sub/internal arrays inside(since it is a 2D array) which can be in some other parts of the heap and individual ones are the references to this
'1,2,3' , '4,5,6' and so on as said above.
- So if we print like `arr[1]` will give `{4, 5, 6}` and of arr[1],[0] will give 4 since the main array itself consists another array at the 1st index and that arrays 0th index value is 4.
- Now the same process applies for 3D arrays, but after that it becomes hard to visualize
- Why the columns size doesn't matter? = The row size matters because of the no of places that will created in the heap memory is important and as such we have made three rows in the example. But the no of data given in the rows are of 3 columns size and we can have variable size of columns in individual rows and as such size of columns doesn't matter,
  - individual size of array can vary as well because each array itself is a different object created in the memory.
  - example:

  ```java
    { 1, 2, 3 },
    { 4, 5 },
    { 7, 8, 9, 10, 11 }
  ```

- 2D array input:

```java
//we are trying to print the following
{ 1, 2, 3 },
{ 4, 5 },
{ 6, 7, 8, 9 }
```

- We will need to do this just like the way we did earlier by adding input using for loop to every index of the original array
- When we print the length of the array using the method `arr.length`, it gives us the no of rows. As such when we declare an array with more no of columns than rows then it will print the max no of rows only.
- Now here the declaration part is different than the initialization part i.e what we are taking as input since the array is being declared using the long method(first declare an empty array of those params then take input), so the initialization part will be done using the for loop like this `for (int col = 0; col < arr2D[row].length; col++)` in which the `arr[row].length` means length of every array at that row
- How is it working internally:
- For the 2D array, the outer for loop is iterating each row and for every row every column is being iterated using another for loop inside the prev for loop. We are doing the 1D input part but for every row
- For the above example we'll have

```java
for (int row = 0; row < 3; row++) {
    // now we take every row
    for (int col = 0; col < size(arr[index]); col++) { // every row itself is an array of size 2
        arr[row][col] = input; // input 
    }
}
```

- firstly for row = 0 it will take the input, then it'll go for the column input and that is also 0 so it'll go for the first 1*1 index of the matrix and fill the value there, then it will go for the second column of the first row and fill it then the loop ends for the 0th index of the array and 0th index of the column. Now similarly row will be incremented and then the values for the second row will be added and the loop for the columns will run again as the first time. `arr[row].length`
- Firstly we take the size of the array as the one that will continue the rows loop, then inside that loop we'll take the size of the array of the 0th index or as such as the size that will take the size of columns correctly. Now in the example total size of the array is 3, so the loop will get the value using the arr.length then it'll run till the 2nd index and then it will go to the next iteration where it'll use the size of the first index of an array using arr.row.length and using those it'll print the columns.
- `arr[row].length` = no of columns in that index of an array. It says individual size of the rows only we need that many amount of columns. If first row has 3 columns run the for loop for the input 3 times, if it has 2 columns then run the for loop for the columns 2 only and respectively
<!-- - **NOTE**: here row literally means the keyword row, and not row number. Same goes for col -->

- Now for the output part

```java
// 2D array output
for (int row = 0; row < arr2D.length; row++) {
    // for each column in every row the input will be followin
    for (int col = 0; col < arr2D[row].length; col++) { // every array at that row, the length of that array
        System.out.println(arr2D[row][col] + " ");
    }
    System.out.println(); // to print it like a matrix you need to print it in a new line so you will need to a add a new line
}
```

First one is iterating for every loop and the second one is iterating for the column. We'll also need to add a new line to the array since otherwise it will show it in the same line, when the first row ends then it'll go the new line to print the next row.

- We can also use a inbuilt method `Arrays.toString[params/args]` to do the internal for loop easily. Every single element of the outside array is an array itself.

- now using the enhanced for loop. To iterate over the outside array, what is the datatype of every element, this is what is given at the first here. Here every element itself is an array for the outermost array so the first it'll have `int[]` then the variable where to store that `a` and after a colon we'll add the variable of which the type is specified at the first i.e `arr2D` which means in this array `arr2D` what is the type of the data of every element

``` java
for (int[] a : arr2D) {
    System.out.println(Arrays.toString(a));
}
```

- `System.out.println(arr.length);` gives the value of the no of sub-array present inside the main array and the `System.out.println(arr[row_no].length);` gives the no of elements present inside the specified sub-array by giving its respective row_no.

## ArrayLists

### Why do we need an ArrayList

- Here arrays are of fixed size, but what if the size is not known. If you want java to handle the size and let you input any no of elements that you want then the ArrayList comes into the picture for such usecases. If you have done C++ then it is similar to vectors in cpp and it is a part of the collection framework(more on this in OOP vids) and it is in the `java.util` package

### The syntax

- Firstly you need to write the name `ArrayList` followed by `<>` inside this angle brackets  the datatype is specified `Integer`(in this case) then you will need to give the var name which will store this arraylist `list` followed by equals then `new` to say that the new object is being created followed by another `ArrayList` which is a constructor (which we'll be looking onto later on) to say that an arraylist is being created and then another set of angle brackets but this time the specification of the datatype is not necessary inside of that and after that another set of circle braces in which we can pass the default size.
- The angled brackets from both the first and the second part of the syntax can be ignored but it is not a good practice, good practice will be specifying the generic (`Integer`) in which the ArrayList is going to be stored.
- Also in the generics you cannot pass primitives to specify its the type, you need to pass the wrapper classes. So here `Integer` used is the wrapper class for the primitive datatype `int`.

```java
ArrayList<Integer> list = new ArrayList<>(index_no);
```

#### Some details about ArrayList

- ArrayList is a class btw
- What is collections framework? : In C++ you may have heard people say that we have all sorts of stuff defined already done / written for us by some peope such as DSA stuff, etc for CP and we can just use them while doing CP to make our lives easier. Similarly for Java we have the collections framework which also has all those stuff's implementations already written and defined and it comes prebuilt inside of java.
- It is slower than the standard array since you can input as many things as you want in it.

### How to actually work with it?

- Here the stuff inside the first angle brackets `Integers` comes in the topic of generics inside of OOP so more details in that separate topic explanation.
- So generics is just saying what is the type of data that you can store in this object i.e `list` var.
- Whenever you use ArrayList, it calls a `toString`

### How does it work internally?

In arrays we were talking about list of references, like when you have an array of the objects then we have an array pointer i.e is the reference variable in the stack memory pointing to the array of objects in the heap memory and those list of objects here acts like a reference variable pointing to other objects. In ArrayList not every single element can be a primitive, since it doesn't allow it, but internally it is similiar to how arrays work.

- Once we declare and initialize the ArrayList then we can use that variable `list` and with a dot we can apply all sorts of functions that are available for this reference variable such as contains(to check if a number is present in that arrray or not), `toArray()` (to convert it to an array), `addAll()` (to add this array to another one), `list.set(3, 900);` which changes the third index no to 900 in the ArrayListExample file, etc.
- In all of the above inbuilt functions where we need to locate the element in order to make any change we'll surely need to use it's index in the array to do so.
- You can use `list.get(index_no)` to get the stuff that is at the given index number

#### How is it saying that no size is required, since we have declared it to be 10 but we can input like more than a hundred or thousand elements, how is it not fixed?

1. The size is fixed but internally
2. But lets say ArrayList fills by some amount, then what happens is that it'll create a new empty ArrayList of double the size(maybe not sure) of the old one and the old elements that are in the old list are copied in the new list and the old one is deleted.
3. Eg: initially lets say we have an ArrayList of size 4 i.e something like [1,2,3, ] {i.e 50% full} then when you will try to input an element again then it'll do something like this, 1st) double the size i.e [1,2,3,4, , ]. 2nd) then copy the previous elements over to the new one and 3rd) add the new just added elements after the old ones and when this also becomes half full then it'll double this again.

#### Multidimensional ArrayList

- Syntax

```java
Scanner in = new Scanner(System.in);
ArrayList<ArrayList<Integer>> list = new ArrayList<>();

// initialisation
for (int i = 0; i < 3 ; i++) {
    list.add(new ArrayList<>()); // and sets a size of 3 in the ArrayList
}

// add elements
for (int i = 0; i < 3 ; i++) {
    for (int j = 0; j < 3; j++) {
        list.get(i).add(in.nextInt()); // and also we'll use the i of first for loop to get all the indexes of the ArrayList and then we'll add the input of integers to those three sized ArrayList
    }
}

System.out.println(list);
```

- the first for loop is used to set a list of three in the ArrayList, but by not using the for loop we'll not be giving it any index which will make it null and the next list.get will not work since it'll not find any index to add the elements
- we'll be using this `list.add(new ArrayList<>());`,  to make a new ArrayList of desired size by adding the for loop numbers to the list as a size no maybe the no of times that loop iterates
- i.e we'll have to manually add some arraylists to an array to enter the objects/stuff in those lists of some size
- and for the input  `1 2 3 4 5 6 7 8 9`, the output is like this `[[1, 2, 3], [4, 5, 6], [7, 8, 9]]`
- Multidimensional array can also be printed by println output.

### Explanation of the example questions

```java
public static void main(String[] args) {
    int[] arr = { 1, 3, 33, 9, 18 };
    swap(arr, 1, 2);
    System.out.println(Arrays.toString(arr));
}

static void swap(int[] arr, int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
```

- Swap problem
  - Firstly we have declared an array and then a function to swap the array and in the swap function we'll declare the array 'arr' and the indexes to do the swap process and then the rest of the steps are history.

- Find the max element in the list and max element in a range of an array
  - MaxItems part: we are assigning an array of index 0 to the maxVal and then we are using a for loop that runs till the index length of the array. Then in the body of the array we're comparing the value of the array to the maxVal and if that the array index's value is greater than the maxVal then we assign that value to th maxVal and then we return the 'maxVal' max value.
  - MaxRange part: Here we also do the same as the above but instead we are using 2 more args other than the arr declaration i.e the start and end index of the array between which we are to find the max no
  - TODO: Learn more about edge cases and how to work with them

- Reverse an array
  - the way it'll work is that for an odd no of arrays, we'll start at the first index and end at the last index and then reverse, basically we'll increment start by 1 and decrement last by 1 and repeat the prev steps till we reach the middle single element will be swapped upon reaching.
  - For the even no of elements we'll do use the same technique, start at first index and last at end index then swap. End and start will each reach one element in this case and the swap will take place. Eg: we'll be using `start = 0` and `end = arr.length-1` (-1 because arr.length gives the length and it starts from 1 so it'll be out of bounds).
  - The loop will end when start becomes greater than 1
  - The method we are using is termed as **two pointer method**.
