# Arrays and Arraylist

## Why do we need Arrays

Lets say we want to store 3 roll nos we can do that by declaring and initializing that 3 roll nos to 3 variables but we can't do that 100 times, in such cases it would be much efficient to store this collection of data of the same datatype in a certain data structure and so the Arrays come into the picture. 

## Arrays

### What is an array

An array is something where we can store a collection of datatypes which can be of the primitive, objects and even complex datatypes, whatever that we want to store we can store it in an array. Eg: below is an array of type int storing five roll nos

```java
int[] rollno = new int[5];
// or directly
int[] rollno = {23, 17, 9, 55, 7};
```

The syntax can of two types:
1. detailed one: `datatype[] variable_name = new datatype[size]`
   - Here `datatype[]` will be something like `int[]` where datatype/type of the stuff to be stored inside the array is to be specified. **It means that the reference variable (i.e variable_name) is pointing to an array object (i.e new datatype[size) that contains type (i.e datatype specified, in eg: integer) elements**
   - the first '[]' means that this reference variable is of an array
   - then we'll write variable_name followed by equals
   - then like Scanner class we will use new 
   - then write the datatype again with the size in brackets, size represents the no of stuff in the array
   - NOTE: We can't store different types of data in a single array, data must of the same type throughout the array.

2. `datatype[] variable_name = {stuff to be stored in array separated by commas}`
   - The first three points are the same as the above
   - The only difference between the two is that we'll directly initialize the stuff to be stored in the array in curly braces to the array reference variable
