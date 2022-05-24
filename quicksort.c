#include "quicksort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "swap.h"

static void *partition(void *left, void *right, void *pivot, size_t elem_size, int (*cmp)(void *, void *)) {
    swap(pivot, right, elem_size);

    void *elem = left;
    void *high = left;
    while (elem < right) {
        if (cmp(elem, right) < 0) {
            swap(elem, high, elem_size);
            high = (char *)high + elem_size;
        }
        elem = (char *)elem + elem_size;
    }

    swap(right, high, elem_size);

    return high;
}

static void quick_sort_rec(void *left, void *right, size_t elem_size, int (*cmp)(void *, void *)) {
    if (left >= (void *)((char *)right - elem_size)) {
        // less than two elements to sort
        return;
    }

    void *before_right = (char *)right - elem_size;
    size_t length = ((char *)right - (char *)left) / elem_size;
    void *pivot = (char *)left + (rand() % length) * elem_size;
    pivot = partition(left, before_right, pivot, elem_size, cmp);
    void *after_pivot = (char *)pivot + elem_size;

    quick_sort_rec(left, pivot, elem_size, cmp);
    quick_sort_rec(after_pivot, right, elem_size, cmp);
}

void quick_sort(void *arr, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *)) {
    void *left = arr;
    void *right = (char *)arr + arr_size * elem_size;

    quick_sort_rec(left, right, elem_size, cmp);
}
