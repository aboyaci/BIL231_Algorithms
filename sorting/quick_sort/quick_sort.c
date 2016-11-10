/*
   bubble Sort
*/

#include <stdio.h>

int quick_sort(int* a, int low, int high);
int partition(int* a, int low, int high);

void print_array(int* a, int size);

int steps = 0;

int main()
{
	int a[10] = {3, 1, 9, 44, 35, 0, 45, 19, 2, 33};
	int steps = 0;	

	print_array(a, 10);

	steps = quick_sort(a, 0, 9);

	printf("\nQuick-sorted array: (used %d steps to sort)\n", steps);
	print_array(a, 10);

	return 0;
}

int quick_sort(int* a, int low, int high)
{
	int pivot = 0;

	if(low < high)
	{
		pivot = partition(a, low, high);
		quick_sort(a, low, pivot-1);
		quick_sort(a, pivot+1, high);

		steps++;
	}

	return steps;		
}

int partition(int* a, int low, int high)
{
	int pivot = a[high]; /* pivot is always last element */
	int i, j;
	int tmp;

	j = low;

	for (i=low; i<high; i++)
	{
		steps++;
		if (a[i] <= pivot)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			j++;
		}
	}

	/* put pivot to proper position */
	tmp = a[j];
	a[j] = a[high];
	a[high] = tmp; 

	return j;
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