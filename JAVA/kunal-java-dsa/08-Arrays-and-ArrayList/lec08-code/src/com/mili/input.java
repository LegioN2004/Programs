package com.mili;

import java.util.Arrays;
import java.util.Scanner;

public class input {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // array of primitives
        int[] arr = new int[5];
        // arr[0] = 23;
        // arr[1] = 44;
        // arr[2] = 44;
        // arr[3] = 44;
        // arr[4] = 44;
        // System.out.println(arr[3]);
        // if the array size is like a thousand then we'll have to use something else
        // than the above

        // using for loop
        // input using loops
        // for (int i = 0; i < arr.length; i++) { // starting point is 0 following the
        // index order of an array
        // arr[i] = in.nextInt();
        // System.out.print(arr[i] + " "); // we can also do something like this
        // }
        // for (int i = 0; i < arr.length; i++) { // starting point is 0 following the
        // index order of an array
        // System.out.print(arr[i] + " ");
        // }

        // using foreach loop
        // for (int num : arr) { // for every element(num) in the array(arr), print the
        // element
        // System.out.println(num + " "); // here num represents element of the array
        // }

        // using arrays class
        // System.out.println(Arrays.toString(arr));

        // array of objects
        String[] str = new String[4];
        for (int i = 0; i < str.length; i++) {
            str[i] = in.next();
        }

        // can modify any, we have changed the 3rd index i.e 2's value
        str[2] = "tera helooooooooooooooooooo"; // you are getting the reference variable and directly changing it
        System.out.println(Arrays.toString(str));
    }
}
