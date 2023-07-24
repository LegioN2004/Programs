# Methods (functions are known as methods in JAVA)

## All the basics about function

- When we need to repeat a certain code block like a hundred or thousand times, then copy pasting will be very inefficient and almost impossible if more changes are to made in those copy pasted code, etc. So in such cases we follow the ***DRY****(Don't repeat yourself)* format by using **FUNCTIONS** and in case of java, they are called **METHODS** since all the code that we write in Java are already under a ***class***. By using the method we can use repeat a certain block of code or any code without copy pasting.

- Methods has the following syntax:

```java
/* // main function will stay here and since it always runs first so after running it will call the funtion inside the main function and thus it runs in that manner

main(){  
return_type_name(); // here goes the respective function name, write it repeatedly to run the code under this function a no of times
    }

    access_modifier return_type_name(){
    // body of the function
    return statement;
    }

access modifier(coming later in OOP videos)
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
  3. Use the required return type for the value of the function call in which the returned value gets stored.(So here we are using the integer type and not the void type)
  4. *Here `return` is used to return the value of a variable to a function*. In this example we are returning value of the `sum` variable which returns the value of the code block in the function `sum2()` and this function can then be assigned to a variable to show the value or directly printed out using an output statement. *`return` also means that the work of the function is done and it will end now, so anything after that will be flagged as unreachable since it cannot be used it due to the return coming before that*.

``` java
public class Sum {
    public static void main(String[] args) {
        sum();
        sum(); // add this a no of times to make it repeat that many amount of times.
        int ans = sum2();
        System.out.println(ans);
        System.out.println(sum2());
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

### things to note

- If we put a function in a class then the function which is put inside the class is known as method. Since we put everything inside a class in Java, so the functions are called methods by default.

- Since the main function contains static so anything that is under the static must also be static. More about static in later videos.
