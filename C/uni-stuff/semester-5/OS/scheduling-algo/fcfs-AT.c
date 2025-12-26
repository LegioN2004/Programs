#include<stdio.h>

#define max 30

void main() {
    int i, j, n, bt[max], at[max], wt[max], tat[max], temp[max];
    float awt = 0, atat = 0;

    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the burst time of the process: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter the arrival time of the process: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &at[i]);

    temp[0] = 0;
    printf("process \t burst time\t arrival time\t waiting time\t turn around time");

    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i + 1] = temp[i] + bt[i]; // temp array ka next element = temp's prev value and bt of first proc
        wt[i] = temp[i] - at[i]; // WT 
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("\n%-8s %-11s %-13s %-13s %-15s\n", "Process", "Burst", "Arrival", "Waiting", "TurnAround");
        printf("---------------------------------------------------------------------\n");

        printf("%-8d %-11d %-13d %-13d %-15d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
        }

        awt = awt / n;
        atat = atat / n;
        printf("\nAverage waiting time = %f\n", awt);
        printf("Average turn around time = %f\n", atat);
}