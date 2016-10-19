
#ifndef __HASH_MAP_H__
#define __HASH_MAP_H__

/* size should be a prime number */
#define SIZE 23

typedef struct map_node
{
	char *key;
	void* data;
	struct map_node *next;
} map_node;

typedef struct hash_map
{
	map_node* items[SIZE];
	int item_count;
	int size;
} hash_map;

int initialize(hash_map*);
map_node* allocate_node();
int map_put(hash_map*, char*, void*);
int hash_key(char*);
void* map_get(hash_map*, char*);
int map_print(hash_map*);


#endif /* __HASH_MAP_H__ */
