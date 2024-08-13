# All the notes dump

## About the first question

In C, the `sizeof` operator is used to determine the size of a data type or an object in bytes. When you apply `sizeof` to an array, it gives you the total size of the array in bytes. However, if you want to determine how many elements are in the array (i.e., the length of the array), you need to divide the total size of the array by the size of a single element.

Here's why this division is necessary:

### 1. **Total Size of the Array:**

When you use `sizeof(array_name)`, C returns the total size of the array in bytes. For example:

```c
int faveNumbers[] = {7, 33, 13, 9, 29};
size_t total_size = sizeof(faveNumbers);
```

In the above example, `sizeof(faveNumbers)` will return `20`, because there are 5 integers, and each integer typically takes up 4 bytes of memory. So, 5 \* 4 = 20 bytes.

##
