# Methods (functions are known as methods in JAVA)

- If we put a function in a class then the function which is put inside the class is known as method. Since we put everything inside a class in Java, so the functions are called methods by default.

- When we need to repeat stuff like a thousand times, then copy pasting will be very inefficient and impossible if more changes are to made in those copy pasted stuff, etc. So in such cases we follow the DRY(Don't repeat yourself) format by using functions and in case of java, methods. By using the method we can use repeat a certain block of code or any code without copy pasting.

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

- Since the main function contains static so anything that is under the static must also be static. More about static in later videos.

- Function call is done by writing the name with a pair of brackets. We can also pass parameters in those brackets to So we can call the function in the main function a no of times to make the code under that function repeat.
