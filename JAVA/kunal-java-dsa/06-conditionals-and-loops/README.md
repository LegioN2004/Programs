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

- From Q4 Counting occurences of a number(or letter): refer to the countOccurrence.java file from the source code for more context
- My solution as well as kunal's solution, (going directly towards the logic)
  - My solution contains the usage of for loop ( I have shown only the main function part

   ```  java
    public static void main(String[] args) { 
      int n = 333300000; // 4 must be the output here
      int c = 0, count = 0;
      for (int i = 0; i <= 4; i++) {
        c = n % 10; // this c will get remainder of the number till the last division of the input from n and  
        n = n / 10; // this will make the number short by one digit from the last and overwrite n
          if (c == 0) {
            count++ ;
          }
        }
          System.out.println(count);
    }
   ```

  Here we'll use division by 10 to find the no of occurences since division of any number by 10 gives the individual numbers as quotient as well as the remainder which can then be reused to find answers to these questions.
    1. First the for loop should be declared and then it should be set to run the loop according to x times where x denotes the no of digits present in the input number.
    2. Then declare and take another variable which takes the end digit of the number by finding the modulo `%` i.e the remainder of the number as it'll help in finding the occurence of the desired number.
    3. Also store the quotient of the number in another variable when dividing it by 10 so as to reduce the number after storing the end digit, since we don't want any repititions
    4. Then take an if conditional statment to check which no's occurence is needed followed by a count variable which gets iterated the no of times the condition catches the desired number
    5. Then output the count variable outside of the loop to show the no of occurences of the desired number.
    **NOTE** The declaration and for loop syntax is in the code itself, it is not required to explain them at this point of time.

  - Kunal's solution

  ``` java
  public static void main(String[] args) {
    int n = 400000;
    int count = 0;
    while(n > 0){
    int rem = n % 10; // last digit
    if (rem == 0){
      count++;
    }
    n = n / 10; // use this n /= 10 to make it shorter
    }
    System.out.println(count);
  }
  ```

  He has used a while loop to solve this question
    1. Firstly declare the required variables.
    2. Then take a while loop that runs as long as the number given is > 0
    3. Store the remainder in a variable as it'll help find the number of occurences.
    4. Then in a conditional statment(here if) give the rem the number which you want to find the occurence of
    5. Also reduce the no from the end so as to not show the same occurence in the same place again and again
    6. Then in the conditional statment iterate the count variable to show the no of occurence which will then be printed outside of the loop.

- Q5: Reverse a number:
- My solution

   ``` java
  public class reverseNOmine {
      public static void main(String[] args) {
          int n = 28479;
          while (n > 0) {
              int a = n % 10;
              n = n / 10;
              System.out.print(a);
          }
      }
      
  }
  ```

  1. first take a number
  2. take a while loop that runs as long as the number is > 0
  3. Store the remainder value in a variable.
  4. Also reduce the no from the end so as to not show the same occurence in the same place again and again
  5. Print the value of remainder variable.
  6. What happens is that the remainder variable will print from the last number and then after the reduction by n / 10, n will give the reduced number and so it'll print the numbers from the last gradually and a reverse no will be generated. Eg = firstly a will give 9 , 28479 will get reduced to 2847 and 3rd output line will print the 9, this will iterate till the last value i.e 2 and so a reverse no will be printed. **NOTE** This works only when the printing is done in the same line i.e `System.out.print(a);`

- Kunal's version

   ``` java
  `public class reverseNo {
    public static void main(String[] args) {
        System.out.println("Kunal's version of reverse a No problem ");
        int num = 28479;
        int ans = 0;
        while (num > 0) {
            int rem = num % 10; // 9
            num /= 10; // 2847
            ans = ans * 10 + rem; // 90 + 7  
        }
        System.out.print(ans);
    }
    ```

  1. first take a number, and also declare a variable as shown above in the code snippet
  2. take a while loop that runs as long as the number is > 0
  3. Store the remainder value in a variable, one that is found using modulo
  4. Also reduce the no from the end so as to not show the same occurence in the same place again and again
  5. Then do this: ans * 10 + remainder value
  6. Then use the single print line of the ans variable using the `System.out.print(ans);`
  7. Logic: the ans variable does the ans multiplied by 10 and then adds the remainder value and then outputs them outside of the loop. Eg: rem = 9, num = 2847 , ans = 0 _10 + 9 = 9 : then rem = 7 , num = 284 , ans = 9_ 10 + 7 = 97 ; so ans now stores 97 then this will iterate like that 97 _10 + 4 then 974_ 10 + 8 ....... and then we will get our desired reversed no.  

**TODO** _Make the calculator program better by adding more features like scientific operations, then adding a gui (using swing) and make it beautiful using css(learn that beforehand)

- Calculator program: Refer this file [calculator.java](https://github.com/LegioN2004/programs/JAVA/kunal-java-dsa/06-conditionals-and-loops/lec06-code/src/com/mili/calculator.java)_
  1. Declare the three variables required, two for doing the operations and one for storing the answer of that operation
  2. Then take a true while condition and in that loop take the input of the operator with `trim() and charAt(0)`
  3. Then take an if statement with the condition where we give the input operator to the declared variable(for storing operators) with OR `||`, since we need to operate which is given as an input among the these: '+'/'*'/'/'/'-'/'%'.
  4. Then take the numbers which we need to perform the operation, can be an input or a predefined value.
  5. Do the operation using if statements, and it has been set like when we press x or X , it will break out of the loop basically to cancel it using an `else if()` and if there is something else written which doesn't match the type of the operator i.e the char type then it'll print "invalid operator" by using the `else`.
  **NOTE** this x or X to cancel the operation and the invalid operator will work only for the top level if statment i.e when it is used with the condition having the operators declared other than that if it gets those type of invalid data type in the other nested if statments then it'll directly throw compiler error from javac
  6. Then it'll print the output using the third variable which we declared earlier outside of the if statment
