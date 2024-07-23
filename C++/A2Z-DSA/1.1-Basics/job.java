import java.util.Scanner;

/**
 * job
 */
public class job {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int age = in.nextInt();
        if (age < 18) {
            System.out.println("not eligible for job");
        } else if (age <= 54) {
            System.out.println(" eligible for job");
        } else if (age <= 57) {
            System.out.println("not eligible for job, retire soon");
        } else {
            System.out.println("retireddddddd");
        }
    }
}