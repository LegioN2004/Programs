// Question: write a Java program to find the second .largest element in an integer array.

import java.util.Arrays;

public class exam {
    public static void main(String[] args) {
        int arr[] = {1, 5, 2, 9, 3};
        Arrays.sort(arr);
        int sec = arr[arr.length - 2];
        System.out.println("Second largest element is: " + sec);
    }
}
