#include "bsearch.h"

#include <stdio.h>

void *binary_search(void *arr, void *key, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *)) {
    int left = 0;
    int right = arr_size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        void *elem = (char *)arr + mid * elem_size;
        int cmp_value = cmp(elem, key);

        if (cmp_value == 0) {
            return elem;
        } else if (cmp_value < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return NULL;
}
