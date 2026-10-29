public class max_Subarray_Sum {

    static int brute(int nums[]) {
        int sum = Integer.MIN_VALUE;
        int value = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                for (int k = i; k <= j; k++) {
                    value += nums[k];
                }
                sum = Math.max(value, sum);
                value = 0;
            }
        }
        return sum;
    }

    static int better(int nums[]) {
        int sum = Integer.MIN_VALUE; // NOTE: take this as min value otherwise if arr consists of all negative
                                     // numbers, the if check won't work.
        int value = 0;
        for (int i = 0; i < nums.length; i++) {

            for (int j = i; j < nums.length; j++) {
                value += nums[j];
                if (sum < value)
                    sum = value;
            }

            value = 0;
        }
        return sum;
    }


    // there might be a follow up question asking to print out the max subarray and for that we need to slightly change it. We know that we are starting always from the sum as 0

    static long optimal(int nums[]) {
        long max = Long.MIN_VALUE; // NOTE: take this as min value otherwise if arr consists of all negative numbers, the if check won't work.
        long sum = 0;
        int ansStart = 0, ansEnd = 0, start = 0; //* follow up part

        for (int i = 0; i < nums.length; i++) {

            if (sum == 0) start = i; // *follow up part
            sum += nums[i];

            if (sum > max){
                max = sum;
                ansStart = start; // *follow up
                ansEnd = i; // follow up
            }
            // else if (max < 0)
            //     return 0;

            if (sum < 0) {
                sum = 0;
            }
        }

        System.out.println("Array start: " + ansStart);
        System.out.println("Array end: " + ansEnd);

        if (max < 0)
            return 0;
        return sum;
    }

    public static void main(String[] args) {
        int[] nums = { -2, -3, 4, -1, -2, 1, 5, -3 };

        System.out.println("brute: " + brute(nums));
        System.out.println("better: " + better(nums));
        System.out.println("optimal: " + optimal(nums));
    }
}
