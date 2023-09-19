package functions.Qno11ConditionalsAndLoops.BasicJavaPrograms;// README: extended the prism to the more detailed version (usage remains dependent on the user) by adding the types of prism and their individual calculations if not known by the user

import java.util.Scanner;

public class VolumeOfPrismExtended {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println(
                "Program to find the volume of a prism (please refrain from using float numbers instead use only int type");
        System.out
                .print("Wanna go to the more detailed version of the prism or the boring regular one then press yes/no: ");
        String yesORno = in.next().trim();
        if (yesORno.equals("yes".trim())) {
            System.out.print("Give the type of prism, from rectangle or triangle: ");
            String key = in.next().trim();
            switch (key) {
                case "rectangle" -> {
                    System.out.print(
                            "You entered the type rectangle i.e rectangular prism, so give the area and height of the rectangular prism serially. If the area is not known then press no to calculate it explicitly, else press yes and give the asked values: ");
                    String area = in.next().trim();
                    if (area.equals("yes")) {
                        int a2 = in.nextInt(), b2 = in.nextInt(), d2;
                        d2 = a2 * b2;
                        System.out.println("the volume of the rectangular prism is: " + d2);
                    }
                    if (area.equals("no")) {
                        System.out.print(
                                "So for calculating the area, give the rectangle base, height, serially: ");
                        int a3 = in.nextInt(), b3 = in.nextInt();
                        int ar = a3 * b3;
                        System.out.print(
                                "The area of the rectangle is found: " + ar
                                        + " so now give the value of prism height: ");
                        int c3 = in.nextInt();
                        int vol = ar * c3;
                        System.out.print("The volume of the rectangular prism is: " + vol);
                    }
                }
                case "triangle" -> {
                    System.out.print(
                            "You entered triangle, i.e triangular prism so give the area of the triangle and height serially, if the area is not known then press no to calculate it explicitly, else press yes: ");
                    String area1 = in.next().trim();
                    if (area1.equals("no")) {
                        System.out.print(
                                "So for calculating the area, give the triangle base and height serially: ");
                        int a3 = in.nextInt(), b3 = in.nextInt();
                        float ar = 1 / 2 * (a3 * b3);
                        System.out.println(
                                "The area of the triangle is found: " + ar
                                        + " so now print the value of prism height: ");
                        int c3 = in.nextInt();
                        float vol = ar * c3;
                        System.out.print("The volume of the triangular prism is: " + vol);
                    }
                    if (area1.equals("yes".trim())) {
                        // if (area == "yes") {
                        int a2 = in.nextInt(), b2 = in.nextInt(), d2;
                        d2 = a2 * b2;
                        System.out.println("The volume of the triangular prism is: " + d2);
                    }
                }
                default -> System.out.println("Give the correct output as said above");
            }
        } else if (yesORno.equals("no".trim())) {
            System.out.print(
                    "No reallyyyy! with the boring version, enter the base area and height without calculating (as if you really know that already): ");
            int a = in.nextInt(), h = in.nextInt();
            int vol = a * h;
            System.out.println("The vol of the boring prism is: " + vol + " you boring person");
        } else {
            System.out.println("give some yes or no or get the hell out of here");
        }
    }
}
