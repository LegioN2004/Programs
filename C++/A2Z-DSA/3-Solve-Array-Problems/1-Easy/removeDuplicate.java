import java.util.HashSet;
import java.util.Set;

public class removeDuplicate {

    // TC: O(n log(n) + n) SC: O(n) bcz heap
    // if all elements were unique, then it would take n space
    public static int brute(int[] nums) {
        if (nums.length == 0)
            return 0;

        // TC: O(n log n)
        Set<Integer> st = new HashSet<Integer>();
        for (int i = 0; i < nums.length; i++)
            st.add(nums[i]);

        int i = 0;
        // TC: O(n)
        for (Integer in : st) {
            nums[i] = in;
            i++;
        }

        return i;
    }

    // two pointer approach
    public static int optimal(int[] nums) {
        // Edge case: An empty array has 0 unique elements
        if (nums.length == 0)
            return 0;


        /* first element will be unique in itself so it will always be at the first place. Next space will be taken by someone not equivalent bcz its supposed to be unique, so next element will be chosen from the not equivalent ones and put it in the next index place of the first. Then repeat for all the next spaces */

        // 'i' starts at the first element (index 0). It is already unique!
        int i = 0;

        // 'j' starts at index 1 and explores the rest of the array sequentially
        // TC: O(n) SC: O(1) because the iteration is performed on the same
        /* Why it's $O(1)$: The only extra allocations are a couple of primitive integer pointer variables (i and j). Whether the input array contains 3 elements or 3 million elements, the algorithm requires the exact same fixed amount of extra memory slots to run. This makes it an in-place optimization requiring constant space.  */
        for (int j = 1; j < nums.length; j++) {

            // If the explorer finds a value that is DIFFERENT from our last unique value...
            if (nums[j] != nums[i]) {
                i++; // 1. Move our unique boundary forward to the next slot
                nums[i] = nums[j]; // 2. Copy the new unique value into that slot
            }
        }

        // Since 'i' is an index (0-indexed), the total count of unique items is i + 1
        return i + 1;
    }

    public static void main(String[] args) {
        int arr[] = { 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 3 };
        System.out.println(optimal(arr));
    }
}