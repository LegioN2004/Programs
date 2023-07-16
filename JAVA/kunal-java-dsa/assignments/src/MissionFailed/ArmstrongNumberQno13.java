package MissionFailed;

import java.util.Scanner;

public class ArmstrongNumberQno13 {
    public static void main(String[] args) {
        System.out.println("Armstrong number");
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number you want to find the armstrong of: ");
        int a = in.nextInt();
        // while(a != 0){ // use a loop to determine the no of digits in the number
        // entered for now I'll use a System.out.println();
        // a = a % 10;
        // }
        System.out.print("Enter the number of digits present in the number give to find the armstrong of: ");
        int n = in.nextInt();
        int c = 0, d = 0;
        while (a > 0) {
            int rem = a % 10;
            for (int i = 1 ; i <= n ; i++) {
                c = rem * rem * rem;
            }
            a = a / 10;
            d = d + c;
        }
        System.out.println("The calculated no for armstrong is -> " + d);
        if (d == a) {
            System.out.println(
                    "So after the calculation the number " + d + " is equal to " + a + " so the number is armstrong");
        } else {
            System.out.println("The number is not armstrong");
        }
    }
}
