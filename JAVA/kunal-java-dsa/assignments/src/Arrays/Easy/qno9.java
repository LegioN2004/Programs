// 9. [Create Target Array in the Given Order](https://leetcode.com/problems/create-target-array-in-the-given-order/)

package Arrays.Easy;

import java.util.ArrayList;

public class qno9 {
    public static void main(String[] args) {
        int[] nums = { 0, 1, 2, 3, 4 };
        int[] index = { 0, 1, 2, 2, 1 };
        System.out.println(java.util.Arrays.toString(func(nums, index)));
    }

//    Example 1:
//    Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
//    Output: [0,4,1,3,2]
//    Explanation:
//       nums       index     target
//        0            0        [0]
//        1            1        [0,1]
//        2            2        [0,1,2]
//        3            2        [0,1,3,2]
//        4            1        [0,4,1,3,2]


    static int[] func(int[] nums, int[] index) {
        ArrayList<Integer> list = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            list.add(index[i], nums[i]); // this shifts the already present
        }
        // newly created array for the return variable
        int[] result = new int[list.size()];

        // index for the for loop entry of list to array
        int i = 0;
        for(int x: list){
            result[i++] = x;
        }

        return result;
        }
    }