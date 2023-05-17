package Assignments;

public class reverseAstring {
    public static void main(String[] args) {
        // 1st way using the StringBuffer
        StringBuffer x = new StringBuffer("Hello, How are you");
        System.out.println(x.reverse());

        // 2nd way using the StringBuilder
        StringBuilder y = new StringBuilder("Java coding"); // changed ref var
        System.out.println(y.reverse());

        // 3rd using own logic for the code
        String r1 = "Hello this my own";
        String r2 = ""; // this is to store the reverse order of the value of the r1 string
        int l = r1.length(); // to find the length of the variable
        for (int i = l-1; i>=0; i--) { // always run the for loop reverse to make the string reverse
        r1.charAt(i);
        }
    }
}
