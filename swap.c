#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "swap.h"

void swap(void *a, void *b, size_t elemSize)
{
    void *temp = malloc(elemSize);

    memcpy(temp, a, elemSize);
    memcpy(a, b, elemSize);
    memcpy(b, temp, elemSize);

    free(temp);
}
