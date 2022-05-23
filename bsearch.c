#include <stdio.h>

#include "bsearch.h"

void *binary_search(void *arr, void *key, size_t arrSize, size_t elemSize, int (*cmp)(void *, void *))
{
    int left = 0;
    int right = arrSize - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        void *elem = (char *)arr + mid * elemSize;
        int cmp_value = cmp(elem, key);

        if (cmp_value == 0)
            return elem;
        else if (cmp_value < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0;
}
