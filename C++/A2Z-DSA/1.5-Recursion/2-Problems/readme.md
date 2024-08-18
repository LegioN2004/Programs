# Solving some problems in recursion

## Problem 1: printing a name n times

Here the function goes as what normal recursion happens. But the thing where it is crucial is the one where we recall the function, there in the args passed `i` must be incremented since we are not using a for loop to do so. Otherwise the function is going to print unlimited times until the stack overflows, simple(I am kinda dumb for not doing that initially). Then after the condition is fulfilled the function ends.

```java
    static void namePrint(int i, int n) {
        if (i > n) {
            return;
        }
        System.out.println("G ILY");
        namePrint(i + 1, n); // main line
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        namePrint(1, n);
    }
```

![recursion tree](../assets/Screenshot%202024-08-18%20172052.png)

Time complexity: O(n)

Stack space: O(n)

## Problem 2: printing from n to 1

This is the same as the previous one but the only difference is that we are printing from n to 1. So the base condition is when `i < 1` and the function ends.

```java
static void noReversePrint(int i, int n) {
    if (i < 1) {
        return;
    }
    System.out.println(i);
    noReversePrint(i - 1, n);
}
```

## Problem 3: printing from n to 1 but not using i + 1, using something called backtracking

This is the same code but we know that till the function is not executed it remains in the stack then it will run until it reaches return and so by giving the print statement after the recurse call it will go on till the base_condition is met and then come back from the end to the start and print the values serially.

In these type of cases, we have kept the print statement after the recurse call, so we have made sure that the print statement is executed first. And also the input that gets in first and in the recurse part stays the same.

Last one is executed first, this is backtracking.

```java
static void noReverseBacktracking(int i, int n) {
    if (i < 1) {
        return;
    }
    noReverseBacktracking(i - 1, n);// 3, 4; 2, 4; 1, 4; then comes back and prints serially
    System.out.println(i);
}
```
