// 12. [Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)

package Arrays.Easy;

import java.util.List;

public class qno12 {
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
    }
}