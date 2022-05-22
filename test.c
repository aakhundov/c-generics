#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "test.h"
#include "swap.h"
#include "lsearch.h"

static int cmp_int(void *p1, void *p2)
{
    int i1 = *(int *)p1;
    int i2 = *(int *)p2;
    return i2 - i1;
}

static int cmp_str(void *p1, void *p2)
{
    char *s1 = *(char **)p1;
    char *s2 = *(char **)p2;
    return strcmp(s1, s2);
}

static void test_swap_int()
{
    int a = 1, b = 2;
    swap(&a, &b, sizeof(int));
    assert(a == 2 && b == 1);
}

static void test_swap_double()
{
    double pi = 3.14, e = 2.71;
    swap(&pi, &e, sizeof(double));
    assert(pi == 2.71 && e == 3.14);
}

static void test_swap_str()
{
    char *s1 = strdup("First");
    char *s2 = strdup("Second");
    swap(&s1, &s2, sizeof(char *));
    assert(strcmp(s1, "Second") == 0);
    assert(strcmp(s2, "First") == 0);
    free(s1);
    free(s2);
}

void test_swap()
{
    test_swap_int();
    test_swap_double();
    test_swap_str();
}

static void test_lsearch_int()
{
    int arr[] = {1, 2, 3, 4, 5};
    int query;
    void *found;

    query = 4;
    found = lsearch(arr, &query, 5, sizeof(int), cmp_int);
    assert(found == arr + 3);

    query = 10;
    found = lsearch(arr, &query, 5, sizeof(int), cmp_int);
    assert(found == 0);
}

static void test_lsearch_str()
{
    char *arr[] = {"Hello", "world"};
    char *query;
    void *found;

    query = strdup("world");
    found = lsearch(arr, &query, 2, sizeof(char *), cmp_str);
    assert(found == arr + 1);
    free(query);

    query = strdup("hello");
    found = lsearch(arr, &query, 2, sizeof(char *), cmp_str);
    assert(found == 0);
    free(query);
}

void test_lsearch()
{
    test_lsearch_int();
    test_lsearch_str();
}
