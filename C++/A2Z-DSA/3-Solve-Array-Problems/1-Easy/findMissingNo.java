public class findMissingNo {
    public static void main(String[] args) {
        int arr[] = { 1, 2, 4, 5 };
        int n = 5;
        // brute(arr, n);
        // better(arr, n);
        // optimalUsingSum(arr, n);
        betterOptimalXor(arr, n);
        bestOptimalXor(arr, n);
    }

    /* explanation to the interviewer
    here in the brute force, the arr mostly find itself when the for loop goes in the first occurence, and it breaks out too. so it doesn't need to go through the whole array so the TC is a hypothetical situation. It never goes till the end in this case.
     */

    // TC; O(n * n)
    // SC; O(1)
    private static void brute(int arr[], int n) {
        int i = 0;
        for (i = 1; i < n; i++) {
            int flag = 0;
            for (int j = 0; j < n - 1; j++) {
                if (arr[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                System.out.println(i);
            }
        }
    }

    // this is done using hashing, we will use a hash array that will keep track of the elements that we have visited by first putting all of the hash array as 0 and then setting them as one once visited
    private static void better(int arr[], int n) {
        int[] hash = new int[n + 1];

        for (int i = 0; i < hash.length; i++) {
            hash[i] = 0;
        }

        // int arr[] = { 1, 2, 4, 5 };
        for (int i = 0; i < arr.length; i++) {
            hash[arr[i]] = 1;
        }

        for (int i = 1; i <= hash.length; i++) {
            if (hash[i] == 0) {
                System.out.println(i);
            }
        }
    }

    /*
    using sum of n natural numbers we can find out the number not present by subtracting the n total length of the array that is supposed to be present  vs the total of the arr elements.
    TC: O(n)
    SC: O(1)
    */
    private static void optimalUsingSum(int[] arr, int n) {
        int sumArr = 0;
        for (int i = 0; i < arr.length; i++)
            sumArr += arr[i];
        int total = (n * (n + 1)) / 2;
        System.out.println(total - sumArr);
    }

    /*
     we'll using the XOR operation property where the same value XOR gives 0.
     2 ^ 2 = 0, 2 ^ 2 ^ 2 ^ 2 = 0, 2 ^ 2 ^ 2 ^ 2 ^ 2 = 0
     */

    // TC: O(2n)
    // SC: O(1)
    private static void betterOptimalXor(int[] arr, int n) {
        int xor1 = 0, xor2 = 0;
        for (int i = 1; i <= n; i++)
            xor1 = xor1 ^ i;
        for (int i = 0; i < n-1; i++) {
            xor2 = xor2 ^ arr[i];
        }
        System.out.println(xor1 ^ xor2);
    }

    /*
    tell the interviewer that you can do better
    for not even using 2 arrays nd instead 1 only
    we can now use the same array for doing both the xor operations. So we can go from i + 1 instead of i and it'll cover 1 to 4, but the remaining 5 needs to XOR'ed as well so we can do that at the last using n.

    Why use XOR instead of the sum of nat nos? Because the xor will never increase from the max no possible i.e 10^5 but sum can go way bigger and that may cause overflow and require long type.
    TC: O(n)
    SC: O(1)
     */
    private static void bestOptimalXor(int[] arr, int n) {
        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < n-1; i++){
            xor1 = xor1 ^ (i + 1);  // using original array numbering
            xor2 = xor2 ^ arr[i]; // using array elements
        }
        xor1 = xor1 ^ n;
        System.out.println(xor1 ^ xor2);
    }
}
