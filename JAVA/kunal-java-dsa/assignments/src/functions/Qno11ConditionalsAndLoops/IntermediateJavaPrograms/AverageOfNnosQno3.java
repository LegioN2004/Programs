package Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class AverageOfNnosQno3 {
 public static void main(String[] args) {
  Scanner in = new Scanner(System.in);
  // done by directly providing the no of numbers in the input then providing the
  // numbers
  System.out.print("Print the no of numbers you want the average of: ");
  double n = in.nextInt();
  average(n);
 }

 static void average(double n) {
  Scanner in = new Scanner(System.in);
  double b = 0, i = 0;
  System.out.println("Input the numbers one by one");
  for (i = 0; i < n; i++) {
   double N = in.nextDouble();
   b = b + N;
  }
  System.out.println("The avg is: " + (b / i));
 }
}
