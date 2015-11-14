/*
 *
 *  Program is Incomplete
 *
*/

#include <stdio.h>

typedef struct resource
{
	int no;
}resource;

typedef struct allocation
{
	resource R[3];
}allocation;

typedef struct max
{
	resource R[3];
}max;

typedef struct available
{
	resource R[3];
}available;

typedef struct process
{
	int prc_no;
	allocation AL;
	max MAX;
}process;

available AVL;

int main()
{
	int i, j, p;
	
	printf ("Enter the number of process available: ");
	scanf ("%d", &p);
	process pr[p];
	
	printf ("Enter the Currently AVAILABLE resources\n");
	for (i = 0; i < 3; i++)
	{
		printf ("Enter the value for resource %d: ", i + 1);
		scanf ("%d", &AVL.R[i].no);
	}
	
	for (i = 0; i < p; i++)
		pr[i].prc_no = i + 1;
	printf ("Enter the resource allocation matrix\n");
	for (i = 0; i < p; i++)
		for (j = 0; j < 3; j++)
			scanf ("%d", &pr[i].AL.R[j].no);
	
	printf ("Enter the maximum resource matrix\n");
	for (i = 0; i < p; i++)
		for (j = 0; j < 3; j++)
			scanf ("%d", &pr[i].MAX.R[j].no);
	
	printf ("PROCESS\t\tALLOCATION\n\t\tR1 R2 R3\n");
	for (i = 0; i < p; i++)
	{
		printf ("P%d\t\t", pr[i].prc_no);
		for (j = 0; j < 3; j++)
			printf ("%2d ", pr[i].AL.R[j].no);
		printf ("\n");
	}
	printf ("PROCESS\t\tMAX\n\t\tR1 R2 R3\n");
	for (i = 0; i < p; i++)
	{
		printf ("P%d\t\t", pr[i].prc_no);
		for (j = 0; j < 3; j++)
			printf ("%2d ", pr[i].MAX.R[j].no);
		printf ("\n");
	}

	printf ("Total Available Resource\n");
	for (i = 0; i < 3; i++)
		printf ("%d ", AVL.R[i].no);

	printf ("\n");
	return 0;
}
