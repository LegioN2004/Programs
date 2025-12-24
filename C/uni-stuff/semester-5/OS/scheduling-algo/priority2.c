#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int n;
    printf("Enter Number of Processes: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    int b[n], p[n], index[n];
    for (int i = 0; i < n; i++) {
        /* Read burst and priority separately to avoid scanf confusion */
        printf("Enter Burst Time for Process %d: ", i + 1);
        while (scanf("%d", &b[i]) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) ;
            printf("Invalid. Enter Burst Time for Process %d: ", i + 1);
        }

        printf("Enter Priority Value for Process %d: ", i + 1);
        while (scanf("%d", &p[i]) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) ;
            printf("Invalid. Enter Priority Value for Process %d: ", i + 1);
        }

        index[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        int a = p[i], m = i;
        for (int j = i; j < n; j++) {
            if (p[j] > a) { a = p[j]; m = j; }
        }
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i], &index[m]);
    }

    int t = 0;
    printf("Order of process Execution is\n");
    for (int i = 0; i < n; i++) {
        printf("P%d is executed from %d to %d\n", index[i], t, t + b[i]);
        t += b[i];
    }

    printf("\nProcess Id     Burst Time   Wait Time    TurnAround Time\n");
    int wait_time = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d          %d          %d          %d\n", index[i], b[i], wait_time, wait_time + b[i]);
        wait_time += b[i];
    }

    return 0;
}
