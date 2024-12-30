int main(int argc, char *argv[]) {
  for (int i = 1; i <= 10; i++) {
    if (i == 5) {
      continue;  // Skip the current iteration when i is 5
    }
    printf("%d ", i);  // Output: 1 2 3 4 6 7 8 9 10
  }

  return 0;
}
