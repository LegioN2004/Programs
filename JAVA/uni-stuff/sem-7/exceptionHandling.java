import java.lang.*;

public class exceptionHandling {
    public static void main(String[] args) {
        try{
            int numbers[]  = {1, 2, 3};
            System.out.println(numbers[5]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Arry index is out of bounds: ", e);
        } finally {
            System.out.println("hello finally");
        }
    }
}
