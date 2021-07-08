#include "hash_tables.h"

/**
 *function that gives you the index of a key using djb2.
 * @key: data to be stored
 * @size: size of the hashmap
 * Return:  index at which the key/value pair should be stored in
 * the array of the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
