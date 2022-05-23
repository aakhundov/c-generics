#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <stdio.h>

void merge_sort(void *arr, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *));

#endif  // MERGESORT_H_
