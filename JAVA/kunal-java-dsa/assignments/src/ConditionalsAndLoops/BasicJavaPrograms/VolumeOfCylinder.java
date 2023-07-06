package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class VolumeOfCylinder {

    public static void main(String[] args) {
        System.out.println("deez nuts cylindr");
        Scanner in = new Scanner(System.in);
        System.out.print("Print the radius and height of the cylinder: ");
        int r = 5, h = 8;
        double c = 3.14 * r * r * h;
        System.out.println("The volume of the cylinder is: " + c);

    }
}