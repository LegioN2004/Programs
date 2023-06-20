# Conditionals and loops

## If-else statements

``` java
if (boolean expression: True/False){
   code body do this
   } else-if{
   or do this
   } else-if{
   or do this
   } else-if{
   or do this
   } else{
   do this
   }
```

- In an if else statments only the code block of one of the statments run.
- The condition in the brackets gives a true or false condition, the code runs according to that T/F.
- We can use else-if statments to run multiple cases multiple times if necessary
- Else condition will always remain in the end, it means if none of the above conditions are true then execute this condition.
- **NOTE** We can use if's or else's multiple times in a if else statement without using if or else in those statements but it is important to note that using too many if statements or else statements can make your code difficult to read and understand. It is often better to use a more structured approach, such as using a switch statement or a case statement( coming later on maybe).

## Loops

### **FOR** loops

``` java
for (initialisation; condition; increment/decrement){
    // code body
}
```

1. In a for loop, in the brackets we have the initialisation part where it'll first declare the var as int or float or something else, then it'll give a condition till which the loop will run and in the increment or dec part it will either give a ++/ -- to inc or dec as per need and then the loop will continue. So after one time the loop runs the condition will be checked for true or false, if true it will go for inc/dec and then in the code body and if false it will break out of the loop and will run the remaining stuff next outside of the loop.
2. example

``` java
public static void main(String[] args) {
    // Q1 : Print the numbers from 1 to 5
    for (int i = 1; i <= 5; i += 1){
        System.out.println(i);
    }
}
System.out.println("the no is bigger than 5 loop break, stoppppooooooooo");
```

   here it'll first assign 1 to i then check for if the value of i is less than or equal to 5 or not, if yes go for the loop inside or if not break out. Then after the code body runs then it'll go for the increment/decrement (in case of this it will increase the value by 1) and then check again if greater than or equal to 5 or not, if yes go run the code body to print the number or if not break out of the loop. This will continue till the no reaches 6(which will false out the condition) in which it'll break out of the loop and eventually finish the code.

### **WHILE** loops

``` java
while (condition){
    // code body
}
```

1. In a while loop, in the brackets we'll write the condition and the loop will run accordingly, the condition will be checked if it is true or false, if true it will go for the code body and if false it will break out of the loop and will run the remaining stuff next outside of the loop.
2. In the code /loop.java/, we converted the above for loop example to while loop and the details of the conversion are written there
3. You can use for or while loop however you want but the following is recommended
4. **NOTE** when you don't know how many times the loop is going to run use the while loop
5. **NOTE** when you know how many times the loop is going to run use the for loop

### **Do-WHILE** loops

``` java
do{
    // code body
}while (condition);
```

1. One difference between while and dowhile loop is that a dowhile loop will run atleast once

   ``` java
         int n = 1;
         do {
             System.out.println(n);
         } while (n != 1);
         // 1.1 here the dowhile loop shows that even if n != 1 but still the loop runs one time because first it executes the body then it goes for the change condition which proves the above statement
   ```

2. In a do-while loop, after the closing curly brackets we'll write the while and condition and the loop will run accordingly, the condition will be checked if it is true or false, if true it will go for the code body and if false it will break out of the loop and will run the remaining stuff next outside of the loop.
3. In the code _loop.java_, we converted the above for loop example to while loop and the details of the conversion are written there

### Examples questions solved

- They are not much complex so it should be easy to understand just by the video itself, if not use the debugger or anything else but do it by yourself only otherwise progress will not be possible
- Some stuff to be noted from the questions solving

- From Q1 largestno.java
  - `Math.max(_int_ a, _int_ b)` Math.max class is used to find the max between two values. The values whose max is to be found should be given in the brackets with the correct type and the max value need to be stored in another var with the correct type , and we can use more of those classes in a nested manner with other values like here `Math.max(c ,(Math.max(a, b)))`.

- From Q2 CaseCheck.java : code `System.out.println(in.next().trim());`  
  - here `in` will take `input` from `System.in` and give it to the `next()` class which chooses the first word and then the `trim()` class just removes the extra spaces that come after/before the word/input.
  - Here we also have `charAt(0)`; it means give the character at the 0th index(can be any position of index acc to the no in the brackets) of the input.
  - **It will only take string input but not char, if it gets char then it will convert it to string using the `charAt()` class**. So we can store it in a char type. That's why we can declare the ch variable as char type due to the above
  - Now to check the case type, we can use the if condition statement with the declared variable to see if the letters lie in between a to z
    - _(Check the operators.java file for any doubts regarding operators, using directly here)_

  ``` java
    if (ch >= 'a' && ch <= 'z') { // here we are using the && operator to show if both the conditions are true or not. This condition is valid only if both the conditions before and after the && is true
        System.out.println("letter " + ch + " is lowercase");
    } else {
        System.out.println("letter " + ch + " is uppercase");
    } // if a word is given only the first letter will be taken or else just add a letter to find uppercase or lowercase.
  ```

- From Q3 fibonacci.java : The fibonacci series
  - Didn't undestand fully how this code worked, it just directly printed the value of the nth fibonacci number as given by the input. I'll need to dig in more.
  1. first take an input from the user using system.in
  2. Then take the values as given in the file, remember to take the value of count as 2 so that
  3. Then go for the while loop.
  4. Take a temp variable to store the value of 'b' such that the value of 'a' req to give to 'b' doesn't get overwritten when directly assigned the value 'b' i.e when written like 'a = b'.
  5. ..........................

- From Q4 Counting occurences of a number(or letter):
