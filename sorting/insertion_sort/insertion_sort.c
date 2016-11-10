/*
   Insertion Sort
*/

#include <stdio.h>

int insertion_sort(int* a, int size);
void print_array(int* a, int size);

int main()
{
	int a[10] = {3, 1, 9, 44, 35, 0, 45, 19, 2, 33};
	int steps = 0;	

	printf("Unsorted array:\n");
	print_array(a, 10);

	steps = insertion_sort(a, 10);

	printf("\nInsertion-sorted array: (used %d steps to sort)\n", steps);
	print_array(a, 10);

	return 0;
}

int insertion_sort(int* a, int size)
{
	int i, j, key;

	int steps = 0;

	for (j=1; j<size; j++)
	{
		key = a[j];
		i = j-1;		
		
		while (i>=0 && a[i]>key)	
		{
			steps++;

			/* move numbers */
			a[i+1] = a[i];
			i--;
		}

		a[i+1] = key;
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