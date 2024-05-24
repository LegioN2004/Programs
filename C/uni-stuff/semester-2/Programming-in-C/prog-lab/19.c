#include <stdio.h>

int main() {
  int ans = 0;

  for (int i = 10; i < 100; i++) {
    int temp = i;     // Use a temporary variable to avoid modifying i directly
    int digitSum = 0; // Reset the digit sum for each number
    while (temp > 0) {
      digitSum += temp % 10;
      temp /= 10;
    }
    ans += digitSum; // Add the sum of digits of the current number to ans
  }

  printf("The cumulative sum of the digits from 10 to 99 is: %d\n", ans);
  return 0;
}

