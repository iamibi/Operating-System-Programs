/*
 *
 * First Come First Serve (FCFS) process scheduling algorithm.
 *
 * About:
 * 
 * FCFS is a non-preemptive scheduling algorithm and follows the concept of FIFO (First In First Out).
 * Here the CPU is assigned to the processor in the order the processes appear and request.
 *
 * Waiting Time = Start Time - Arrival Time
 * Turn Around Time = Burst Time + Waiting Time = Finish Time - Arrival Time
*/

#include <stdio.h>

int main()
{
    int n, i, temp = 0, AvTat = 0, AvWt = 0;

    printf ("Enter the number of processes: ");
    scanf ("%d", &n);
    int cpu_burst[n], tat[n], wt[n], process[n], tct[n], arrival[n];

    for (i = 1; i <= n; i++)
    {
        process[i] = i;
        printf ("Enter the cpu burst of %d process: ", process[i]);
        scanf ("%d", &cpu_burst[i]);
        printf ("Enter the arrival time of the %d process: ", process[i]);
        scanf ("%d", &arrival[i]);
        tct[i] = temp + cpu_burst[i];
        temp = tct[i];
        tat[i] = tct[i] - arrival[i];
        AvTat = tat[i] + AvTat;
        wt[i] = tat[i] - cpu_burst[i];
        AvWt = wt[i] + AvWt;
    }

    printf ("Process\t\tBurst Time\tArrival Time\tTurn Around Time\tWaiting Time\n");
    for (i = 1; i <= n; i++)
        printf ("%5d\t%15d\t\t%9d\t%12d\t%12d\n", process[i], cpu_burst[i], arrival[i], tat[i], wt[i]);

    printf ("Average Turn Around Time: %d\nAverage Waiting Time: %d\n", AvTat / n, AvWt / n);

    return 0;
}
