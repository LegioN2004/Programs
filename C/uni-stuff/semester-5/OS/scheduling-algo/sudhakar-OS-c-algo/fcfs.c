#include <stdio.h>

int main()
{
  int n, i, j;
  int at[100], bt[100], wt[100], tat[100], ct[100];
  int sum;
  float totaltat = 0.0f, totalwt = 0.0f;

  printf("enter the total number of processes: ");
  if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
    printf("Invalid number of processes (1-100)\n");
    return 1;
  }

  printf("\nEnter The Process Arrival Time & Burst Time\n");
  for (i = 0; i < n; i++) {
    printf("Enter Arrival time of process[%d]: ", i + 1);
    scanf("%d", &at[i]);
    printf("Enter Burst time of process[%d]: ", i + 1);
    scanf("%d", &bt[i]);
  }

  /* Calculate completion time of processes (FCFS) */
  sum = 0;
  for (j = 0; j < n; j++) {
    if (sum < at[j]) {
      /* CPU idle until this process arrives */
      sum = at[j];
    }
    sum += bt[j];
    ct[j] = sum;
  }

  /* Calculate Turn Around time and Waiting time */
  for (i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    totaltat += tat[i];
    totalwt += wt[i];
  }

  printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
  }

  printf("\nAverage Turnaround Time: %.2f\n", totaltat / n);
  printf("Average Waiting Time: %.2f\n", totalwt / n);

  return 0;
}
