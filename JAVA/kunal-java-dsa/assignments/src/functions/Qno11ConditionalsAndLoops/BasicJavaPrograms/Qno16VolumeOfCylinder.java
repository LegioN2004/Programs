package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno16VolumeOfCylinder {
    public static void main(String[] args) {
        System.out.println("deez nuts cylindr");
        Scanner in = new Scanner(System.in);
        System.out.print("Print the radius and height of the cylinder: ");
        int r = in.nextInt(), h = in.nextInt();
        System.out.println("The volume of the cylinder is: " + volume(r, h));
    }

    static double volume(int r, int h) {
        double c = Math.PI * r * r * h;
        return c;
    }
}
