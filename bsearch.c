#include "bsearch.h"

#include <stdio.h>

void *binary_search(void *arr, void *key, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *)) {
    void *left = arr;
    void *right = (char *)arr + (arr_size - 1) * elem_size;

    while (left <= right) {
        size_t len = ((char *)right - (char *)left) / elem_size;
        void *mid = (char *)left + (len / 2) * elem_size;
        int cmp_value = cmp(mid, key);

        if (cmp_value == 0) {
            return mid;
        } else if (cmp_value < 0) {
            left = (char *)mid + elem_size;
        } else {
            right = (char *)mid - elem_size;
        }
    }

    return NULL;
}
