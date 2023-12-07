public class strln {

  public static void main(String[] args) {
    String originalString = "Hello, World!";
    StringBuilder reversedString = new StringBuilder();
    System.out.println(originalString.length());
    System.out.println("helloiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii");

    int[] arr = {1 , 2, 3, 4};
    System.out.println(arr[0] + arr[2]);


    for (int i = originalString.length() - 1; i >= 0; i--) {
      reversedString.append(originalString.charAt(i));
    }

    System.out.println("The reversed string is " + reversedString);
  }
}
