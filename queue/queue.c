/*
 * queue
 */

#include <stdio.h>
#include <string.h>
#include "queue.h"

int main()
{
	queue q;
	initilize(&q);
	insert(&q, 1);
	insert(&q, 2);
	insert(&q, 3);
	get(&q);
	info(&q);

	return 0;
}


int initilize(queue* q)
{
	q->front = 0;
	q->rear = 0;
	q->size = SIZE;
	q->count = 0;
	memset(q->data, 0, SIZE*sizeof(int));

	return 0;
}

int insert(queue* q, int i)
{
	if(!is_full(q))
	{
		q->data[q->front++] = i;

		if (q->front >= q->size)
		{
			q->front = 0; /* circular */
		}
		
		q->count++;

		return 0;
	}

	return -1; /* error, no room */
}

int get(queue* q)
{
	int item = 0;

	if(!is_empty(q))
	{
		item = q->data[q->rear++];

		if (q->rear >= q->size)
		{
			q->rear = 0; /* circular */
		}
		q->count--;

		return item;
	}

	return -1; /* error, no elements to remove */
}

int info(queue* q)
{
	int i=0;

	printf("Front = %d, Rear = %d, Count = %d\n", q->front, q->rear, q->count);
	
	for(i=0; i < q->size; i++)
	{
		printf("%4d", q->data[i]);	
	}
	
	printf("\n");

	for(i=0; i < q->size; i++)
	{
		if (i == q->front)
		{
			printf("  F^");	
		}
		else if(i == q->rear)
		{
			printf("  R^");
		}
		else
		{
			printf("    ");
		}	
	}
	printf("\n");

	return 0;
}

int is_full(queue* q)
{
	return (q->rear == q->front) && q->count > 0;
}
int is_empty(queue* q)
{
	return (q->rear == q->front) && q->count == 0;
}
