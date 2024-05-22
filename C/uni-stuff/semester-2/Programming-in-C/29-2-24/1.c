// w.a.p to find the exam result

#include <stdio.h>

int main()
{
  float a;
  printf("Enter the percentage: ");
  scanf("%f", &a);
  if (a >= 0 && a <= 35)
  {
    printf("failed boiiiiiiiiiii");
  }
  else if (a >= 35 && a <= 40)
  {
    printf("thik hai");
  }
  else if (a >= 40 && a <= 70)
  {
    printf("mast hai");
  }
  else if (a >= 70 && a <= 80)
  {
    printf("aur accha kar sakta tha :)");
  }
  else if (a >= 80 && a <= 100)
  {
    printf("phaaaaaaaaaaaaaaaad diaaaaaa behhhhhhh");
  }
  else
  {
    printf("Input thikse de yaarr, kyahi kar rha hai murkh");
  }
  return 0;
}
