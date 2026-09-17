import java.util.HashSet;
import java.util.Set;

public class practice {
    public static void main(String[] args) {

        int arr[] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4 };
        Set<Integer> nums = new HashSet<Integer>();
        for (int i = 0; i < arr.length; i++) {
            nums.add(arr[i]);
        }
        System.out.println(nums);
    }
}
