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

	tree_remove(t.root, 6);
	tree_remove(t.root, 1);

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
	n->parent = NULL;

	return n;
}

int tree_insert(tree* t, int data)
{
	tree_node **n = &(t->root);
	tree_node *parent = NULL;

	while(*n)
	{
		parent = *n;

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
	(*n)->parent = parent;

	return 0;
}

int tree_remove(tree_node* root, int key)
{
	tree_node *n = tree_find(root, key);
	tree_node *successor = NULL;

	if (n != NULL)
	{
		if (n->left == NULL) /* one child or leaf */
		{
			n->parent->left = n->right;
			free(n);
		}
		else if (n->right == NULL) /* one child or leaf */
		{
			n->parent->right = n->left;
			free(n);
		}
		else /* two child */
		{
			successor = tree_successor(n);

      		n->data = successor->data;

      		tree_remove(n->right, n->data);
		}
	}

	return 0;
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

tree_node* tree_find(tree_node *root, int key)
{
	while(root != NULL)
	{
		if(root->data == key)
			break;
		else if (root->data > key)
			root = root->left;
		else 
			root = root->right;
	}

	return root;
}

tree_node* tree_successor(tree_node* root)
{
	/* min of right subtree */
	tree_node *n = root->right;

	while(n != NULL && n->left != NULL)
	{
		n = n->left;
	}

	return n;
}

tree_node* tree_predecessor(tree_node* root)
{
	/* max of left subtree */
	tree_node *n = root->left;

	while(n != NULL && n->right != NULL)
	{
		n = n->right;
	}

	return n;
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