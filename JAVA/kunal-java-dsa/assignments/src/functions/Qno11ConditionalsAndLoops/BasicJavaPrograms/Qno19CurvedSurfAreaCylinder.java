package ConditionalsAndLoops.BasicJavaPrograms;

public class Qno19CurvedSurfAreaCylinder {

    public static void main(String[] args) {
        int r = 1, h = 2;
        System.out.println("The curved surface area of the cylinder is: " + surfArea(r, h));
    }

    static double surfArea(int r, int h) {
        double ar = 2 * 3.14 * r * h;
        return ar;
    }
}
