package ConditionalsAndLoops.BasicJavaPrograms;

public class Qno20TotSurfArOfCube {

    public static void main(String[] args) {
        int a = 2, c = 0;
        System.out.println("The tot surface area of a cube is: " + totSurf(a, c));
    }

    static int totSurf(int a, int c) {
        c = 6 * a * a;
        return c;
    }
}
