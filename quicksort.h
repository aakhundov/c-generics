#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <stdio.h>

void quick_sort(void *arr, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *));

#endif  // QUICKSORT_H_
