#include <stdio.h>
#include <string.h>

int main()
{
  char str[100];
  printf("Enter a binary string: ");
  scanf("%s", str);

  // Since DFA accepts ALL strings, no need to check transitions
  printf("accepted\n");
  return 0;
}
