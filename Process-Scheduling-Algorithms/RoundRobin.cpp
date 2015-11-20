/*
 *
 * ROUND ROBIN PROCESS SCHEDULING ALGORITHM
 *
 * Developed by Ibrahim
 *
*/

#include <iostream>

using std::cin;
using std::cout;

typedef struct RR
{
    int process;        //Process number
    int burst;          //Burst time
    int arrival;        //Arrival time
    int remaining;      //Remaining time
    int complete;       //Completion time
    int tat;            //Turn around time
    int wt;             //Waiting Time
}RR;

int sort(RR [], int);

int main()
{
    int i, j, k, n, TCT = 0, Time_Quantum, update = 1, x = 0, rear = 0;
    float AvTAT = 0, AvWT = 0;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum for the processes: ";
    cin >> Time_Quantum;
    RR arr[n];          //Array of type struct RR
    int ReadyQue[n];    //Ready Queue

    for (i = 0; i < n; i++)
    {
        arr[i].process = i + 1;
        cout << "Enter the data for process " << arr[i].process << "\n";
        cout << "Burst Time: ";
        cin >> arr[i].burst;
        cout << "Arrival: ";
        cin >> arr[i].arrival;
        arr[i].remaining = arr[i].burst;        //Initially the remaining time is the burst time
        arr[i].complete = 0;                    //Completion time is 0
    }

    //Sort the processes according to the arrival time
    sort(arr, n);
    cout << "PROCESS\t\tARRIVAL\tBURST\n";
    for (i = 0; i < n; i++)
        cout << "P" << arr[i].process << "\t\t" << arr[i].arrival << "\t" << arr[i].burst << "\n";

    rear = 0;
    ReadyQue[rear] = 0;         //Process 0 is in ready queue

    while (update != 0)
    {
        for(j = 0; j < n; j++)
        {
            if(TCT >= arr[j].arrival)
            {
                x = 0;
                for(k = 0; k <= rear; k++)
                    if(ReadyQue[k] == j)
                        x++;
                
                //Insert the process in the ready queue if it isn't there
                if(x == 0)
                {
                    rear++;
                    ReadyQue[rear] = j;
                }
            }
        }
        if(rear == 0)
            i = 0;
        if(arr[i].remaining == 0)
            i++;
        if(i > rear)
            i = (i - 1) % rear;         //Wrap i, so that it is within the range of rear
        if(i <= rear)
        {
            if(arr[i].remaining > 0)
            {
                //if the remaining time of the current process is less than the given time quantum
                //then the process will complete
                if(arr[i].remaining < Time_Quantum)
                {
                    TCT = TCT + arr[i].remaining;
                    arr[i].remaining = 0;
                }
                //else calculate the resulting remaining time and total completion time
                else
                {
                    TCT = TCT + Time_Quantum;
                    arr[i].remaining = arr[i].remaining - Time_Quantum;
                }
                arr[i].complete = TCT;          //Set the completion time of that process
            }
            i++;
        }
        update = 0;
        
        //Are all the process done?
        for(j = 0; j < n; j++)
            if(arr[j].remaining > 0)
                update++;
    }

    //Calculate turn around time and waiting time
    for (i = 0; i < n; i++)
    {
        arr[i].tat = arr[i].complete - arr[i].arrival;
        arr[i].wt = arr[i].tat - arr[i].burst;
    }

    cout << "PROCESS\t\tTAT\tWT\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << arr[i].process << "\t\t" << arr[i].tat << "\t" << arr[i].wt << "\n";
        AvTAT = arr[i].tat + AvTAT;
        AvWT = arr[i].wt + AvWT;
    }

    cout << "Average TAT: " << AvTAT / n << "\nAverage WT: " << AvWT / n << "\n";
    
    return 0;
}

int sort(RR arr[], int n)
{
    int i, j;
    RR temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i].arrival > arr[j].arrival)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    return 0;
}
