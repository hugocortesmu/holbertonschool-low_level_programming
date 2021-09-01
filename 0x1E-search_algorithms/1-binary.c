#include "search_algos.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_message - prints message
 * @array: Array to search
 * @size: Size of the array
 * Return: int
 */
void print_message(int *array, size_t size)
{
	size_t j;

	printf("Searching in array: ");

	for (j = 0; j < size; j++)
	{
		if (j == size - 1)
			printf("%d\n", array[j]);
		else
			printf("%d, ", array[j]);
	}

}

/**
 * get_middle - gets the middle of a size
 * @start: number to start counting
 * @end: number to end counting
 * Return: The middle
 */
size_t get_middle(size_t start, size_t end)
{
		return (start + ((end - start) / 2));
}

/**
 * binary_search - binary searching algorithm
 * @array: Array to search
 * @size: Size of the array
 * @value: Value to search
 * Return: int
 */
int binary_search(int *array, size_t size, int value)
{
	size_t start, middle, end;
	int *ptr;

	if (array == NULL || size == 0)
		return (-1);

	ptr = array;
	start = 0;
	end = size - 1;
	middle = get_middle(start, end);

	while (size > 0)
	{
		print_message(ptr, size);

		if (value == array[middle])
			return (middle);
		else if (value < array[middle])
			end = middle - 1;
		else if (value > array[middle])
			start = middle + 1;
		size = end - start + 1;
		middle = get_middle(start, end);
		ptr = &array[start];
	}

	return (-1);
}
