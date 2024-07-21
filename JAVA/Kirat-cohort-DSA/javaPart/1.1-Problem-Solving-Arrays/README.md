# Week 1: Basics of DSA and Problem Solving

### Some stuff for solving problems

Instead of initializing the value of a variable to 0 for setting the lowest possible number to a variable, you can also use `int a = Integer.MIN_VALUE` (in cpp it is `int a = INT_MIN`). We have got similar ones for other types such as `Long.MIN_VALUE`, `Integer.MAX_VALUE`, etc.

Initializing it with 0 is fine because the least possible integer value can be 0 but if we are trying to find out the max value of an array which also contains negative values then this type of initialization will be useful `Integer.MIN_VALUE`.

While solving the 2D array problems using for each loop, we must know that the loop iterates already on a 1D so you don't need to explicitly set a 1D variable to iterate in a 1D manner on the given 2D variable, just like in the following leetcode question no 1672. Richest customer wealth: You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the ith customer has in the jth bank. Return the wealth that the richest customer has.
A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

```java
class Solution {
    public int maximumWealth(int[][] accounts) {
        int count = 0;
       for (int[] account: accounts) {
        int sum = 0;
           for (int main: account){
            sum += main;
           }
           count = Math.max(count, sum);
       }
       return count;
    }
}
```

**867. Transpose of a matrix**:

- we need to find the rows and columns here, so to find the rows we can find the length of the matrix since that'll be always equal to the no of rows in the array and for the columns we can find the no of values in the first/any one of the value of the index since that'll be always equal to the no of columns.
- Then we'll need to have to make an output array that will store the transpose of the matrix and which will also return it. Note that it should be initialized with the size of the format of transpose that it'll be storing so that there is no index out of bounds error, i.e transpose[columns][rows]
- Since the rows and columns will interchange when there is not a square matrix we'll need to also interchange them when setting up the size of the matrix so that they don't err out on index out of bounds.
- Then the main logic, you can't use the for each loop since the indexes will be required to solve this question
  - So the main logic will have the first iteration which will be for the row and then the second iteration will be for the columns which will then be reversed within their places for storing the transpose.

**NOTE**: In coding contests, the questions will be well defined but in the interviews there'll be multiple rounds of these type of contests and there we should clarify the question with the interviewer, since a small piece of info can change the answer. The interviewers doesn't always tell all the info since they want the candidate to ask questions. Since in the real world while working you will always be approached by people in the workplace who will come to you with problems and they'll not be well defined most of the times. It is upto the engineers to ask questions, clarify the problem and then start solving instead of just jumping on the problem. You'll be studying about that on the 6th semesters in Software Engineering called lifecycles. Another use case can be when you'll be solving tree problems where the interviewer will tell you that you are given a binary tree but if it is a binary search tree then the problem might be a bit different so there's a property associated with it, in matrix if you have gotten square matrix(no of rows = no of columns) then you can leverage that to further optimize the solutions. So don't make assumptions and just ask questions.

***1572 Matrix Diagonal Sum***:

- The main logic is to find the sum of the diagonal elements of the matrix. The main diagonal is the diagonal that goes from the top-left corner to the bottom-right corner of the matrix. The secondary diagonal is the diagonal that goes from the top-right corner to the bottom-left corner of the matrix. Do note that you should not add the middle value twice if it is overlapping when going from the secondary side.
- So the main logic is to iterate over the matrix and then check if the row and column are equal, if they are equal then add the value to the sum of the main diagonal and then check if the row and column are equal to the length of the matrix - 1, if they are equal then add the value to the sum of the secondary diagonal.
- Then return the sum of the main diagonal and the secondary diagonal.
- The main logic will be a nested loop where the outer loop will be for the rows and the inner loop will be for the columns.
- The time complexity of this solution will be O(n) where n is the no of elements in the matrix.
- The space complexity of this solution will be O(1) since we are not using any extra space.
- The code will look something like the following:

The solving is happening row wise and as such we will be traversing from one row to another and there is no use of the column for loop

for the primary diagnoal it is easy since the index goes like 00, 11, 22, so it will be the `matrix[rowNo][rowNo]`.

main thing: Now the property of diagnoals is that the primary one shifts to the right by one and the secondary one shifts to the left by one as well. So the primary one is pretty straightforward but the secondary diagonal will be a bit complex which is `matrix[rowNo][matrix.length - rowNo - 1]`.

The thing is you need to figure out the pattern anyhow using the things given/calculated by us, and then solve it. Like how he did the row wise check for the primary diagonal and then the column wise check for the secondary diagonal, and then using the columns size minus the row no minus 1 to get the secondary diagonal. Row will always be the same here.

