import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Scanner;

public class everything {

    static void pairs(int a) {
        AbstractMap.SimpleEntry<Integer, Integer> pair = new AbstractMap.SimpleEntry<>(1, 2);
        System.out.println(pair.getKey() + " " + pair.getValue());
    }

    static int vectors(int a) {
        
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int a = in.nextInt();
            // pairs(a);
            vectors(a);
        }
    }
}
