/*
 *  Arrays
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

void print_array(int* a, int size);
int* allocate_array(int size);
int* resize_array(int* a, int size);

int main()
{
	int i = 0;

	int* a = allocate_array(SIZE);

	for(i=0; i<SIZE; i++)
	{
		a[i] = i;
	}

	print_array(a, SIZE);

	a = resize_array(a, SIZE * 2);

	print_array(a, SIZE * 2);

	return EXIT_SUCCESS;
}

int* allocate_array(int size)
{
	int* a = malloc(size * sizeof(int)); 
	memset(a, 0, SIZE*sizeof(int));

	return a;
}

int* resize_array(int* a, int size)
{
	int* new_a = realloc(a, size);

	return new_a;
}

void print_array(int* a, int size)
{
	int i = 0;

	printf("Array starts at %p\n", a);
	
	for(i=0; i<size; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}
