/*
 * First Fit Page Placement Algorithm
 *
 * This program is dynamic implementation of first fit
 *
 * Developed by Ibrahim and Prakhar
*/
#include <iostream>

using std::cin;
using std::cout;

typedef struct frame
{
    int no;                     //Frame number
    int blockSize;              //Frame size
}frame;

typedef struct page
{
    int pro;                    //Page size
    int no;                     //Page number
    int blockno;                //Block number allocated to
}page;

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
    cout << "Pages available\nPage No\tPage Size\n";
    for (i = 0; i < m; i++)
        cout << pr[i].no << "\t\t" << pr[i].pro << "\n";

    for (i = 0; i < m; i++)
        pr[i].blockno = -1;
    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            //Check for the size of page with the available block size
            if (pr[i].pro <= arr[j].blockSize)
            {
                arr[j].blockSize -= pr[i].pro;
                pr[i].blockno = arr[j].no;
                break;
            }
        }
    }
    cout << "Page No\tBlock No\n";
    for (i = 0; i < m; i++)
        cout << "\t" << pr[i].no << "-->\t " << pr[i].blockno << "\n";
    return 0;
}
