#ifndef SEARCH_ALGOS_H_
#define SEARCH_ALGOS_H_

#include <stdlib.h>

int linear_search(int *array, size_t size, int value);
void print_message(int *array, size_t size);
size_t get_middle(size_t start, size_t end);
int binary_search(int *array, size_t size, int value);

#endif
