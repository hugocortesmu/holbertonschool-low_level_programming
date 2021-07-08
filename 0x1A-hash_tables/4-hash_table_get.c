#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
/**
  * function that retrieves value associate with a key
  * @ht: hashtable
  * @key: key
  * Return: value inside
  */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	int index;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);

	if (ht->array[index] == NULL)
		return (NULL);

	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
