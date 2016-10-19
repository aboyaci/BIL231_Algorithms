/*
 * Set implementation based on linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main()
{
	set s;
	set s2;
	set *s3, *s4;

	initialize(&s);
	initialize(&s2);

	set_insert(&s, 11);
	set_insert(&s, 1);
	set_insert(&s, 0);
	set_insert(&s, 2);
	set_insert(&s, 9);
	set_insert(&s, 21);
	set_insert(&s2, 3);
	set_insert(&s2, 2);
	
	printf("Set1: ");
	set_print(&s);

	printf("Set2: ");
	set_print(&s2);

	s3 = set_union(&s, &s2);
	printf("Set3 Union Set1 and Set2: ");
	set_print(s3);

	set_remove(s3, 21);
	printf("Removed 21 from Set3: ");
	set_print(s3);

	set_except(s3, &s2);
	printf("Set3 except Set2: ");	
	set_print(s3);

	s4 = set_intersect(&s, &s2);
	printf("Set4 Set1 intersect Set2: ");	
	set_print(s4);
}

/*
inialize set
*/
int initialize(set* s)
{
	s->items = NULL;
	s->item_count = 0;

	return 0;
}

/*
 allocate o node for set
*/
set_node* allocate_node()
{
	set_node* sn = malloc(sizeof(set));
	
	sn->data = 0;
	sn->next = NULL;
	
	return sn;
}

/*
 insert an item to the set
*/
int set_insert(set* s, int data)
{
	set_node* current_node = s->items;
	set_node* next_node = NULL;
	set_node* new_node = NULL;

	/* if set is empty, add the first element  */
	if (current_node == NULL)
	{
		current_node = allocate_node();
		current_node->data = data;
		
		s->items = current_node;
		s->item_count = 1;

		return 1;
	}

	next_node = current_node->next;

	/* add to top if necessary */
	if (current_node->data > data)
	{
		new_node = allocate_node();
		new_node->data = data;
		new_node->next = current_node;
		
		s->items = new_node;		
		
		s->item_count++;

		return 1;
	}
	else if (current_node->data == data)
	{
		/* already exist ignore */
		return 0;
	}
	
	/* find correct place to add */
	while(next_node != NULL)
	{
		/* alredy exist, ignore */
		if(current_node->data == data || next_node->data == data)
		{
			/* already exist ignore */
			return 0;		
		}
		
		if (next_node->data > data)
		{
			/* found the right place */
			break;
		}
		
		/* move to next node */
		current_node = next_node;
		next_node = current_node->next;
	}

	/* add new node to proper place */
	new_node = allocate_node();
	new_node->data = data;
	new_node->next = current_node->next;
	current_node->next = new_node;

	s->item_count++;

	return 0;
}

/*
 remove an item from set
*/
int set_remove(set* s, int data)
{
	set_node* prev = NULL;
	set_node* current = s->items;

	if(!current)
	{
		/* no items */
		return 0;
	}

	if (current->data == data)
	{
		s->items = current->next;
		s->item_count--;

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
			
			s->item_count--;

			return 1;
		}
		
		prev = current;
		current = current->next;
	}
	
	return 0;
}

/*
 Set union
*/
set* set_union(set* a, set* b)
{
	set_node *sn = NULL;
	set *s = malloc(sizeof(set));
	initialize(s);

	sn = a->items;

	while(sn)
	{
		set_insert(s, sn->data);
		sn = sn->next;
	}

	sn = b->items;

	while(sn)
	{
		set_insert(s, sn->data);
		sn = sn->next;
	}

	return s;
}

/*
 Set intersection
*/
set* set_intersect(set* a, set* b)
{
	set* new_set = malloc(sizeof(set));
	set_node *sn1 = a->items;
	set_node *sn2 = b->items;
	
	initialize(new_set);

	while(sn1 && sn2)
	{
		if(sn1->data > sn2->data)
		{
			sn2 = sn2->next;
		}
		else if (sn1->data < sn2->data)
		{
			sn1 = sn1->next;
		}
		else
		{
			set_insert(new_set, sn1->data);
			sn2 = sn2->next;
			sn1 = sn1->next;
		}
	}
	
	return new_set;
}

/*
 Set difference
*/
set* set_except(set* a, set* b)
{
	set_node *sn = b->items;

	while(sn)
	{
		set_remove(a, sn->data);
		sn = sn->next;
	}

	return a;
}

/*
 Print set
*/
int set_print(set* s)
{
	set_node* sn = s->items;

	printf("{");	

	while(sn)
	{
		printf("%d", sn->data);
		sn = sn->next;

		if(sn)
		{
			printf(", ");
		}
	}

	printf("}\n");

	return 0;
}

