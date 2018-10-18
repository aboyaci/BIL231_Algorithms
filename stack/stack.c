/*
 * Stack
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
	stack s;
	initilize(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	pop(&s);
	info(&s);
}


int initilize(stack* s)
{
	s->top = 0;
	s->max = SIZE;
	memset(s->data, 0, SIZE*sizeof(int));
}

int push(stack* s, int i)
{
	if(s->top < s->max)
	{
		s->data[s->top++] = i;
		
		return s->top;
	}

	return -1; /* error, no room */
}

int pop(stack* s)
{
	if(s->top > 0)
	{
		return s->data[--(s->top)];
	}
	
}

int info(stack* s)
{
	int i=0;

	printf("Top = %d, Max = %d\n", s->top, s->max);
	
	for(i=0; i < s->top; i++)
	{
		printf("%d ", s->data[i]);	
	}
	
	printf("\n");
}

