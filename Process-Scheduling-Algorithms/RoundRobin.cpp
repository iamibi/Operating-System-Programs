/*


Program is incomplete.



*/
#include <iostream>

using std::cin;
using std::cout;

typedef struct RR
{
    int process;
    int burst;
    int arrival;
    int remaining;
}RR;

void partition(RR [], int, int);
void merge(RR [], int, int, int);

int main()
{
    int n, i, TCT, AvTAT = 0, AvWT = 0, Time_Quantum, count_process = 0;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum for the processes: ";
    cin >> Time_Quantum;
    RR arr[n];

    for (i = 0; i < n; i++)
    {
        arr[i].process = i + 1;
        cout << "Enter the data for process " << arr[i].process << "\n";
        cout << "Burst Time: ";
        cin >> arr[i].burst;
        cout << "Arrival: ";
        cin >> arr[i].arrival;
        arr[i].remaining = arr[i].burst;
    }

    partition (arr, 0, n - 1);
    i = 0;
    
    //TODO here
    while (count_process < n)
    {
        TCT = arr[i].remaining = arr[i].burst - Time_Quantum;
    }
}

void partition(RR arr[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void merge(RR arr[], int low, int mid, int high)
{
    int i, m, k, l;
    RR temp[n];

    i = l = low;
    m = mid + 1;

    while (l <= mid && m <= high)
    {
        if (arr[l].arrival <= arr[m].arrival)
            temp[i] = arr[m];
        else
            temp[i] = arr[m];
        m++;
        i++;
    }

    if (l > mid)
        for (k = m; k <= high; k++)
        {
            temp[i] = arr[k];
            i++;
        }

    else
        for (k = l; k <= mid; k++)
        {
            temp[i] = arr[k];
            i++;
        }

    for (k = low; k <= high; k++)
        arr[k] = temp[k];
}
