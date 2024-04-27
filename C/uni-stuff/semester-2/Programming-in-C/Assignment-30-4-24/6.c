/*
Take the price and quantity of items as an input. Write a C function to
calculate the sum of the prices. Write another C function to calculate the
discount according to the following rules:
    1. For total less than Rs.1000, discount is 5%.
    2. For total greater than Rs.1000 but less than Rs.5000, discount is 10%.
    3. For total greater than Rs.5000, discount is 15%.
*/

#include <stdio.h>

float TotalSum(float prices[], int n) {
  float total = 0;
  for (int i = 0; i < n; i++) {
    total += prices[i];
  }
  return total;
}

float TotalDiscount(float total) {
  float discount = 0;
  if (total < 1000) {
    discount = total * 0.05;
  } else if (total < 5000) {
    discount = total * 0.10;
  } else {
    discount = total * 0.15;
  }
  return discount;
}

int main() {
  int n;
  printf("Enter the number of items: ");
  scanf("%d", &n);

  float price[n];
  printf(
      "Enter the prices of %d items(separated by spaces, then press enter): ",
      n);
  for (int i = 0; i < n; i++) {
    scanf("%f", &price[i]);
  }

  float total = TotalSum(price, n);
  printf("Total price: RS %.2f\n", total);

  float discount = TotalDiscount(total);
  printf("Discount applied: RS %.2f\n", discount);

  float finalPrice = total - discount;
  printf("Final price after discount: RS %.2f\n", finalPrice);

  return 0;
}
