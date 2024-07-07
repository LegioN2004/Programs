public class first {
    public static void main(String[] args) {
        System.out.println("helloooooooo");

        int arr[] = new int[5];
        arr[1] = 0;
        System.out.println(arr[1]);

        String s = "1234";
        int x = Integer.parseInt(s);
        System.out.println(x);

        int q = 10;
        float y = q; // implicit typecasting
        float z = (float) q; // explicit typecasting
        System.out.println("q = " + q + " y = " + y + " z = " + z);
        // arr[ 10]= 5;

        // short first = 1;
        // short sec = (short) first + 1;
        // System.out.println(sec);

        String s1 = "hello";
        String s2 = "heeee";
        String s3 = "hello";
        if (s1 == s2) {
            System.out.println("s1, s2, equality true");
        } else if (s1 == s3) {
            System.out.println("s1, s3 equality true");
        } else if (s1.equals(s2)) {
            System.out.println("s1, s2, .equals true");
        } else if (s1.equals(s3)) {
            System.out.println("s1, s3, .equals true");
        }
    }
}
