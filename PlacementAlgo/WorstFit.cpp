#include <iostream>

using std::cin;
using std::cout;

typedef struct placement
{
    int no;
    int blockSize;
}placement;

typedef struct process
{
    int pro;
    int no;
    int blockno;
}process;

int sort (placement [], int);

int main()
{
    int i, j, n, m;
    
    cout << "Enter the total number of free blocks: ";
    cin >> n;
    placement arr[n];
    
    for (i = 0; i < n; i++)
    {
        arr[i].no = i + 1;
        cout << "Enter the" << arr[i].no << " block size: ";
        cin >> arr[i].blockSize;
    }
    cout << "Free Block list\nBlock No\tBlock Size\n";
    for (i = 0; i < n; i++)
        cout << arr[i].no << "\t\t" << arr[i].blockSize << "\n";
        
    cout << "Enter the number of process: ";
    cin >> m;
    process pr[m];
    
    for (i = 0; i < m; i++)
    {
        pr[i].no = i + 1;
        cout << "Enter the process " << pr[i].no << " size: ";
        cin >> pr[i].pro;
    }
    cout << "Processes available\nProcess No\tProcess Size\n";
    for (i = 0; i < m; i++)
        cout << pr[i].no << "\t\t" << pr[i].pro << "\n";

    for (i = 0; i < m; i++)
    {
        pr[i].blockno = -1;
    }
    
    sort (arr, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (pr[i].pro <= arr[j].blockSize)
            {
                arr[j].blockSize -= pr[i].pro;
                pr[i].blockno = arr[j].no;
                sort (arr, n);
                break;
            }
        }
    }
    cout << "Process No\tBlock No\n";
    for (i = 0; i < m; i++)
    {
        cout << "\t" << pr[i].no << "-->\t " << pr[i].blockno << "\n";
    }
    return 0;
}

int sort (placement arr[], int n)
{
    int i, j;
    placement temp;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (arr[i].blockSize > arr[j].blockSize)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
    return 0;
}
