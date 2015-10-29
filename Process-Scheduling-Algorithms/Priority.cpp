/*
 * Priority Scheduling Algorithm (Non-Preemptive)
 *
 * TCT -> Total Completion Time
 * TAT -> Turn Around Time
 * WT  -> Waiting Time
 *
 * Developed by Prakhar and Ibrahim.
*/
#include <iostream>

using std::cin;
using std::cout;

// This structure holds the basic data of a process
typedef struct pri
{
    int process;
    int burst;
    int arrival;
    int priority;
    int tat;
    int wt;
}pri;   //Data of type pri

int sort (pri [], int);

int main()
{
    int n, i, TCT, count = 0, count_process = 0, minPri, pos, j;
    float AvTAT = 0, AvWT = 0;
    
    cout << "Enter number of processes: ";
    cin >> n;
    pri arr[n];     //Array of type pri
    
    for (i = 0; i < n; i++)
    {
        arr[i].process = i + 1;
        cout << "Enter the burst time for process " << arr[i].process << ": ";
        cin >> arr[i].burst;
        cout << "Enter the arrival time: ";
        cin >> arr[i].arrival;
        cout << "Enter the priority: ";
        cin >> arr[i].priority;
    }
    sort (arr, n);
    arr[0].tat = TCT = arr[0].burst;        //For the first process the TAT is its TCT.
    arr[0].wt = arr[0].tat - arr[0].burst;  //WT is calculated with TAT - Burst
    // As the priority scheduling is non-preemptive, the first process when gets completed
    // set the arrival time to -1, so that when sorted it will reach at the top of the list.
    arr[0].arrival = -1;
    // Sort the structure completely
    sort (arr, n);
    // Increment the process count
    count_process = 1;
    
    // Repeat the process until the all the process have arrived and completed
    while(count_process < n)
    {
        // Minimum priority will be set to 99
        minPri = 99;
        count = 0;
        i = count_process;
        
        // Check how many process have arrived in the given arrival time
        while (TCT >= arr[i].arrival && i < n)
        {
            count++;
            i++;
        }
        
        // Check the priorities of the arrived processes and set the minimum priority to
        // the minimum priority among the arrived processes
        for (j = i - count; count != 0 && j < n; j++, count--)
        {
            if (arr[j].priority < minPri)
            {
                minPri = arr[j].priority;
                pos = j;
            }
        }
        // Calculate the TCT, TAT and WT of the processes and set their arrival to -1
        TCT = TCT + arr[pos].burst;
        arr[pos].tat = TCT - arr[pos].arrival;
        arr[pos].wt = arr[pos].tat - arr[pos].burst;
        arr[pos].arrival = -1;
        sort(arr, n);
        count_process++;
    }
    cout << "Process\tTAT\tWT\n";
    for (i = 0; i < n; i++)
        cout << arr[i].process << "\t" << arr[i].tat << "\t" << arr[i].wt << "\n";
        
    for (i = 0; i < n; i++)
    {
        AvTAT = AvTAT + arr[i].tat;
        AvWT = AvWT + arr[i].wt;
    }
    
    cout << "Average TAT: " << AvTAT/n << " Average WT: " << AvWT/n;
    
    return 0;
}

int sort(pri arr[], int n)
{
    int i, j;
    pri k;
    
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i].arrival > arr[j].arrival)
            {
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
     
     return 0;
}
