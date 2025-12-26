#include <stdio.h>

#define max 30

int main() {
  int i, j;       // for using in the for loops
  int n;          // for no of process the user wants to run.
  int bt[max];    // burst time
  int wt[max];    // waiting time
  int tat[max];   // turn around time
  float awt = 0;  // average waiting time
  float atat = 0; // average turn around time

  printf("enter the number of process: ");
  scanf("%d", &n);
  printf("enter the burst time of the process: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &bt[i]);
  }
  printf("process\t burst time\t waiting time\t turn around time\n");
  // loop run karwayenge to check process individually
  for (i = 0; i < n; i++) {
    wt[i] = 0;
    tat[i] = 0;
    // when we get a partciular job, it'll come according to the burst time and
    // execute accordingly. prev job wt + bt
    for (j = 0; j < i; j++)
      wt[i] = wt[i] + bt[j];
    tat[i] = wt[i] + bt[i];
    awt = awt + wt[i]; // numerator part, sum of observations
    atat = atat + tat[i];
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
  }

  // div by no of observations
  awt = awt / n;
  atat = atat / n;
  printf("Average waiting time = %f", awt); // use %s for float type
  printf("\nAverage turn around time = %f", atat);
}
