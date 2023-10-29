# This is a file to store my frequently faced errors just to remember these

## some maths stuff

- Even though 3.14 is a floating-point number, it is stored as a double in Java. This is because by default, any floating-point literal that is not explicitly declared as a float is interpreted as a double.

- In the fibonacci series firstly take three vars and give them 0 , 1 , 0 respectively. Then in the while loop the condition should be one less than the input number. The var should be one becoming 0

- Integer division in floating point context -> this error occurs when you perform division between integers inside a context where floating-point numbers are expected or involved. It indicates that you might be using integer division where floating-point division is expected or preferred. This can lead to unexpected results or loss of precision in calculations.
  - **NOTE** remember the computer doesn' calculate like humans do like if I does this

   ```java
        int discRate = in.nextInt(); // discRate = 50 (%)
        double disAmount = oriPrice * (discRate/100); // oriPrice = 2000
   ```

   here discRate is declared int type already and so if i put a number here like 5 then disay will get the value as 0, since the computer doesn't do divisions like from num to denom i.e 5 *20 = 100 then 20* 100 = 2000, it doesn't do like that. It will instead show 0 since it will do the division like 5 / 100 = 0.05 and since the discRate is int type it will only take the int part and remove the fractional part and so the disAmount gets the total calc as 0
  - Also java does follow the BODMAS rule and doesn't follow this rule when the calculations are separated by brackets, separated by brackets means literally that. So while doing calculations do not do any silly mistakes such as placing brackets unnecessarily as it will not give the desired result. For eg: ((1 - 10) / 100)^2 and (1-10/100)^2 gives different results one gives 1.62 and the second gives 162, so beware of proper usage.

- In Java, you don't always need to initialize a variable with a specific value when declaring it. However, local variables (variables declared within methods, loops, or blocks) need to be explicitly initialized before you can use them.
   When you declare a variable without initializing it, Java assigns a default value to the variable based on its data type. For example:
  - int: The default value for an int variable is 0.
  - double: The default value for a double variable is 0.0.
  - boolean: The default value for a boolean variable is false.
  - char: The default value for a char variable is the null character '\u0000'.
  - Reference types (e.g., String, custom classes): The default value is null.

   However, it's a good practice to explicitly initialize variables with meaningful values before using them to avoid unexpected behavior or errors. By initializing variables with appropriate values, you ensure that they hold the intended data.

   For example, if you declare an int variable to store the sum of numbers, it's common to initialize it with 0 initially, as you want the sum to start from 0 before you accumulate the actual values. `int sum = 0;` This way, you avoid any potential issues caused by using an uninitialized variable, and you establish a clear starting point for the sum.

- don't forget to add the 0! = 1 in the factorial questions so that finding 0 in factorial doesn't show some unusual output

   ``` java
   static int Factorial(int n){
           int a = 1;
           // don't forget to add the following which is 0! = 1
           if(n == 0){
               a=1;
               return a;
           }
           do{
               a = n * a;
               n = n - 1;
           } while (n != 0);
           return a;
       }
   }

   ```

- Also when attaching and storing the individual digits to one number, use the following logic

```java
 int digit = n % 10;
reversed = reversed * 10 + digit; // don't forget this, this stores the no in the main form here in this case it is forming a 3 digit number after removing digit from the input 101 to find the palindrome
n /= 10;
```

## some string stuff

- Certainly! In programming, especially in languages like Java, string indices and lengths are important concepts to understand. Here's some more information:

   1. Indices: A string is a sequence of characters, and each character in the string has an index associated with it. In most programming languages, including Java, string indices start from 0, which means the first character of the string is at index 0, the second character is at index 1, and so on. For example, in the string "Hello", the character 'H' is at index 0, 'e' is at index 1, 'l' is at index 2, and so on.

   2. Length: The length of a string refers to the number of characters it contains. In Java, you can obtain the length of a string using the `length()` method. For example, `String a = "Hello"; int length = a.length();` will assign the value 5 to the variable `length`.

   3. Index Out of Bounds Error: The "index out of bounds" error occurs when you try to access an element (character) of a string using an invalid index. Since indices start from 0 and go up to `length - 1`, trying to access an index outside this range will result in an error. For example, if a string has a length of 5, valid indices are 0, 1, 2, 3, and 4. If you try to access index 5, which is out of bounds, you will get an "index out of bounds" error.

   ```java
   public class ReverseAStringQno15 {
       public static void main(String[] args) {
           Scanner in = new Scanner(System.in);
           System.out.print("Enter an example string: ");
           String a = in.next();
           int b = a.length();
           for (int i = 1; i <= b; i++) {
               System.out.print(a.charAt(b-i));
           }
       }
   }
   ```

   In the code snippet, the error occurred because I used `b` as the index to access characters in the string `a`. However, since `b` is equal to the length of the string, it is out of bounds because the indices range from 0 to `length - 1`.

   To access the characters correctly, you need to adjust the index by subtracting `i` from `b` in the line `System.out.print(a.charAt(b - i));`. This ensures that you stay within the valid index range of the string.

- When you use `while(true)` while loop with the true condition, then you need to have a break statement that will break out of a loop after a certain condition is met. It is necessary since the while with the true condition is an infinite loop and so we need to end it after sometime
- You can use conditions like the ones in the brackets of if-else statements directly in the return statements to return boolean true or false if there is only one if and else statement (or accordingly), which helps to simplify and reduce code.
- Err in the question **print a greeting messsage that specifically shows up for a particular input name**: The code you've provided uses if (greeting(a).equals("mili")) to check if the result of the greeting function is equal to the string "mili." If this code is causing an error, it's likely not due to the use of == versus .equals(). Both can be used to compare strings in Java, but they have slightly different behaviors:

  - == compares the references of the two string objects. It checks if the two string variables point to the same memory location. This might work for some cases, but it's generally not used for comparing the content of strings.

  - .equals() compares the actual content of the two strings. It checks if the characters in the two string objects are the same.

  - The reason you should prefer .equals() when comparing strings is that it compares the content, which is usually what you want.

    If your code is causing an error, it might be due to another issue, such as a NullPointerException if greeting(a) returns null. Ensure that the greeting function always returns a non-null string to avoid such errors.

- You can do function calls for 2 or three or more arguments/parameters and they'll follow the order and sequence while running i.e it'll first run the first function that takes a param and passes the consecutive argument, run the function properly come back and then again run the following same function but for different arguments/parameters which has been provided after that, and it'll surely help.

- The error "primitive int n doesn't have a field length in Java" means that you are trying to use the length() method on a primitive int type. Primitive types do not have methods because they are not objects in Java. To fix this error, you can use the length property of an int array instead.
