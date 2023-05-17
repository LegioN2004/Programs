public class strln {

    public static void main(String[] args) {
        String originalString = "Hello, World!";
        StringBuilder reversedString = new StringBuilder();
        System.out.println(originalString.length());
        System.out.println("helloiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii");

        for (int i = originalString.length() - 1; i >= 0; i--) {
            reversedString.append(originalString.charAt(i));
        }

        System.out.println("The reversed string is " + reversedString);
    }
}