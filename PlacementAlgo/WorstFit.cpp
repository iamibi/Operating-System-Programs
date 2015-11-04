/*
 * Worst Fit Page Placement Algorithm
 *
 * This program is dynamically created for the worst fit page placement algorithm
 *
 * Developed by Prakhar and Ibrahim
*/
#include <iostream>

using std::cin;
using std::cout;

typedef struct frame
{
    int no;                     //Frame number
    int blockSize;              //Frame Block Size
}frame;

typedef struct page
{
    int pro;                    //Page size
    int no;                     //Page number
    int blockno;                //Block Number the page is allocated to
}page;

int sort (frame [], int);

int main()
{
    int i, j, n, m;
    
    cout << "Enter the total number of free frames: ";
    cin >> n;
    frame arr[n];
    
    for (i = 0; i < n; i++)
    {
        arr[i].no = i + 1;
        cout << "Enter the " << arr[i].no << " block size: ";
        cin >> arr[i].blockSize;
    }
    cout << "Free Frame list\nBlock No\tBlock Size\n";
    for (i = 0; i < n; i++)
        cout << arr[i].no << "\t\t" << arr[i].blockSize << "\n";
        
    cout << "Enter the number of pages: ";
    cin >> m;
    page pr[m];
    
    for (i = 0; i < m; i++)
    {
        pr[i].no = i + 1;
        cout << "Enter the page " << pr[i].no << " size: ";
        cin >> pr[i].pro;
    }
    cout << "Page available\nPage No\tPage Size\n";
    for (i = 0; i < m; i++)
        cout << pr[i].no << "\t\t" << pr[i].pro << "\n";

    for (i = 0; i < m; i++)
        pr[i].blockno = -1;
    
    sort (arr, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            //if the size of the page is less than the current block size
            if (pr[i].pro <= arr[j].blockSize)
            {
                arr[j].blockSize -= pr[i].pro;
                pr[i].blockno = arr[j].no;
                sort (arr, n);
                break;
            }
        }
    }
    cout << "Page No\tBlock No\n";
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
            if (arr[i].blockSize > arr[j].blockSize)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
    return 0;
}
