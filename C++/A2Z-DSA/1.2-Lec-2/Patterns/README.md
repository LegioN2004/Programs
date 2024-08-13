# All about patterns

Why is it necessary? Because it teaches us all about loops and this is one of the most important things to learn in DSA.

## Trick to solve any pattern

Note that it'll always have nested loops.

- patterns will have two loops, outer and innner
  - outer loop will be responsible for the number of rows
  - inner loop will be responsible for the number of columns

So the rules for solving these are based on the above points.

1. For the outer loop, count the no of rows/lines.
2. For the inner loop, focus on the columns and connect them somehow to the rows.
3. Whatever is being printed, print them inside the inner loop.
4. Observe symmetry in some patterns(optional, since it can be applied to some patterns).

Example: four lines of stars

``` shell
****
****
****
****
```

Now according to the rules

1. outer loop runs for four times, i.e `for(int i = 0; i < 4; i++)`
2. inner loop should print four stars as well since for all the rows(0, 1, 2, 3) we need four stars, i.e `for(int j = 0; j < 4; j++)`
3. Then join the logic and it will run properly

**NOTE**: Do note that the times will be given as input so we will get that in the main function and then pass it to the function which will print the pattern, something like this. Using that we can print it for however lines we want. For now we are doing this, but the main function code will not be shown and is not expected to write by us, we just need to write the main logic function. Also that snippet function will be given.

```java
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int n = in.nextInt();
            pattern1(n);
        }
    }
    /*
    and the input is like the following
    2
    4
    5
    */
```

So here the input is 2, so the pattern will be printed two times, for 4 lines and then for 5 lines.

- Pattern 1
- Pattern 2

