
#ifndef __STACK_H__
#define __STACK_H__

#define SIZE 20

typedef struct {
	int data[SIZE];
	int top;
	int max;
} stack;

int initilize(stack* );
int push(stack* s, int i);
int pop(stack* s);
int info(stack* s);


#endif /* __STACK_H__ */
