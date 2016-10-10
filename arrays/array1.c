/*
 *  Arrays
 */

#include <stdio.h>
#include <string.h>

#define SIZE 10

void print_array(int* a, int size);

int main()
{
	int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; /* initilize array */
	int i = 0;

	memset(a, 0, SIZE*sizeof(int));

	print_array(a, SIZE);

	a[0] = 1;

	for(i=1; i<SIZE; i++)
	{
		a[i] = a[i-1] + 1;
	}

	print_array(a, SIZE);

}

void print_array(int* a, int size)
{
	int i = 0;
	
	for(i=0; i<size; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}
