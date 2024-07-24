# Time Complexity

Why it is required: We will always write a piece of code in an interview, but the way to judge the code is not by running it, instead by knowing its time complexity. Whatever code that we will write will be judged by the two params: Time complexity and Space complexity.

Time complexity != Time taken to run: Because the code may take different time on running in different machines

It is the rate at which the time taken increases with respect to the input size. This is what is generally referred to as time complexity of any given code

## Big-O Notation

Time complexity is not calculated in terms of seconds, so there comes the Big-O Notation. Every piece of code takes time in terms of Big-O Notation so when we are asked of the time complexity by the interviewer we will have to answer in terms of Big-O Notation. It is known as the **worst-case complexity** or **upper-bound complexity**

It is written in terms of O() where we write the time taken inside the brackets

For example: lets consider a normal for loop.

```java
for(int i = 0; i < 5; i++){
    System.out.println("Helllo");
}
```

Then the Big-O of this is the no of steps that this code takes.

- First step is assigning the for variable,
- then comparison,
- and then printing
- lastly updation of the variable
- and then repitition of all the above steps sequentially from the second one

Whatever is the total no of steps that is what's written inside the brackets, that is called the prime Big-O notation.

We can't manually count the steps, so there are these following rules

- Time complexity are to be calculated in worst case scenario
- Avoid constants
- Avoid lower values

1. **Time complexity are to be calculated in worst case scenario**

Here the loop will iterate for 5 times and 3 steps are repeated continuously so the Big-O will be 5 \* 3 = 15. So O(15) is what we would write, Big-O of 15 is what it is called, but this is a number so we don't use it. We can change this to 'n', so this loop runs for `n` no of iterations where n = 5 for 3 times each, and as such the notation will be O(3n), Big-O of 3n.

There are three cases for a scenario:

- Best case
- Average case
- Worst case

```java
if(marks > 25) System.out.println("Graded D");
else if(marks > 45) System.out.println("Graded C");
else if(marks > 65) System.out.println("Graded B");
else System.out.println("Graded A");
```

Here if marks is 10, then grade is D, which runs in least no of steps i.e 2, so it is the "best case scenario" here and it is O(2). And if marks is 70, then it will be the "worst case scenario", since the code runs for 4 times, so it will be O(4) and this will be chosen. Why: Because we have to think for the worst case most of the times and

2. **Avoid constants**
   More example: O(4N^3 + 3N^2 + 8) where let N = 10^5 so it becomes O(4*10^15 + 3*10^10 + 8)
   Now when we put the value inside here, 8 won't have any significance on adding because it is a very small number compared to the others because they're huge. That is why we don't consider constants. So if we update the above example and add a 2 there, it should not be in the Big-O notation since that doesn't have any significance, so the ans still remains O(3n)

```java
int n = 2
for(int i = 0; i < 5; i++){
    System.out.println("Helllo");
}
```

3. **Avoid lower values**
   Taking the same above example: O(4N^3 + 3N^2 + 8) where let N = 10^5 so it becomes O(4*10^15 + 3*10^10 + 8).
   So if we add the ten to the power 10 to its 15 counterpart, it won't have any significance. So this is why we would avoid the lower values which doesn't change its significance by much.

This is what we should keep in mind while computing the Big-O Notation. It is very important for interviews

## Theta notation

This is the average complexity. This is for semesters only and will not be asked in DSA interview questions

## Omega notation

It is the lower-bound complexity which is the best case one. This is for semesters only and will not be asked in DSA interview questions

## Example solving

1. First question

```java
for(int i = 0; i < n; i++){
  for(int j = 0; j < n; j++){
      // some block of code, taking constant time
  }
}
```

Time complexity: O(2n)
explanation: for i = 0, j goes till n-1; for i = 1, j goes till n-1 again and that continues till i goes for n-1. So for every i, j goes till n until i becomes n, so n + n + n ...... n, i.e n\*n. So the Big-O will be O(N^2)

2. Second question

```java
for(int i = 0; i < n; i++){
  for(int j = 0; j <= i; j++){
      // some block of code, taking constant time
  }
}
```

Time complexity: O(N^2) (acc to the rules); Exact time complexity O(n^2/2 + n/2)

- explanation: 1 + 2 + 3 + 4 + .................. + n, which is the sum of first n natural numbers, so it is (n \_ (n-1) / 2) = n^2/2 + n/2 = n^2/2 = n^2 (remove the constants i.e half and smaller nos i.e n/2)
  - i = 0 { j = 0 }
  - i = 1 { j = 0, 1 }
  - i = 2 { j = 0, 1, 2 }
  - .......
  - .......
  - .......
  - .......
  - i = n-1 { j = n-1 }

# Space Complexity

It is the memory space that our program takes. But it will vary from machine to machine so in order to find calc we are going to use the Big-O notation, and not in kb, mb, gb.

It is nothing but **auxilliary space** + **input space**. Auxilliary space is the space required to solve the problem and the input space is the space taken to store the input.

Eg: let there be input given to a and b and let c = a + b; So the auxilliary space is the space used by c, i.e an extra variable. So if you use any extra space or variable that is termed as an auxilliary space. And the ones given as an input will be termed as input space i.e a and b. And the combined one is termed as space complexity or O(3) because we are using 3 variables.

If we are making an array of size n, then the space complexity of that will be O(n)

Also if you are storing the value of the a + b in b and not a third variable, it is okay, takes less space but in an interview it'll be considered "not done", why. In terms of software engineering imagine writing code for a MNC and they give some data, we can't change that data directly which we are doing here. So the main rule is never change anything in the input. It is okay if it takes extra space like O(2N) instead of O(N), but as long as the interviewer doesn't allow it don't do it.

## misc stuff related to CP and contests

Most coding platforms and places where contests take place are roughly on the same server of that platform and as such they take same time for all the participants

Now if there is a **time limit** mentioned in the question/coding rounds, it means the following

- 1s ~ 10^8 operations (roughly +/-, most of the servers relatively same)
- 2s ~ 2 \* 10^8 operations
- 3s ~ 3 \* 10^8 operations
- 5s ~ 5 \* 10^8 operations

Time limit = 1s, its time complexity = O(10^8) avoiding constants and lower values
