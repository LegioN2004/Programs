#include <stdio.h>

int main() {
  char str[100];
  char state = 'a'; // Start state
  int i;

  printf("Enter a binary string: ");
  scanf("%s", str);

  for (i = 0; str[i] != '\0'; i++) {
    switch (state) {
    case 'a': // No '1's seen yet
      if (str[i] == '0')
        state = 'a';
      else if (str[i] == '1')
        state = 'b';
      /* else */
      /*   state = 'd'; // invalid input */
      break;

    case 'b': // One '1' seen
      if (str[i] == '0')
        state = 'b';
      else if (str[i] == '1')
        state = 'c';
      /* else */
      /*   state = 'd'; */
      break;

    case 'c': // Two '1's seen (accepting state)
      if (str[i] == '0')
        state = 'c';
      else if (str[i] == '1')
        state = 'd'; // more than 2 '1's → dead state
      /* else */
      /*   state = 'd'; */
      break;

    case 'd': // dead state
      // Once here, remain forever
      state = 'd';
      break;
    }
    printf("after reading '%c', current state = %c\n", str[i], state);
  }

  // Final decision
  if (state == 'c')
    printf("✅ String accepted (exactly two 1s)\n");
  else if (state == 'd')
    printf("❌ String rejected (dead state reached)\n");
  else
    printf("❌ String rejected (less than two 1s)\n");

  return 0;
}
