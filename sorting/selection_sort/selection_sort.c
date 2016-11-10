/*
   Selection Sort
*/

#include <stdio.h>

int selection_sort(int* a, int size);
void print_array(int* a, int size);

int main()
{
	int a[10] = {3, 1, 9, 44, 35, 0, 45, 19, 2, 33};
	int steps = 0;	

	printf("Unsorted array:\n");
	print_array(a, 10);

	steps = selection_sort(a, 10);

	printf("\nSelection-sorted array: (used %d steps to sort)\n", steps);
	print_array(a, 10);

	return 0;
}

int selection_sort(int* a, int size)
{
	int i,j;
	int min;
	int tmp;

	int steps = 0;

	for (i=0; i<size-1; i++)
	{
		min = i;
		for (j=i+1; j<size; j++)
		{
			steps++;

			if (a[j] < a[min])
			{
				min = j;
			}
		}

		/* swap the min */
		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}

	return steps;
}

void print_array(int* a, int size)
{
	int i = 0;
	
	for(i=0; i<size; i++)
	{
		printf("%3d ", a[i]);
	}

	printf("\n");
}