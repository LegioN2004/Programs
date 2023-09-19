package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno14VolumeOfCone {
    public static void main(String[] args) {
        System.out.println("Give the radius and height of the cone");
        Scanner in = new Scanner(System.in);
        float r = in.nextInt(), h = in.nextInt();
        System.out.println("The volume of the cone is " + volume(r, h));
    }

    static double volume(float r, float h) {
        double p = 3.14 * r * r * (h / 3);
        return p;
    }
}
