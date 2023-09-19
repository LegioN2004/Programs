package functions.Qno11ConditionalsAndLoops.IntermediateJavaPrograms;
import java.util.Scanner;

public class DiscountOfProductQno4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Give the original price of the product -> ");
        int oriPrice = in.nextInt();
        System.out.print("Also give the discount rate of the product -> ");
        int discRate = in.nextInt();
        discount(oriPrice, discRate);
    }

    static void discount(int oriPrice, int discRate) {
        int disAmount = oriPrice * (discRate / 100);
        System.out.println("The discounted amount of the product is -> " + disAmount);
        int finalPrice = oriPrice - disAmount;
        System.out.print("The final price of the product after the discount is -> " + finalPrice);
    }
}
