import java.util.Scanner;

/**
 * hello
 */
public class betterGradingProg {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int marks = input.nextInt();
    if (marks < 25) {
      System.out.println("F");
    } else if (marks <= 44) {
      System.out.println("E");
    } else if (marks <= 49) {
      System.out.println("D");
    } else if (marks <= 59) {
      System.out.println("C");
    } else if (marks <= 791) {
      System.out.println("B");
    } else if (marks <= 100) {
      System.out.println("A");
    }
  }
}