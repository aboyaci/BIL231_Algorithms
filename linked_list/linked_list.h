
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define SIZE 20

typedef struct node{
	int data;
	struct node *next;
} list_node;

typedef struct linked_list{
	struct node *items;
	int item_count;
} linked_list;


int initialize(linked_list*);
list_node* allocate_list_node();
int list_insert(linked_list*, int);
int list_remove(linked_list*, int);
int list_print(linked_list* s);


#endif /* __LINKED_LIST_H__ */
