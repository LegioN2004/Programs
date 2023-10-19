package com.mili;

import java.util.Arrays;
import java.util.Scanner;

public class MultiDimension {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // mulitidimension arrays can be something like matrix
        /*
         * 2D arrays can be something like matrix
         * lets say create an arrray that is something like the following, 3*3 array
         *
         * 1 2 3
         * 4 5 6
         * 7 8 9
         */

        // int arr[][] arr = new int[3][]; // (hard way) // the part after new and int,
        // the braces will take values as rows and columns in order just like in any
        // matrix formation style

        // int[][] arr2D = new int[4][];
        // int[][] arr2D = { // (easy way) directly adding the values
        // { 1, 2, 3 }, // 0th index
        // { 4, 5, 6 }, // 1st index
        // { 7, 8, 9 }, // 2nd index
        // { 7, 8, 9, 10, 11 } // 3rd index
        // };

        int[][] arr2D = new int[3][3];

        // 2D array input
        for (int row = 0; row < arr2D.length; row++) {
            // for each column in every row the input will be followin
            for (int col = 0; col < arr2D[row].length; col++) { // every array at that row, the length of that array
                arr2D[row][col] = in.nextInt();
            }
        }

        // 2D array output
        for (int row = 0; row < arr2D.length; row++) {
            // for each column in every row the input will be followin
            // for (int col = 0; col < arr2D[row].length; col++) { // every array at that
            // row, the length of that array
            // System.out.print(arr2D[row][col] + " ");
            // }
            // System.out.println("");
            System.out.println(Arrays.toString(arr2D[row])); // to print it like a matrix you need to print it in a new
            // line so you will need to a add a new line
        }

        // or we can use enhanced for loop
        System.out.println("using the enhanced for loop");

        for (int[] a : arr2D) {
            System.out.println(Arrays.toString(a));
        }

    }
}
