#ifndef LSEARCH_H_
#define LSEARCH_H_

#include <stdio.h>

void *linear_search(void *arr, void *key, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *));

#endif  // LSEARCH_H_
