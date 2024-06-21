# C++ One shot

This video consists of all the basics of programming and the related concepts using the C++ language that you need to know in order to get started with DSA.

> I have noted down the stuff that I thought was something new and is supposed to be known while doing DSA, so this readme will be documented on those stuff.

### Datatypes

- We have got the basic datatypes like `int`, `float`, `double`, `char`, `bool` etc.
- When we want to get the entire line with spaces in the input then we need to use the inbuilt function **`getline(cin, str)`** where `cin` is the way to take input to the `str` variable. This will get the whole line with spaces. Since `cin` stops reading when it encounters a space, we use **`getline`** to get the whole line. But do note that this will not take up the next line, like the **`getline`** stops at the end of the line.
- `char` can store all of the 256 characters in the english dictionary.
  - `string` ends up taking more space then `char` if we want to store single characters specifically and so we use `char` in that case.
- everything takes a fixed amount of space in the memory. So we won't use long long instead of int to store a 2 digit number, since that will take up more space in the memory. Depending on the problem, we need to choose the datatype.
  - The datatype has a range which is not possible to remember, so we can round off the range to the power of 10 and then see which datatype fits in that range. Like say for example, if we have int we can remember it like it goes from `-10^9` to `10^9` and then see if the number fits in that range or not. Likewise long will go for `-10^18` `10^18` and so on.

### Conditionals

- We have the basic if-else statements here, where we have the `if` and `else` conditions but it is not mandatory to have an `else` block.
  - But we can also use `if` and more `ifs` and as such it will also work, but there'll be more memory usage since all the `ifs` will run again and again, This is where `else ifs`. By using `else-if` the code will not run again and again once the `if` condition or the `else-if` satisfies and as such we'll not have more than
