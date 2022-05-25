#include "lsearch.h"

#include <stdio.h>

void *linear_search(void *arr, void *key, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *)) {
    void *elem = arr;
    for (size_t i = 0; i < arr_size; i++) {
        if (cmp(key, elem) == 0) {
            return elem;
        }
        elem = (char *)elem + elem_size;
    }

    return NULL;
}
