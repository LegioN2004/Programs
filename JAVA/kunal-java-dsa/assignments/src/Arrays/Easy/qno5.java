package Arrays.Easy;

import java.util.Arrays;

// Input: nums = [2,5,1,3,4,7], n = 3
// Output: [2,3,5,4,1,7]
// Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

public class qno5 {
	public static void main(String[] args) {
		int[] nums = {2, 5, 1, 3, 4, 7};
		int n = 3;
		System.out.println(Arrays.toString(nums));
		System.out.println(Arrays.toString(hello(nums, n)));
	}
	static int[] hello(int[] nums, int n) {
		int[] a = new int[nums.length];
		int x = n - 1;
		for (int i = 0; i < n; i++) {
			a[2*i] = nums[i];
			a[2*i + 1] = nums[2*i + 1 + x];
			x--;
		}
		return a;
	}
}

