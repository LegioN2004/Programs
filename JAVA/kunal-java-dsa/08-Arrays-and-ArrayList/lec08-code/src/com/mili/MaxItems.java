package com.mili;

import java.util.Arrays;

// Q. Find the maximum item in the list?
public class MaxItems {
    public static void main(String[] args) {
        int[] arr = { 1, 3, 33, 9, 18 };
        System.out.println(max(arr));
        System.out.println(maxRange(arr, 3, 4));
    }

    // lets assume the first index value is the maximum one
    // imagine that the array 'arr' is not empty

    // TODO: also work on edge cases here like array being null(learn about edge cases)
    static int max(int[] arr){

        if (arr.length == 0){
            return -1;
        }

        int maxVal = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if(arr[i] > maxVal){
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    // Q. Find the maximum item in the range?
    static int maxRange(int[] arr, int start, int end){

        if (end > start){
            return -1;
        }

        if (arr == null) {
            return -1;
        }

        int maxVal = arr[start];
        for (int i = start; i <= end; i++) {
            if(arr[i] > maxVal){
                maxVal = arr[i];
            }
        }
        return maxVal;
    }
}
