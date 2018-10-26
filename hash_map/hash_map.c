/*
 * Hash map implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"

int main()
{
	char *s;	
	hash_map m;
	char data1[] = "data1";
	char data2[] = "data2";
	char data3[] = "data3";

	initialize(&m);

	map_put(&m, "test key1", data1);
	map_put(&m, "test key2", data2);
	map_put(&m, "test key3", data3);
	map_put(&m, "test key3", data1); /* overwrite the previous value */
	
	s = map_get(&m, "not existing key");

	if (s)
	{
		printf("%s\n", s);
	}
	else
	{
		printf("key '%s' does not exist!\n", "not existing key");
	}

	s = map_get(&m, "test key1");
	printf("%s\n", s);

	map_print(&m);
	
	return 0;
}

int initialize(hash_map* m)
{
	memset(m->items, 0, sizeof(map_node*) * SIZE);
	m->size = SIZE;
	m->item_count = 0;

	return 0;
}


map_node* allocate_node()
{
	map_node *n = malloc(sizeof(map_node));
	
	n->key = NULL;
	n->data = NULL;
	n->next = NULL;

	return n;
}

int map_put(hash_map* m, char* key, void* data)
{
	map_node *n;
	map_node *new_node;
	int key_hash = hash_key(key);

	new_node = allocate_node();
	new_node->key = strdup(key);
	new_node->data = data;
	new_node->next = NULL;

	if (m->items[key_hash])
	{
		/* hash collision, add to linked list */
		n = m->items[key_hash];
	
		/* go to the end of list */
		while(n->next!=NULL)
		{
			/* check for existing key */
			if(strcmp(n->key, key) == 0)
			{
				n->data = data;
				free(new_node->key);
				free(new_node);

				return 0;
			}
			n = n->next;
		}
		if(strcmp(n->key, key) == 0)
			{
				n->data = data;
				free(new_node->key);
				free(new_node);

				return 0;
			}
		n->next = new_node;
	}
	else
	{
		m->items[key_hash] = new_node;
	}

	m->item_count++;

	return 0;
}

/*
 Compute the hash of the key. 
 This is not the best way to do this!
*/
int hash_key(char* key)
{
	int i = 0;
	char *s = key;

	while(*s)
	{
		i += *s++;
	}

	return i % SIZE;
}

void* map_get(hash_map* m, char* key)
{
	int k = hash_key(key);
	map_node *n;

	n = m->items[k];

	while(n)
	{
		if(strcmp(n->key, key) == 0)
		{
			return n->data;		
		}

		n = n->next;
	}

	return NULL;
}

int map_print(hash_map* m)
{
	int i;
	map_node *n;

	printf("Hash_map has %d items\n\n", m->item_count);

	for(i=0; i<SIZE; i++)
	{
		n = m->items[i];
		printf("Keyhash: %d\n", i);
		while(n)
		{
			printf("     key:'%s', data:%s", n->key, (char*)n->data);
			n = n->next;
		}

		printf("\n");
	}

	return 0;
}

