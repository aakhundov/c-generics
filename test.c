#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "test.h"
#include "swap.h"

void test_swap()
{
    // swap int
    int a = 1, b = 2;
    swap(&a, &b, sizeof(int));
    assert(a == 2 && b == 1);

    // swap double
    double pi = 3.14, e = 2.71;
    swap(&pi, &e, sizeof(double));
    assert(pi == 2.71 && e == 3.14);

    // swap char*
    char *s1 = strdup("First");
    char *s2 = strdup("Second");
    swap(&s1, &s2, sizeof(char *));
    assert(strcmp(s1, "Second") == 0);
    assert(strcmp(s2, "First") == 0);
    free(s1);
    free(s2);
}
