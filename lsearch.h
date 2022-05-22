#ifndef LSEARCH_H
#define LSEARCH_H

#include <stdio.h>

void *lsearch(void *arr, void *key, size_t arrSize, size_t elemSize, int (*cmp)(void *, void *));

#endif // LSEARCH_H
