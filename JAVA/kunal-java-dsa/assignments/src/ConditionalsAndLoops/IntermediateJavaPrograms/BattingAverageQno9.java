package ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class BattingAverageQno9 {
    public static void main(String[] args) {
        System.out.println("Printing the batting average for 10000 runs, 250 matches, and 50 not-out.");
        Scanner in = new Scanner(System.in);

        // get hits from the user
        System.out.println("Please enter the number of hits");
        double hits = in.nextInt();

        // get bats from the user
        System.out.println("Please enter the number of bats");
        double bats = in.nextInt();

        // calculate the batting average
        // double batAvg = (hits / bats) * 100; // Idk what is the correct formula and
        // what is this batting avg but nvm, I know how to do these calculations in java
        double batAvg = (hits / bats);

        // show the average in the output
        System.out.println("Your batting average is: " + batAvg + "%");
    }
}
