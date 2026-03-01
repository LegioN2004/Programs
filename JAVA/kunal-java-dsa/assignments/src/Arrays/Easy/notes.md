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


## qno10.java leetcode 1832: Check if the sentence is pangram

You can align the boolean array with the alphabet by using the character's ASCII value. For each lowercase letter, calculate its index as `c - 'a'`, where `c` is the character. This gives you an index from 0 (for 'a') to 25 (for 'z'). Set `bool[c - 'a'] = true` when you find a matching letter.

Example:
```java
for (char c : sentence.toCharArray()) {
    if (c >= 'a' && c <= 'z') {
        bool[c - 'a'] = true;
    }
}
```
This way, each letter in the alphabet maps to a unique index in the array.

The issue is in your second loop:

```java
for (boolean b : bool) {
    if (b == false){
        return false;
    } else {
        return true;
    }
}
```

This loop returns after checking only the first element, so it never checks the rest of the array. To fix it, you should return `false` if you find any `false`, but only return `true` after the loop finishes (meaning all are `true`):

```java
for (boolean b : bool) {
    if (!b) {
        return false;
    }
}
return true;
```

This way, the function only returns `true` if all letters are present.


## qno11.java leetcode 1773: Count items matching a rule

You can loop through the array like this:

```java
for (int i = 0; i < arr.length; i++) {
    String value = arr[i][2]; // This gets the third element of each row
    // You can now check or use 'value' as needed
}
```

This will access the third element (index 2) of each row in your 2D array.