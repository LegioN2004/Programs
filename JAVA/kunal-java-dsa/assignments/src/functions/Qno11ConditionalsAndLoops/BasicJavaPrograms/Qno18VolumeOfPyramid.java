package Qno11ConditionalsAndLoops.BasicJavaPrograms;

public class Qno18VolumeOfPyramid {

    public static void main(String[] args) {
        System.out.println("The volume of the pyramid is: " + volume());
    }

    static int volume() {
        int a = 1, b = 2, c = 3, d;
        d = (a * b * c) / 3;
        return d;
    }
}
