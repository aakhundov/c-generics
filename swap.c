#include "swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t elem_size) {
    void *temp = malloc(elem_size);

    memcpy(temp, a, elem_size);
    memcpy(a, b, elem_size);
    memcpy(b, temp, elem_size);

    free(temp);
}
