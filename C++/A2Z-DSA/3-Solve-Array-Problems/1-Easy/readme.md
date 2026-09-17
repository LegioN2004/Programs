## Remove duplicates from sorted array

- Asked in lot of interviews.
- Shouldn't say optimal approach directly, show first
  approach which is the brute.
- Whenever we get this kinda find the unique element
  question, the thing that should come to our mind is `set` DS,

### Here comes the set data structure

In `set` DS, just like cpp, java also doesn't allow repitition of
elements(unlike the List DS, which does allow repitition).

### left rotate the array by one element

```java
    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 5 };
        int temp = arr[0];

        for (int i = 1; i < arr.length; i++) {
            arr[i - 1] = arr[i];
        }
        arr[arr.length - 1] = temp;

        for (int i : arr) {
            System.out.println(i);
        }
    }
```

the above is for one time rotation, we store the first element to replace in the last after the for loop, and a for loop for the array iterations shift all the elements after the 0th index to the left
k = 1 was here.

Whereas for the k = 2 elements, we’ll be storing all the 2 elements in the temp variable and then we’ll rotate and then we’ll take the two elements and put it at the back.