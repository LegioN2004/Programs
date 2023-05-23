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

1. In an if else statments only the code block of one of the statments run.
2. The condition in the brackets gives a true or false condition, the code runs according to that T/F.
3. We can use else-if statments to run multiple cases multiple times if necessary
4. Else condition will always remain in the end, it means if none of the above conditions are true then execute this condition.
5. **NOTE** We can use if's or else's multiple times in a if else statement without using if or else in those statements but it is important to note that using too many if statements or else statements can make your code difficult to read and understand. It is often better to use a more structured approach, such as using a switch statement or a case statement( coming later on maybe).

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
