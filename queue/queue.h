
#ifndef __QUEUE_H__
#define __QUEUE_H__

#define SIZE 20

typedef struct {
	int data[SIZE];
	int front;
	int rear;
	int size;
	int count;
} queue;

int initilize(queue* q);
int insert(queue* q, int i);
int get(queue* q);
int info(queue* q);
int is_full(queue* q);
int is_empty(queue* q);

#endif /* __QUEUE_H__ */
