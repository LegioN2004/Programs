//NOTE: finding the no of armstrong numbers present between two given numbers
package MissionFailed;

import java.util.Scanner;

public class methodArmstrongHaauuh {
    public static void main(String[] args) {
                Scanner in = new Scanner(System.in);

                System.out.print("Enter the first number: ");
                int start = in.nextInt();

                System.out.print("Enter the second number: ");
                int end = in.nextInt();

                findArmstrongNumbers(start, end);
        }

        static void findArmstrongNumbers(int start, int end) {
            System.out.println("Armstrong numbers between " + start + " and " + end + ":");
            for (int number = start; number <= end; number++) {
                if (isArmstrong(number)) {
                    System.out.println(number);
                }
            }
        }

        static boolean isArmstrong(int number) {
            int originalNumber, remainder, result = 0, n = 0;
            originalNumber = number;

            // Store the number of digits in n
            for (; originalNumber != 0; originalNumber /= 10, ++n) ;

            originalNumber = number;

            // Calculate result as the sum of nth power of each digit
            while (originalNumber != 0) {
                remainder = originalNumber % 10;
                result += Math.pow(remainder, n);
                originalNumber /= 10;
            }

            // If the result is equal to the original number, it's an Armstrong number
            return result == number;
        }
    }