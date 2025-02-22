# Learning Python using a new playlist: telusko

will be documenting only the important things worth noting here

## 3rd video: Getting started

- 3 \*\* 2 means 3 to the power 2 i.e nine
- round method can be used to round off the number to the nearest integer using the first parameter as the number and the second parameter as the number of decimal places to round off to. Since by default python prints the number to 15 decimal places, we can use `round` to round off the number to a specific number of decimal places.
- Strings should be used wisely, like if you need to print single or double quotes then you do this, like in combination then do.

    ```python
    print('I\'m learning python')
    print("don't")
    print('hi " bye')
    print('navin\'s "laptop"')
    ```

- Here \n also means new line, so printing `C:\Documents\newFolder` prints the path in a new line, to avoid this we can use `r` before the string to make it a **raw string**.

    ```python
    print(r'C:\Documents\newFolder') # ignores the \n here as a newline character
    ```

## 4th Video: variables

- variables are just like js
- but for strings we can use array number with [] to get the character at that index
  - we can also use negative index to get the character from the end of the string, which works like:

    ```
            [0,1,2,3,4,5,6,7,8,9] = [-10,-9,-8,-7,-6,-5,-4,-3,-2,-1]
    ```

  - we can also use the index to print from one index to another index, like `print(name[0:3])` (name = youtube) will print the characters from 0 to 2, 3 is not included, i.e you only. This is called **slicing**. If you don't provide the first index then it will start from the beginning and if you don't provide the second index then it will go till the end. name[1:4] gives 'out', name[3:10] gives 'tube' but no errors considering the index goes till 6.
- **Strings in python is immutable**
  - There are workarounds to achieve any changes like, `'my' + name[2:]` will give 'mytube', etc.
- **len()** method is used to get the length of the string, inbuilt functions

## 5th Video: Lists

Imagine we have many types of values such as numbers and strings, if you want to group them together

- Lists are like arrays in js
- Lists can have different types of data types in them
- Lists are mutable
- Lists can be sliced like strings
- Lists can be concatenated using `+` operator
- Lists can be multiplied using `*` operator
- Lists can be nested
- Lists can be appended using `append` method

example:

```python
nums = [1,2,3,4,5]
print(nums[1], nums[0], nums[0:3])

# we can also have
values = [1.3, 2, 'a name', 'a string']
```

gives `2 1 [1, 2, 3]`

- **NOTE**: the usage of `+` is very different from `,`, `+` is used to concatenate the lists and `,` is used to print the lists as a whole.

    ```python
        names = ['hello', 'world', 'python']
        values = [1,2,3,4,5,6,7,8,9,10]
        mixedValues = [1,2.1, 'hello', 'w']
        listOfList = [names , values , mixedValues , [1, 4, 7]]
        print(listOfList)
        listOfList = [names + values + mixedValues + [1, 4, 7]]
        print(listOfList)

        ## gave me the output
        [['hello', 'world', 'python'], [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [1, 2.1, 'hello', 'w'], [1, 4, 7]]
        [['hello', 'world', 'python', 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2.1, 'hello', 'w', 1, 4, 7]]
    ```

- `names = ['hello', 'world', 'python']` is a list of strings
- `values = [1,2,3,4,5,6,7,8,9,10]` is a list of numbers
- `mixedValues = [1,2.1, 'hello', 'w']` is a list of mixed values
- `listOfList = [names , values , mixedValues , [1, 4, 7]]` is a list of lists
- `listOfList = [names + values + mixedValues + [1, 4, 7]]` is a list of concatenated lists
- List methods often require index values for specific operations:
  - `append` method is used to append a value to the list
  - `insert` method is used to insert a value at a specific index
  - `pop` method is used to remove the last value from the list works like an actual DSA pop, if you provide an index then it will remove the value at that index
  - `extend` method is used to add the list with multiple values, like `names.extend([1,2,3])` will add the values to the list
  - `sort` method is used to sort the list
  - we can use the above using the dot operator
  - `del` method is used to delete a value at a specific index, used like `del names[1]` will delete the value at index 1. We can use the other array styles to delete multiple values at once.
  - `min` method is used to get the minimum value in the list, `max(nums)`
  - `max` method is used to get the maximum value in the list
  - `sum` method is used to get the sum of the values in the list
  - `remove` method is used to remove a value from the list
  - `clear` method is used to clear the list
  - `index` method is used to get the index of a value
  - `count` method is used to get the count of a value
  - `sort` method is used to sort the list
  - `reverse` method is used to reverse the list
  - `copy` method is used to copy the list

## 6th Video: Tuples and Sets

It's almost like lists but the difference is that tuples are immutable, i.e you can't change the values in the tuple. It is written as `()` instead of `[]`. Eg: `nums = (1,2,3,4,5)`

**Tuple** methods:

- `count` method is used to get the no of occurences of a value
- `index` method is used to get the index of a value
When to use tuples, when you have a list and you don't want to change the values of it(there may be usecases like these). Since we don't change values in tuples, so iterations in tuples is faster than lists.

And we don't have the methods like `append`, `insert`, `pop`, `remove`, `clear`, `sort`, `reverse`, `copy` in tuples, because it is immutable

- Iterations in tuples are faster than lists
- Tuples are used when you don't want to change the values in the tuple

**Sets**: It is a collection of unordered values, written as `{}`. Eg: `nums = {1,2,3,4,5}`. Sets never follow a sequence, you may get the same values in a different order. Eg:

```python
s = {25, 14, 98, 63, 75, 98}
print(s)
# of s we get: {98, 25, 75, 14, 63}
```

We got 98 only and there is no ascending or descending order, it is random values. The reason is that sets use hash under the hood and using that we can access the values as fast as possible and as such the values we get are in random order. We can add sequence using the sort method on this. Sets don't have indexing as well since they are unordered.

- Sets are unordered
- Sets don't have duplicate values
- Sets are mutable
- Sets can't be sliced, concatenated, multiplied, nested, appended, inserted, popped, extended, sorted, reversed, or copied
- indexing not supported

## 7th video: Add the stuff here

## 9th video: more variables in python

We can get the address of a variable assigned to a value using the `id()` method. And that is like
