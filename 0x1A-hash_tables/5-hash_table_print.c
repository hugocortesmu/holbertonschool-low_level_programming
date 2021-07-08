#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
  * hash_table_print - function that prints a hash table
  * @ht: hash table
  * Return: void
  */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int j;
	char *str = "";

	j = 0;
	if (ht == NULL)
		return;
	printf("{");
	while (j < ht->size)
	{
		node = ht->array[j];
		while (node != NULL)
		{
			printf("%s", str);
			printf("'%s': '%s'", node->key, node->value);
			str = ", ";
			node = node->next;
		}
	j++;
	}
	printf("}\n");
}
