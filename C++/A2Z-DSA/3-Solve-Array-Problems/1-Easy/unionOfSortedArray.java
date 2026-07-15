import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class unionOfSortedArray {

    static void brute() {
        int arr1[] = { 1, 1, 2, 3, 4, 5 };
        int arr2[] = { 2, 2, 3, 4, 4, 5 };

        // TC: O(n1 log n + n2 log n) + O(n1 + n2)
        // SC: O(n1 + n2) + O(n1 + n2)
        Set<Integer> union = new TreeSet<Integer>();
        for (int i = 0; i < arr1.length; i++) { // n1
            union.add(arr1[i]); // log n
        }
        for (int i = 0; i < arr2.length; i++) { // n2
            union.add(arr2[i]); // log n
        }

        System.out.println(union);
    }

    /*
     * Two pointer approach
     *
     */

    static void optimal() {
        List<Integer> nums1 = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        List<Integer> nums2 = Arrays.asList(2, 3, 4, 4, 5, 11, 12);

        List<Integer> unionArray = new ArrayList<>(); // n

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1.get(i) <= nums2.get(j)) {
                if (unionArray.isEmpty() || !unionArray.get(unionArray.size() - 1).equals(nums1.get(i))) {
                     // unionArray  last element  of the current  iteration  matching with  a.get(i) or  not, if not  insert that  element since  that means not  same and if  yes it means  same so just  iterate to  next for first  arr, i.e i++ unionArray.add(a.get(i));
                    unionArray.add(nums1.get(i));
                }
                i++;
            } else {
                if (unionArray.isEmpty() || !unionArray.get(unionArray.size() - 1).equals(nums2.get(j))) {
                    unionArray.add(nums2.get(j));
                }
                j++;
            }
        }

        while (j < nums2.size()) {
            if (unionArray.isEmpty() || !unionArray.get(unionArray.size() - 1).equals(nums2.get(j))) {
                unionArray.add(nums2.get(j));
            }
            j++;
        }

        while (i < nums1.size()) {
            if (unionArray.isEmpty() || !unionArray.get(unionArray.size() - 1).equals(nums1.get(i))) {
                unionArray.add(nums1.get(i));
            }
            i++;
        }

        System.out.println(unionArray);


    }

    public static void main(String[] args) {
        // brute();
        optimal();
    }
}
