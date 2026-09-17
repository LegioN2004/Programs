import java.util.ArrayList;
import java.util.List;

public class intersectionOfSortedArray {

    // TC: O(n1 * n2)
    // SC: O(n)
    static void brute() {
        int nums1[] = { 1, 1, 2, 3, 3, 4, 5 };
        int nums2[] = { 2, 2, 3, 3, 4, 4, 5, 5 };
        boolean visited[] = new boolean[nums2.length]; // by default false set kori diye

        List<Integer> intersection = new ArrayList<>();

        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                if (nums1[i] == nums2[j] && visited[j] == false) {
                    intersection.add(nums1[i]);
                    visited[j] = true;
                    break;
                }
                if (nums2[j] > nums1[i])
                    break;
            }
        }
        System.out.println(intersection);
    }

    static void optimal() {
        int nums1[] = { 1, 1, 2, 3, 3, 4, 5 };
        int nums2[] = { 2, 2, 3, 3, 4, 4, 5, 5 };
        List<Integer> ans = new ArrayList<>();

        int i = 0, j = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                ans.add(nums1[i]);
                i++;
                j++;
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        // brute();
        optimal();
    }
}
