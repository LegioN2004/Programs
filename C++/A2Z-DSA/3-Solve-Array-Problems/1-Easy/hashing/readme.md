# Hashing

It is a technique of converting key value pairs to indices. It allows for faster
searching and inserting.

- eg: if we have an array of index 0 - 9 and it's blank. For searching the values inside it it'll be a huge task.

- But if we use hashing which is kind of a function `f(x) = x % 10` and it gives us indices. So on storing values like 72, 39, 18, 11, if we pass these values to the hashing function, we'll get direct indices such as 2, 9, 8, 1, to store it which makes searching incredibly fast.

- But there appears hash collision which means value like 21 has to be stored at the same place of index 1 just like 11. So in such cases we can use the empty locations that comes after that index. In case of very big array, the chances of collision becomes very less. This keeping of values in further indices than the original required place when collision occurs is known as open addressing.

- Chaining: Another method to handle collisions; let's say we have elements that need the same indices, then we'll create
  a new linkedlist pointing that index of the hashtable where a value of the
  hash function can sit in. so whenever we neeed that element we'll need to just go till the hashvalue and then
  go to the linkedlist to find it.

- our array will be later known as \*hashtable\* since it contains hashes.

- if our hashtable turns out to be small, the elements are again copied in
  another big hashtable such that the older hashtable can be resized again and
  then the elements that didn't fit can be again added in that one.

- Load factor: it is the measure of how full the hashtable is allowed to get
  before it's capacity is automatically increased
