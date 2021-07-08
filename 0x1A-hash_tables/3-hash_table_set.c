#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * replace value key already exists
 * @node: node to be checked
 * @ht: hashtable to be checked
 * @idx: index to be checked
 * Return: 1 could replace, 0 key not exists
 */
int key_exists(hash_node_t *node, hash_table_t *ht, unsigned long int idx)
{
	hash_node_t *ptr;

	if (ht->array == NULL)
		return (0);
	ptr = ht->array[idx];
	while (ptr != NULL)
	{
		if (strcmp(ptr->key, node->key) == 0)
		{
			ptr->value = node->value;
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: pointer to the hash table
 * @key: key to find
 * @value: value to be added
 * Return: 1 if successful, otherwise 0
 *
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;

	if (!ht || !key || !value || strcmp(key, "") == 0)
		return (0);

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	index = key_index((const unsigned char *)key, ht->size);

	if (key_exists(new_node, ht, index))
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (1);
	}

	if (ht->array[index] != NULL)
		new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}


