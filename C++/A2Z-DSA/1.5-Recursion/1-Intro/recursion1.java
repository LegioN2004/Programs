public class recursion1 {
    static void infiniteFunction() {
        System.out.println("1");
        infiniteFunction();
    }

    static void finiteFunction(int a) {
        if (a == 4) return;
        System.out.println(a);
        a++;
        finiteFunction(a);
    }

    public static void main(String[] args) {
        // infiniteFunction();
        int a = 1;
        finiteFunction(a);
    }
}
