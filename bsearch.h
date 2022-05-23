#ifndef BSEARCH_H
#define BSEARCH_H

#include <stdio.h>

void *binary_search(void *arr, void *key, size_t arrSize, size_t elemSize, int (*cmp)(void *, void *));

#endif // BSEARCH_H
