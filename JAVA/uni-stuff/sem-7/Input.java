import java.util.Scanner;

public class Input {
    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = obj.nextLine();
        System.out.print("Enter your age: ");
        int age = obj.nextInt();

        System.out.println("Your name is " + name + " and your age is " + age);
    }
}
