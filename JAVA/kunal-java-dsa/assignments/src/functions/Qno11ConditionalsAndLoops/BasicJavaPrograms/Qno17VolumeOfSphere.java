package ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class VolumeOfSphere {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int r = in.nextInt();
        double b = (4 / 3) * (3.14 * r * r * r);
        System.out.println("The volume of the sphere is: " + b);
    }
}