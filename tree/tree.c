/*
 * Binary tree
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
	tree t;
	initialize(&t);

	tree_insert(&t, 6);
	tree_insert(&t, 9);
	tree_insert(&t, 5);
	tree_insert(&t, 7);
	tree_insert(&t, 3);
	tree_insert(&t, 2);
	tree_insert(&t, 1);

	printf("LDR: ");
	tree_traverse_ldr(t.root);

	printf("\nDLR: ");
	tree_traverse_dlr(t.root);

	printf("\nLRD: ");
	tree_traverse_lrd(t.root);

	printf("\n");

	return 0;
}

int initialize(tree* t)
{
	t->root = NULL;

	return 0;
}

tree_node* allocate_node()
{
	tree_node *n = malloc(sizeof(tree_node));
	
	n->data = 0;
	n->left = NULL;
	n->right = NULL;

	return n;
}

int tree_insert(tree* t, int data)
{
	tree_node **n = &(t->root);

	while(*n)
	{
		if ((*n)->data > data)
		{
			n = &((*n)->left);
		}
		else
		{
			n = &((*n)->right);
		}
	}

	*n = allocate_node();
	(*n)->data = data;

	return 0;

}

int tree_remove(tree* t, int data)
{
	tree_node **n = &(t->root);
	tree_node *parent = NULL;
/*
	while(*n)
	{
		if 
	}
*/

}

int tree_traverse_ldr(tree_node* n)
{
	if(n)
	{
		tree_traverse_ldr(n->left);
		printf("%d ", n->data);
		tree_traverse_ldr(n->right);
	}

	return 0;
}

int tree_traverse_dlr(tree_node* n)
{
	if(n)
	{
		printf("%d ", n->data);
		tree_traverse_ldr(n->left);
		tree_traverse_ldr(n->right);
	}

	return 0;
}

int tree_traverse_lrd(tree_node* n)
{
	if(n)
	{
		tree_traverse_ldr(n->left);
		tree_traverse_ldr(n->right);
		printf("%d ", n->data);
	}

	return 0;
}

int tree_successor(tree*, int)
{

}

int tree_predecessor(tree*, int)
{

}
int tree_depth(tree_node* n)
{
	int l,r;

	if (!n)
	{
		return 0;
	}

	l = tree_depth(n->left);
	r = tree_depth(n->right);

	return l>r ? l+1: r+1;
}