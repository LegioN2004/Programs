package Arrays.Easy;

import java.util.ArrayList;
import java.util.List;

public class qno6 {
	public static void main(String[] args) {
		int[] candies = { 2, 3, 5, 1, 3 };
		int extraCandies = 3;
		System.out.println(func(candies, extraCandies));
	}

	static List<Boolean> func(int[] candies, int extraCandies) {
		int b = 0;
		int i = 0;
		List<Boolean> d = new ArrayList<>(candies.length);
		if (candies[i] > b) {
			b = candies[i];
		}
		for (int j = 0; j < candies.length; j++) {
			if (candies[i] + extraCandies >= b) {
				d.add(true);
			} else {
				d.add(false);
			}
		}
		return d;
	}
}
