/*
	Big O examples
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE 10000
#define SIZE_1	10
#define SIZE_2	100
#define SIZE_3	10000
#define EXECUTION_COUNT	100000

int get_item(int* a, int i);
float elapsed_time(struct timeval t0, struct timeval t1);
int run_and_measure(int* a, int size);

int main()
{
	int i = 0;
	int *a = NULL;

	a = malloc(ARRAY_SIZE * sizeof(int));
	
	for (i=0; i<10000; i++)
	{
		a[i] = i;	
	}

	run_and_measure(a, SIZE_1);
	run_and_measure(a, SIZE_2);
	run_and_measure(a, SIZE_3);
	
	free(a);

	return EXIT_SUCCESS;
}

int run_and_measure(int* a, int size)
{
	struct timeval t0;
	struct timeval t1;
	int i = 0;

	gettimeofday(&t0, 0);

	for (i=0; i<EXECUTION_COUNT; i++)
	{
		get_item(a, size/2);
	}
	
	gettimeofday(&t1, 0);

	printf("array with %d items execution time : %f milliseconds.\n", size, elapsed_time(t0, t1));

	return 0;
}

/*
   O(1)
   Get item reads an item from given array at index i
   This is not a usefull code, however it is independent from input
*/
int get_item(int* a, int i)
{
	return a[i];
}

float elapsed_time(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

