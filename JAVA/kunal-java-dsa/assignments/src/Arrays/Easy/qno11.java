// 11. [Count Items Matching a Rule](https://leetcode.com/problems/count-items-matching-a-rule/)

package Arrays.Easy;

import java.util.List;

public class qno11 {
    public static void main(String[] args) {
        // Prepare the input as a List of Lists
        List<List<String>> items = List.of(
            List.of("phone", "blue", "pixel"),
            List.of("computer", "silver", "lenovo"),
            List.of("phone", "gold", "iphone")
        );
        System.out.println(func(items, "color", "silver"));
    }

    static int func(List<List<String>> items, String ruleKey, String ruleValue) {
        int index = 0, count = 0;

        // setting indexes for the ruleKey
        if (ruleKey.equals("type")) {
            index = 0;
        } else if (ruleKey.equals("color")) {
            index = 1;
        } else
            index = 2;

        for (int i = 0; i < items.size(); i++) {
            // first get(i) gets the first part of the array, then
            if (items.get(i).get(index).equals(ruleValue))
                count += 1;
        }
        return count;
    }
}