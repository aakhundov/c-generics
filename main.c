#include <stdio.h>
#include <assert.h>

#include "main.h"
#include "swap.h"

int main(int argc, char *argv[])
{
    test_swap();

    return 0;
}

void test_swap()
{
    int a = 1, b = 2;
    swap(&a, &b, sizeof(int));
    assert(a == 2 && b == 1);

    double pi = 3.14, e = 2.71;
    swap(&pi, &e, sizeof(double));
    assert(pi == 2.71 && e == 3.14);
}
