/*
   merge Sort
*/

#include <stdio.h>

int merge(int* a, int first, int mid, int last);
int merge_sort(int* a, int first, int last);

void print_array(int* a, int size);

int steps = 0;

int main()
{
	int a[10] = {3, 1, 9, 44, 35, 0, 45, 19, 2, 33};
	int steps = 0;	

	print_array(a, 10);

	steps = merge_sort(a, 0, 9);

	printf("\nMerge-sorted array: (used %d steps to sort)\n", steps);
	print_array(a, 10);

	return 0;
}

int merge(int* a, const int first, const int mid, const int last)
{
	int f1 = first;
	int f2 = mid + 1;
	int l1 = mid;
	int l2 = last;
	int i;

	int step = 0;

	int tmp[10];

	for(i=0; (f1 <= l1) && (f2 <= l2); i++)
	{
		if (a[f1] < a[f2])
		{
			tmp[i] = a[f1++];
		}
		else
		{
			tmp[i] = a[f2++];
		}

		step++;
	}

	for (;f1 <= l1; f1++, i++)
	{
		tmp[i] = a[f1];
		step++;
	}

	for (;f2 <= l2; f2++, i++)
	{
		tmp[i] = a[f2];
		step++;
	}

	for (i=0; i <= last - first; i++)
	{
		a[first + i] = tmp[i];
		step++;
	}

	return step;
}

int merge_sort(int* a, int first, int last)
{
	int mid;
	if(first < last)
	{
		mid = (first + last) / 2;

		merge_sort(a, first, mid);
		merge_sort(a, mid+1, last);

		return merge(a, first, mid, last);
	}

	return 1;
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