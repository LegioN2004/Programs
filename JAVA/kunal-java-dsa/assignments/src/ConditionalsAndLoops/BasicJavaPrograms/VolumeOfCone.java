package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class VolumeOfCone {
    public static void main(String[] args) {
        System.out.println("Give the radius and height of the cone");
        Scanner in = new Scanner(System.in);
        float r = in.nextInt(), h = in.nextInt();
        double p;
        p = 3.14 * r * r * (h / 3);
        System.out.println("The volume of the cone is " + p);
    }
}
