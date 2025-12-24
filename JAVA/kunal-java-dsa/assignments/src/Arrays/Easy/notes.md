# random notes

## qno9.java leetcode 1389: Create target array in the given order

Example 1:

Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:

[//]: # (make a table here)

| nums | index | target |
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]


Here we'll have to use ArrayLists instead of arrays here because the array will be a very costly process for a big number in this nums. We'll have to shift all the elements to the right whenever we find an element that gets put in the old already used index.

In lists shifting is not very costly.

