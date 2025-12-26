#include <stdio.h>

int main()
{
  int n, i, j;
  int bt[30], wt[30], tat[30], temp;
  float awt = 0, atat = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  printf("Enter burst times:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &bt[i]);

  // Sorting burst times (SJF)
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (bt[i] > bt[j])
      {
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;
      }
    }
  }

  wt[0] = 0;
  for (i = 1; i < n; i++)
    wt[i] = wt[i - 1] + bt[i - 1];

  for (i = 0; i < n; i++)
  {
    tat[i] = wt[i] + bt[i];
    awt += wt[i];
    atat += tat[i];
  }

  printf("\nProcess  BT  WT  TAT\n");
  for (i = 0; i < n; i++)
    printf("P%d       %d   %d   %d\n", i + 1, bt[i], wt[i], tat[i]);

  printf("\nAverage Waiting Time = %.2f", awt / n);
  printf("\nAverage Turnaround Time = %.2f\n", atat / n);

  return 0;
}
