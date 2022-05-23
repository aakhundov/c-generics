#ifndef BSEARCH_H_
#define BSEARCH_H_

#include <stdio.h>

void *binary_search(void *arr, void *key, size_t arrSize, size_t elemSize, int (*cmp)(void *, void *));

#endif  // BSEARCH_H_
