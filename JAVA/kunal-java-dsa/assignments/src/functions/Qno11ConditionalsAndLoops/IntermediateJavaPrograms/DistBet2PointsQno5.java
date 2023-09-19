package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;

import java.util.Scanner;

public class DistBet2PointsQno5 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Print the x and y coordinates of the two points");
    System.out.print("Print the value of x1 -> ");
    double x1 = in.nextDouble();
    System.out.print("Print the value of x2 -> ");
    double x2 = in.nextDouble();
    System.out.print("Print the value of y1 -> ");
    double y1 = in.nextDouble();
    System.out.print("Print the value of y2 -> ");
    double y2 = in.nextDouble();
    System.out.print("The dist between the two points is: " + dist(x1, x2, y1, y2));
  }

  static double dist(double x1, double x2, double y1, double y2) {
    double a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    double b = Math.sqrt(a);
    return b;
  }
}
