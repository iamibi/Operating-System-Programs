#include <stdio.h>

int main()
{
    int frame, page, i, j, flag = 0, count = 0, temp, pageFault = 0, index;

    printf ("LRU Page Replacement Algorithm\n");
    printf ("Enter the number of frames available: ");
    scanf ("%d", &frame);
    printf ("Enter the number of pages available: ");
    scanf ("%d", &page);
    int free_frame[frame], pages[page], used_frame[frame];

    for (count = 0; count < frame; count++)
        free_frame[count] = -1;

    printf ("Enter the page sizes: ");
    for (i = 0; i < page; i++)
        scanf ("%d", &pages[i]);

    for (count = 0; count < page; count++)
    {
        flag = 0;
        for (j = 0; j < frame; j++)
        {
            if (free_frame[j] == pages[count])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            for (j = 0; j < frame; j++)
                used_frame[j] = 0;
            for (j = 0, temp = count - 1; j < frame; j++, temp--)
            {
                for (i = 0; i < frame; i++)
                {
                    if (free_frame[i] == pages[temp])
                        used_frame[i] = 1;
                }
            }
            for (j = 0; j < frame; j++)
                if (used_frame[j] == 0)
                    index = j;

            free_frame[index] = pages[count];
            printf ("Page Fault: ");
            pageFault++;
        }
        for (i = 0; i < frame; i++)
            printf ("%d\t", free_frame[i]);

        printf ("\n");
    }
    printf ("The Total Page Faults are: %d\n", pageFault);
    return 0;
}
