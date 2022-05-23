#ifndef BSEARCH_H_
#define BSEARCH_H_

#include <stdio.h>

void *binary_search(void *arr, void *key, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *));

#endif  // BSEARCH_H_
