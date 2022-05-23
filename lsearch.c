#include "lsearch.h"

#include <stdio.h>

void *linear_search(void *arr, void *key, size_t arrSize, size_t elemSize, int (*cmp)(void *, void *)) {
    for (size_t i = 0; i < arrSize; i++) {
        void *elem = (char *)arr + i * elemSize;
        if (cmp(key, elem) == 0) {
            return elem;
        }
    }

    return 0;
}
