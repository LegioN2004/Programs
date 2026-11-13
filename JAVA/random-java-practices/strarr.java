import java.util.Arrays;

class strarr {
    public static void main(String[] args) {
        String[] strs = {"flower","flow","flight"};
        // return brute(strs);
        optimal(strs);
        return;
    }

    String brute(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";

        int minLength = Integer.MAX_VALUE;
        for (int i = 0; i < strs.length; i++) {
            if (strs[i].length() < minLength)
                minLength = strs[i].length();
        }

        // it checks for wrong char in every iteration of the words for the currentChar, once it finds a char that doesn't match, it returns the substring before that index. which is what 0, j sends.
        for (int j = 0; j < minLength; j++) {

            char currentChar = strs[0].charAt(j); // f, l, o, w

            for (int i = 0; i < strs.length; i++) {
                if (strs[i].charAt(j) != currentChar)
                    return strs[0].substring(0, j);
            }
        }
        return strs[0].substring(0, minLength);
    }


    static void optimal(String[] strs){
       Arrays.sort(strs); 
       System.out.println(Arrays.toString(strs));
    }
}