- Pattern 7
  - This one's a little tricky, we'll have to print the following. It is a pyramid pattern, with a column count of 9 and a row count of 5

   ```java
    /*
         *
        ***
       *****
      *******
     *********
     */
   ```

  - So using the rule stated above we can use think it like [space, star, space]. For the first row, [4, 1, 4], for the second row [3, 3, 3], [2, 5, 2], [1, 7, 1], [0, 9, 0].
  - Now for the space part is easy it's just the given `n` in just descending order(indexing may change the way it goes but), it is `n - i - 1` where n is the number of rows and i is the current row number. So for the first row, it will be `4 - 0 - 1 = 3`, for the second row, it will be `4 - 1 - 1 = 2` and so on.
  - The star part will be `2 * i + 1` where i is the current row number. So for the first row, it will be `2 * 0 + 1 = 1`, for the second row, it will be `2 * 1 + 1 = 3` and so on.(couldn't figure it, I am dumbooooooo)
  - And then we can repeate the space part again, and voila we're done

- Pattern 9
  - This is a diamond pattern, and we can solve this by joining both the patterns 7 and 8.

   ```java
        /*
             *
            ***
           *****
          *******
         *********
         *********
          *******
           *****
            ***
             *
         */
   ```

- Pattern 10
  - This is a left diamond pattern. So we have to find the symmetry point here and then we can flip the logic from that point onwards and the first part logic has already been done in the previous pattern.

   ```java
        /*
         *
         **
         ***
         ****
         ***
         **
         *
         */
        for (int i = 1; i <= 2 * n - 1; i++) {
            int stars = i;
            if (i > n)
                stars = 2 * n - i;
            for (int j = 1; j <= stars; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
   ```

- Pattern 12
  - This is a that space and numbers pattern. So it'll go loke [numbers, space, numbers]. the rows are:
    - first: [1, 6, 1],
    - second: [2, 4, 2],
    - third : [3, 2, 3],
    - fourth: [4, 0, 4].
  - So the pattern is something like the numbers are in the order of rows, and the spaces are

   ```java
        /*
         * 1             1 
         * 1 2         2 1
         * 1 2 3     3 2 1 
         * 1 2 3 4 4 3 2 1
         */
   ```

- Pattern 14
  - This pattern needs to work with char so fortunately both java and cpp allows us to increment directly with the char.
  - explanation below

  ```java
   /*
    * A
    * A B
    * A B C
    * A B C D
    * A B C D E
    */
  ```

  Explanation:
  - `for (char ch = 'A'; ch <= 'A' + i; ch++)`: This loop runs from `'A'` to the character that is `i` positions after `'A'`. For example, if `i` is 2, it runs from `'A'` to `'C'`.
  - In computer memory it works exactly like the numbers, so `'A' + 0` is A, `'A' + 1` is `'B'`, `'A' + 2` is `'C'` and so on.

- Pattern 16
  - First loop is for the row part
  - The `char ch = (char) ('A' + i);` part is used to print the characters in the order of the rows.
  - The second loop then prints the characters in the order of the columns, and also prints it in a repeated manner.

  ```java
  for (int i = 0; i < n; i++) {
      char ch = (char) ('A' + i);
      for (int j = 1; j <= i; j++) {
          System.out.print(ch + " ");
      }
      System.out.println();
  }
  ```

  - Here in Java, we have done explicit typecasting due to the language's strict type system which is not necessarily true for C++:

  - In the following Java code, the typecast ensures that the result of the arithmetic operation is treated as a character:

  ```java
  char ch = (char) ('A' + i);
  ```

  - Why C++ allows: Due to its more implicit conversions due to its flexible type system. When performing arithmetic operations with characters, C++ can automatically handle the conversion from `char` to `int` and back to `char`. Hence it doesn't require explicit typecasting.

  ```cpp
  char ch = 'A' + i;
  ```

  - In Java, the expression `'A' + i` involves adding an integer to a character. Characters in Java are represented as 16-bit Unicode values. The result of `'A' + i` is promoted to an `int`, and to assign it back to a `char`, explicit typecasting is needed to ensure the value fits within the `char` range:

  ```java
  char ch = (char) ('A' + i);
  ```

- Pattern 17
  - explanation below

  ```java
        /*
         *      A
         *     ABA
         *    ABCBA
         *   ABCDCBA
         */
  ```

  - The first and third for loop just prints the spaces in the order of 4, 3, 2, 1 by using `n - i - 1` where n is the number of rows and i is the current row number.
  - goes the same like the previous ones but the main part of the code is the second part of the snippet which solves the triangle part.
    - Here firstly we'll print A, then we'll go and print everything in the order of the rows, so for the second row, it will be ABA, for the third row it will be ABCBA and so on. And the code for that is odd_numbers / 2, so 1/2 = 0, 3/2 = 1, 5/2 = 2, 7/2 = 3, till here it increases and then it decreases. 

  ```java
            char ch = 'A';
            for (int j = 1; j <= 2 * i + 1; j++) {
                System.out.print(ch);
                // breakpoint part gives 1 3 5 7 9
                if (j <= (2 * i + 1) / 2) ch++; // 1/2 = 0, 3/2=1, 5/2=2, 7/2=3
                else ch--;
            }
  ```


- Pattern 19
  - This one's not that hard but it's a little tricky. all the sided triangle together and then a diamond spaced pattern in the center.
  - triangle part can be made easily, for the spaced part it is in even no order so it'll go like that.
  - The order is [stars, spaces, stars] and so the top half order is [5, 0, 5], [4, 1, 4], [3, 2, 3], [2, 3, 2], [1, 4, 1], [0, 5, 0]. And then create another outer row wala loop for printing the next part and so it'll be [1, 8, 1], ...., again even spaces. Do note that the iterative traingle loop will remain the same throught the left and right half for both the upper and lower half.


```java
        /*
         *   **********
         *   ****  ****
         *   ***    ***
         *   **      **
         *   *        *
         *   *        *
         *   **      **
         *   ***    ***
         *   ****  ****
         *   **********
         */
```