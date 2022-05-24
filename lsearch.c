#include "lsearch.h"

#include <stdio.h>

void *linear_search(void *arr, void *key, size_t arr_size, size_t elem_size, int (*cmp)(void *, void *)) {
    for (size_t i = 0; i < arr_size; i++) {
        void *elem = (char *)arr + i * elem_size;
        if (cmp(key, elem) == 0) {
            return elem;
        }
    }

    return NULL;
}
