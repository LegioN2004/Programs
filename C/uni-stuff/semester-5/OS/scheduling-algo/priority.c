#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[30], pr[30], wt[30], tat[30];
    int temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter priorities (lower number = higher priority):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pr[i]);

    // Sort by priority
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

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

    printf("\nProcess  BT  Priority  WT  TAT\n");
    for (i = 0; i < n; i++)
        printf("P%d       %d     %d       %d   %d\n",
               i + 1, bt[i], pr[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);

    return 0;
}
