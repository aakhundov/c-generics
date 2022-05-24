#include "main.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

int main(int argc, char *argv[]) {
    TEST(test_swap);
    TEST(test_linear_search);
    TEST(test_binary_search);
    TEST(test_merge_sort);
    TEST(test_quick_sort);

    return 0;
}
