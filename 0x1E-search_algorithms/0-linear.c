#include "search_algos.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * linear_search - linear searching algorithm
 * @array: Array to search
 * @size: Size of the array
 * @value: Value to search
 * Return: int
 */
int linear_search(int *array, size_t size, int value)
{
	size_t j;

	if (array == NULL)
		return (-1);

	for (j = 0; j < size; j++)
	{
		printf("Value checked array[%lu] = [%d]\n", (unsigned long)j, array[j]);
		if (array[j] == value)
			return (j);
	}
	return (-1);
}
