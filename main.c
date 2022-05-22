#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "test.h"

int main(int argc, char *argv[])
{
    TEST(test_swap);
    TEST(test_lsearch);

    return 0;
}
