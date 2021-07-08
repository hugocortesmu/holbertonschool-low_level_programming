#include <stdlib.h>
#include "hash_tables.h"

/**
* Deletes a hash table.
* @ht: Hash table
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int j;
	hash_node_t *ptr, *head;

	for (j = 0; j < ht->size; j++)
		if (ht->array[j])
		{
			head = ht->array[j];
			while (head != NULL)
			{
				ptr = head->next;
				free(head->key);
				free(head->value);
				free(head);
				head = ptr;
			}
		}
	free(ht->array);
	free(ht);
}
