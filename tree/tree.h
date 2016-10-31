
#ifndef __TREE_H__
#define __TREE_H__

typedef struct tree {
	struct tree_node *root;
} tree;


typedef struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
} tree_node;

int initialize(tree*);
tree_node* allocate_tree_node();
int tree_insert(tree*, int);
int tree_remove(tree*, int);
int tree_traverse_ldr(tree_node*);
int tree_traverse_dlr(tree_node*);
int tree_traverse_lrd(tree_node*);


#endif /* __TREE_H__ */