```java
class Solution {
    public int diagonalSum(int[][] mat) {
        int sum = 0;
        for (int i = 0; i < mat.length; i++) {
            sum += mat[i][i];
            int colNo = c - i - 1;
            sum += mat[i][colNo];
        }
        return sum;
    }
}
```

**977. Squares of a Sorted Array**:

- Companies asked:
  - 0-6 months: META 8, Yandex 8, Google 2, Apple 2, Yahoo 2
  - 6 mo-1 yr: Amazon 4, walmart labs 2, bloomberg 2, Tinkoff 2
  - 1-2 yrs: Uber 2, Microsoft 2, TikTok 2

The question firstly says that the array is in non-descending order which means that the array is in ascending order or increasing order and it won't decrease but there might be similar numbers.

Brute force approach:

For sorting we have an Arrays.sort() method in java which sorts the array in ascending order. But here we need to sort the array in ascending order of the squares of the numbers in the array. `Arrays.sort(sum);` you don't need to pass in the index, you just need to pass in the variable that is an array. In C++ we directly have a `sort` function which takes in the array.

Also do remember that no one is going to ask to recreate the sorting algorithm / inbuilt function, you just need to know how to use it. It's complexity is generally O(nlogn) where n is the no of elements in the array, they use the most opitimized method generally.

Time complexity: O(n) + O(logn) ~ O(nlogn) where n is the no of elements in the array.

Any extra space that has been used in the code will be counted in the space complexity. Here we are using an extra array to store the squares of the numbers in the array so the space complexity will be O(n) where n is the no of elements in the array.

Without using the sort function of the Arrays class: It is sorted in itself and we don't need to perform the sorted function. We'll create this array in such a way that we won't need to sort it again by using the positive number approach since squaring the numbers converts it into positive anyway.

here the question is asking for the array which is [-4, -1, 0, 3, 10] and the output should be [0, 1, 9, 16, 100]. So the numbers in the right will go on increasing and the numbers in the left will go on decreasing. The number at the right of 0 i.e 3 and left of 0 i.e -1 will be the next candidates after 0 and so we'll have to choose from the both. And this will go on, why a > b == a^2 > b^2 & -a < -b == a^2 > b^2.

### About time complexity

O(1) : Constant time complexity, it doesn't matter how big the input is, the time taken will be constant. For example, if you have an array of 100 elements and you want to access the 50th element, it will take the same time as accessing the 100th element. It is the most efficient time complexity.

O(logn) : Logarithmic time complexity, it is the time complexity of the algorithms that divide the problem into smaller subproblems and then solve them. For example, binary search, it divides the array into two halves and then searches for the element in the half where the element can be present. It is more efficient than linear time complexity but less efficient than constant time complexity.

O(n) : Linear time complexity, the time taken is directly proportional to the size of the input. For example, if you have an array of 100 elements and you want to access the 50th element, it will take 50 times more time than accessing the 100th element. It is less efficient than logarithmic time complexity but more efficient than quadratic time complexity. eg: the `for` loop part for the array.

O(nlogn) : Linearithmic time complexity, it is the time complexity of the algorithms that divide the problem into smaller subproblems and then solve them. For example, merge sort, it divides the array into two halves and then sorts the halves and then merges them. It is more efficient than linear time complexity but less efficient than quadratic time complexity. In cases where we see the usage of sorting algorithms, we generally see this time complexity.

O(n^2) : Quadratic time complexity, the time taken is directly proportional to the square of the size of the input. For example, if you have an array of 100 elements and you want to access the 50th element, it will take 2500 times more time than accessing the 100th element. It is less efficient than linear time complexity but more efficient than cubic time complexity.

O(n^2logn) : Quadratic logarithmic time complexity, it is the time complexity of the algorithms that divide the problem into smaller subproblems and then solve them. For example, quicksort, it divides the array into two halves and then sorts the halves and then merges them. It is more efficient than quadratic time complexity but less efficient than cubic time complexity.

O(n^logn) : Exponential time complexity, the time taken is directly proportional to the exponential of the size of the input. For example, if you have an array of 100 elements and you want to access the 50th element, it will take 10^50 times more time than accessing the 100th element. It is the least efficient time complexity.

O(2^n) : Exponential time complexity, the time taken is directly proportional to the power of 2 of the size of the input. For example, if you have an array of 100 elements and you want to access the 50th element, it will take 2^50 times more time than accessing the 100th element. It is less efficient than exponential time complexity. It is very bad in terms of time complexity.

O(n!) : Factorial time complexity, the time taken is directly proportional to the factorial of the size of the input. For example, if you have an array of 100 elements and you want to access the 50th element, it will take 100! times more time than accessing the 100th element. It is the least efficient time complexity. It is the worst time complexity.

Between two always choose the one with the lower time complexity, when asked for. Time complexity is called the worst case analysis, which means that my algo at its worst what will be the time taken. It is not the average case analysis, it is the worst case analysis.
