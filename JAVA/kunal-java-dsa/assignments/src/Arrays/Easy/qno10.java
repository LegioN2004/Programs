// 10. [Check if the Sentence Is Pangram](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)

package Arrays.Easy;

public class qno10 {
    public static void main(String[] args) {
        System.out.println(func("anmt"));
    }

    // abaoinrstionat
    // pangram check koribo lage, make a bool array
    static boolean func(String sentence) {
        sentence = sentence.toLowerCase();
        boolean[] bool = new boolean[26];
        // int count;

        for (char c : sentence.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                bool[c - 'a'] = true;
            } else {
                break;
            }
        }

        for (boolean b : bool) {
            if (!b) {
                return false;
            }
        }
        return true;
    }
}
