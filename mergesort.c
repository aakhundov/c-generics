#include "mergesort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void merge_halves(void *left, void *mid, void *right, size_t elem_size, int (*cmp)(void *, void *)) {
    if (left >= mid || mid >= right) {
        // one of the halves is empty
        return;
    }

    size_t size = (char *)right - (char *)left;
    void *buffer = malloc(size);

    void *left_ptr = left;
    void *right_ptr = mid;
    void *buffer_ptr = buffer;

    while (left_ptr < mid || right_ptr < right) {
        if (left_ptr < mid && right_ptr < right) {
            if (cmp(left_ptr, right_ptr) < 0) {
                memcpy(buffer_ptr, left_ptr, elem_size);
                left_ptr = (char *)left_ptr + elem_size;
            } else {
                memcpy(buffer_ptr, right_ptr, elem_size);
                right_ptr = (char *)right_ptr + elem_size;
            }
        } else if (left_ptr < mid) {
            memcpy(buffer_ptr, left_ptr, elem_size);
            left_ptr = (char *)left_ptr + elem_size;
        } else {
            memcpy(buffer_ptr, right_ptr, elem_size);
            right_ptr = (char *)right_ptr + elem_size;
        }
        buffer_ptr = (char *)buffer_ptr + elem_size;
    }

    memcpy(left, buffer, size);

    free(buffer);
}

static void merge_sort_rec(void *left, void *right, size_t elem_size, int (*cmp)(void *, void *)) {
    if (left >= (void *)((char *)right - elem_size)) {
        // less than two elements to sort
        return;
    }

    size_t length = ((char *)right - (char *)left) / elem_size;
    void *mid = (char *)left + (length / 2) * elem_size;

    merge_sort_rec(left, mid, elem_size, cmp);
    merge_sort_rec(mid, right, elem_size, cmp);
    merge_halves(left, mid, right, elem_size, cmp);
}

void merge_sort(void *arr, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *)) {
    void *left = arr;
    void *right = (char *)arr + arr_size * elem_size;
    merge_sort_rec(left, right, elem_size, cmp);
}
