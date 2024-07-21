//APPLICATION OF QUEUE ADT – FCFS SCHEDULING
#include <stdio.h>
// #include <conio.h> // Remove this line
// #include <stdlib.h> // Remove this line (not needed in this code)
// #include <stdbool.h> // If needed, include this for bool data type

void main()
{
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    // clrscr(); // Remove this line

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("Enter the arrival times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    g[0] = 0;
    for (i = 0; i < n; i++)
        g[i + 1] = g[i] + b[i];

    for (i = 0; i < n; i++)
    {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt += w[i];
        att += t[i];
    }

    awt = awt / n;
    att = att / n;

    printf("\n\tProcess\t\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("\tP%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }

    printf("\nThe average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);

    // getch(); // Remove this line
    getchar(); // Use getchar() to pause output before exiting
}
