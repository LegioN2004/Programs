package functions;

import java.util.Scanner;

public class Qno13 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Give the numebrs between which you want to find all the prime numbers: ");
        int a = in.nextInt();
        int b = in.nextInt();
        prime(a, b);
    }

    static void prime(int a, int b) {
        int flag, i, j;

    // Traverse each number in the interval
    // with the help of for loop
        for (i = a; i <= b; i++) {
            if (i == 1 || i == 0)
 
            // Skip 0 and 1 as they are
            // neither prime nor composite
                continue;

            // flag variable to tell
            // if i is prime or not
            flag = 1;
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    flag = 0;
                    break;
                }
            }
            // flag = 1 means i is prime
            // and flag = 0 means i is not prime
            if (flag == 1)
                System.out.println(i);
        }
    }
}