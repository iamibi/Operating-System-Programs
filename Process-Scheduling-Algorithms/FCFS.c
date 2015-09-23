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

typedef struct fcfs
{
    int process;    //Process Number
    int burst;      //Burst Time
    int arrival;    //Arrival Time
    int tat;        //Turn Around Time
    int wt;         //Waiting Time
}fcfs;

int sort(fcfs [], int);

int main()
{
    int n, i, temp = 0, AvTat = 0, AvWt = 0;

    printf ("Enter the number of processes: ");
    scanf ("%d", &n);
    fcfs arr[n];    //Array of type fcfs
    int tct[n];

    for (i = 0; i < n; i++)
    {
        arr[i].process = i;
        printf ("Enter the process %d data\n", arr[i].process);
        printf ("Enter CPU Burst: ");
        scanf ("%d", &(arr[i].burst));
        printf ("Enter the arrival time: ");
        scanf ("%d", &(arr[i].arrival));
    }
    
    //Sorting the processes according to their arrival time
    sort(arr, n);

    printf ("Process\t\tBurst Time\tArrival Time\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        tct[i] = temp + arr[i].burst;
        temp = tct[i];
        arr[i].tat = tct[i] - arr[i].arrival;
        arr[i].wt = arr[i].tat - arr[i].burst;
        AvTat = AvTat + arr[i].tat;
        AvWt = AvWt + arr[i].wt;
        printf ("%5d\t%15d\t\t%9d\t%12d\t%12d\n", arr[i].process, arr[i].burst, arr[i].arrival, arr[i].tat, arr[i].wt);
    }

    printf ("Average Turn Around Time: %d\nAverage Waiting Time: %d\n", AvTat / n, AvWt / n);
    
    return 0;
}

//Bubble Sort
int sort(fcfs arr[], int n)
{
    int i, j;
    fcfs k;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            //Sorting the processes according to their arrival time
            if (arr[i].arrival > arr[j].arrival)
            {
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
    return 0;
}
