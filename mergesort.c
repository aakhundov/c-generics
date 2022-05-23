#include "mergesort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void merge_halves(void *left, void *mid, void *right, size_t elemSize, int (*cmp)(void *, void *)) {
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
                memcpy(buffer_ptr, left_ptr, elemSize);
                left_ptr = (char *)left_ptr + elemSize;
            } else {
                memcpy(buffer_ptr, right_ptr, elemSize);
                right_ptr = (char *)right_ptr + elemSize;
            }
        } else if (left_ptr < mid) {
            memcpy(buffer_ptr, left_ptr, elemSize);
            left_ptr = (char *)left_ptr + elemSize;
        } else {
            memcpy(buffer_ptr, right_ptr, elemSize);
            right_ptr = (char *)right_ptr + elemSize;
        }
        buffer_ptr = (char *)buffer_ptr + elemSize;
    }

    memcpy(left, buffer, size);

    free(buffer);
}

static void merge_sort_rec(void *left, void *right, size_t elemSize, int (*cmp)(void *, void *)) {
    if (left >= (void *)((char *)right - elemSize)) {
        // less than two elements to sort
        return;
    }

    size_t length = ((char *)right - (char *)left) / elemSize;
    void *mid = (char *)left + (length / 2) * elemSize;

    merge_sort_rec(left, mid, elemSize, cmp);
    merge_sort_rec(mid, right, elemSize, cmp);
    merge_halves(left, mid, right, elemSize, cmp);
}

void merge_sort(void *arr, size_t arrSize, size_t elemSize, int (*cmp)(void *, void *)) {
    void *left = arr;
    void *right = (char *)arr + arrSize * elemSize;
    merge_sort_rec(left, right, elemSize, cmp);
}
