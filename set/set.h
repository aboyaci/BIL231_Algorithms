
#ifndef __SET_H__
#define __SET_H__

#define SIZE 20

typedef struct set_node{
	int data;
	struct set_node *next;
} set_node;

typedef struct set
{
	struct set_node* items;
	int item_count;
} set;

int initialize(set*);
set_node* allocate_node();
int set_insert(set*, int);
int set_remove(set*, int);
set* set_union(set*, set*);
set* set_intersect(set*, set*);
set* set_except(set*, set*); 
int set_print(set* s);


#endif /* __SET_H__ */
