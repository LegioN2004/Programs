package Qno11ConditionalsAndLoops.BasicJavaPrograms;

import java.util.Scanner;

public class Qno17VolumeOfSphere {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int r = in.nextInt();
        System.out.println("The volume of the sphere is: " + volume(r));
    }

    static double volume(int r) {
        double b = (4 / 3) * (3.14 * r * r * r);
        return b;
    }
}
