package MissionFailed;
import java.util.Scanner;
public class nothing {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);

            System.out.print("Enter the first number: ");
            int num1 = in.nextInt();

            System.out.print("Enter the second number: ");
            int num2 = in.nextInt();

            boolean isNum1Armstrong = isArmstrong(num1);
            boolean isNum2Armstrong = isArmstrong(num2);

            if (isNum1Armstrong && isNum2Armstrong) {
                System.out.println("Both numbers are Armstrong numbers.");
            } else if (isNum1Armstrong) {
                System.out.println("The first number is an Armstrong number.");
            } else if (isNum2Armstrong) {
                System.out.println("The second number is an Armstrong number.");
            } else {
                System.out.println("Neither of the numbers is an Armstrong number.");
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
