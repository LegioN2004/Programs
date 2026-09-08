public class TypeCasting {

    static void WideTypeCasting() {
        System.out.println("------------ Wide type casting --------");
        int x = 7;
        long y = x;
        float z = y;
        System.out.println("before conversion, int value: " + x);
        System.out.println("after long conversion, value: " + y);
        System.out.println("after float conversion, value: " + z);
    }

    static void NarrowTypeCasting() {
        System.out.println("------------ Narrow type casting --------");
        double x = 166.24;
        long y = (long)x;
        int z = (int)y;
        System.out.println("before conversion, int value: " + x);
        System.out.println("after long conversion, value: " + y);
        System.out.println("after int conversion, value: " + z);
    }

    public static void main(String args[]){
        WideTypeCasting();

        System.out.println();

        NarrowTypeCasting();
    }
}