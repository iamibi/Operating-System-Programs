/*
 * Best Fit Page Placement Algorithm
 * 
 * This program is for dynamic implementation of Best Fit
 *
 * Developed by Prakhar and Ibrahim
*/
#include <iostream>

using std::cin;
using std::cout;

typedef struct frame
{
    int no;                 //To maintain the number of the block
    int blockSize;          //Block Size available
}frame;

typedef struct page
{
    int pro;                //Process size
    int no;                 //Process number
    int blockno;            //Which block the process gets allocated to
}page;

int sort (placement [], int);

int main()
{
    int i, j, n, m;
    
    cout << "Enter the total number of free frames: ";
    cin >> n;
    frame arr[n];
    
    for (i = 0; i < n; i++)
    {
        arr[i].no = i + 1;
        cout << "Enter the" << arr[i].no << " block size: ";
        cin >> arr[i].blockSize;
    }
    cout << "Free Block list\nBlock No\tBlock Size\n";
    for (i = 0; i < n; i++)
        cout << arr[i].no << "\t\t" << arr[i].blockSize << "\n";
        
    cout << "Enter the number of pages: ";
    cin >> m;
    page pr[m];
    
    //Input the page size
    for (i = 0; i < m; i++)
    {
        pr[i].no = i + 1;
        cout << "Enter the page " << pr[i].no << " size: ";
        cin >> pr[i].pro;
    }
    cout << "Processes available\nProcess No\tProcess Size\n";
    for (i = 0; i < m; i++)
        cout << pr[i].no << "\t\t" << pr[i].pro << "\n";

    for (i = 0; i < m; i++)
        pr[i].blockno = -1;
    
    sort (arr, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            //If the page size is less than the block size
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
        cout << "\t" << pr[i].no << "-->\t " << pr[i].blockno << "\n";
    return 0;
}

int sort (frame arr[], int n)
{
    int i, j;
    frame temp;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (arr[i].blockSize < arr[j].blockSize)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
    return 0;
}
