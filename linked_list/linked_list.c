/*
 * Set implementation based on linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
	linked_list l;
	initialize(&l);
	
	list_insert(&l, 1);
	list_insert(&l, 2);
	list_insert(&l, 3);
	list_insert(&l, 4);

	list_print(&l);
}

int initialize(linked_list* l)
{
	l->items = NULL;
	l->item_count = 0;

	return 0;
}

list_node* allocate_node()
{
	list_node *n = malloc(sizeof(list_node));
	
	n->data = 0;
	n->next = NULL;

	return n;
}

int list_insert(linked_list* l, int data)
{
	list_node* current_node = l->items;
	list_node* new_node = NULL;

	/* if set is empty, add the first element  */
	if (current_node == NULL)
	{
		current_node = allocate_node();
		current_node->data = data;
		
		l->items = current_node;
		l->item_count = 1;

		return 0;
	}
	
	/* find correct place to add */
	while(current_node->next != NULL)
	{
		/* move to next node */
		current_node = current_node->next;
	}

	/* add new node to last place */
	new_node = allocate_node();
	new_node->data = data;
	new_node->next = NULL;
	current_node->next = new_node;

	l->item_count++;

	return 0;	
}

int list_remove(linked_list* l, int data)
{
	list_node* prev = NULL;
	list_node* current = l->items;

	if(!current)
	{
		/* no items */
		return 0;
	}

	if (current->data == data)
	{
		l->items = current->next;
		l->item_count--;

		free(current);
		return 1;
	}

	prev = current;
	current = current->next;

	while(current)
	{
		if (current->data == data)
		{
			prev->next = current->next;
			free(current);
			
			l->item_count--;

			return 1;
		}
		
		prev = current;
		current = current->next;
	}
	
	return 0;
}

int list_print(linked_list* l)
{
	list_node* ln = l->items;

	while(ln)
	{
		printf("%d", ln->data);
		ln = ln->next;

		if(ln)
		{
			printf(", ");
		}
	}

	printf("\n");

	return 0;
}
