#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <stdio.h>

void merge_sort(void *arr, size_t arrSize, size_t elemSize, int (*cmp)(void *, void *));

#endif  // MERGESORT_H_
