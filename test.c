#include "test.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bsearch.h"
#include "lsearch.h"
#include "mergesort.h"
#include "queue.h"
#include "quicksort.h"
#include "stack.h"
#include "swap.h"

static int cmp_int(void *p1, void *p2) {
    int i1 = *(int *)p1;
    int i2 = *(int *)p2;

    return i1 - i2;
}

static int cmp_double(void *p1, void *p2) {
    double d1 = *(double *)p1;
    double d2 = *(double *)p2;

    if (d1 == d2)
        return 0;
    else if (d1 < d2)
        return -1;
    else
        return 1;
}

static int cmp_str(void *p1, void *p2) {
    char *s1 = *(char **)p1;
    char *s2 = *(char **)p2;

    return strcmp(s1, s2);
}

static void dispose_str(void *p) {
    char *s = *(char **)p;
    free(s);
}

static void test_swap_int() {
    int a = 1, b = 2;
    swap(&a, &b, sizeof(int));
    assert(a == 2 && b == 1);
}

static void test_swap_double() {
    double pi = 3.14, e = 2.71;
    swap(&pi, &e, sizeof(double));
    assert(pi == 2.71 && e == 3.14);
}

static void test_swap_str() {
    char *s1 = strdup("First");
    char *s2 = strdup("Second");
    swap(&s1, &s2, sizeof(char *));
    assert(strcmp(s1, "Second") == 0);
    assert(strcmp(s2, "First") == 0);
    free(s1);
    free(s2);
}

void test_swap() {
    test_swap_int();
    test_swap_double();
    test_swap_str();
}

static void test_linear_search_int() {
    int arr[] = {1, 2, 3, 4, 5};
    int query;
    void *found;

    query = 4;
    found = linear_search(arr, &query, 5, sizeof(int), cmp_int);
    assert(found == arr + 3);

    query = 10;
    found = linear_search(arr, &query, 5, sizeof(int), cmp_int);
    assert(found == NULL);
}

static void test_linear_search_double() {
    double arr[] = {6.023, 2.71, 3.14};
    double query;
    void *found;

    query = 3.14;
    found = linear_search(arr, &query, 5, sizeof(double), cmp_double);
    assert(found == arr + 2);

    query = 2.71;
    found = linear_search(arr, &query, 5, sizeof(double), cmp_double);
    assert(found == arr + 1);

    query = 1.234;
    found = linear_search(arr, &query, 5, sizeof(double), cmp_double);
    assert(found == NULL);
}

static void test_linear_search_str() {
    char *arr[] = {"Hello", "world"};
    char *query;
    void *found;

    query = strdup("world");
    found = linear_search(arr, &query, 2, sizeof(char *), cmp_str);
    assert(found == arr + 1);
    free(query);

    query = strdup("hello");
    found = linear_search(arr, &query, 2, sizeof(char *), cmp_str);
    assert(found == NULL);
    free(query);
}

static void test_linear_search_empty() {
    int arr[] = {};
    int query = 10;
    void *found = linear_search(arr, &query, 0, sizeof(int), cmp_int);
    assert(found == NULL);
}

void test_linear_search() {
    test_linear_search_int();
    test_linear_search_double();
    test_linear_search_str();
    test_linear_search_empty();
}

static void test_binary_search_int() {
    int arr[] = {-20, -5, 0, 1, 1, 12, 134, 150};
    int query;
    void *found;

    query = 12;
    found = binary_search(arr, &query, 8, sizeof(int), cmp_int);
    assert(found == arr + 5);

    query = -20;
    found = binary_search(arr, &query, 8, sizeof(int), cmp_int);
    assert(found == arr);

    query = 150;
    found = binary_search(arr, &query, 8, sizeof(int), cmp_int);
    assert(found == arr + 7);

    query = 1;
    found = binary_search(arr, &query, 8, sizeof(int), cmp_int);
    assert(found == arr + 3 || found == arr + 4);

    query = 2;
    found = binary_search(arr, &query, 8, sizeof(int), cmp_int);
    assert(found == NULL);

    query = -100;
    found = binary_search(arr, &query, 8, sizeof(int), cmp_int);
    assert(found == NULL);

    query = 200;
    found = binary_search(arr, &query, 8, sizeof(int), cmp_int);
    assert(found == NULL);
}

static void test_binary_search_double() {
    double arr[] = {2.71, 3.14, 6.023};
    double query;
    void *found;

    query = 3.14;
    found = binary_search(arr, &query, 5, sizeof(double), cmp_double);
    assert(found == arr + 1);

    query = 2.71;
    found = binary_search(arr, &query, 5, sizeof(double), cmp_double);
    assert(found == arr + 0);

    query = 6.023;
    found = binary_search(arr, &query, 5, sizeof(double), cmp_double);
    assert(found == arr + 2);

    query = 1.234;
    found = binary_search(arr, &query, 5, sizeof(double), cmp_double);
    assert(found == NULL);
}

static void test_binary_search_str() {
    char *arr[] = {"Al", "Bob", "Bob", "Carl", "Cat", "Dave"};
    char *query;
    void *found;

    query = "Cat";
    found = binary_search(arr, &query, 6, sizeof(char *), cmp_str);
    assert(found == arr + 4);

    query = "Al";
    found = binary_search(arr, &query, 6, sizeof(char *), cmp_str);
    assert(found == arr);

    query = "Dave";
    found = binary_search(arr, &query, 6, sizeof(char *), cmp_str);
    assert(found == arr + 5);

    query = "Bob";
    found = binary_search(arr, &query, 6, sizeof(char *), cmp_str);
    assert(found == arr + 1 || found == arr + 2);

    query = "";
    found = binary_search(arr, &query, 6, sizeof(char *), cmp_str);
    assert(found == NULL);

    query = "Ad";
    found = binary_search(arr, &query, 6, sizeof(char *), cmp_str);
    assert(found == NULL);

    query = "Bert";
    found = binary_search(arr, &query, 6, sizeof(char *), cmp_str);
    assert(found == NULL);

    query = "Zoe";
    found = binary_search(arr, &query, 6, sizeof(char *), cmp_str);
    assert(found == NULL);
}

static void test_binary_search_empty() {
    int arr[] = {};
    int query = 10;
    void *found = binary_search(arr, &query, 0, sizeof(int), cmp_int);
    assert(found == NULL);
}

void test_binary_search() {
    test_binary_search_int();
    test_binary_search_double();
    test_binary_search_str();
    test_binary_search_empty();
}

static void test_sort_int(void (*sort_fn)(void *, size_t, size_t, int (*)(void *, void *))) {
    size_t size = 7;
    int arr1[] = {123, 456, -2, 22, 0, -146, 52};
    int arr2[] = {-146, -2, 0, 22, 52, 123, 456};
    int arr3[] = {456, 123, 52, 22, 0, -2, -146};
    int target[] = {-146, -2, 0, 22, 52, 123, 456};

    sort_fn(arr1, size, sizeof(int), cmp_int);
    for (size_t i = 0; i < size; i++) {
        assert(arr1[i] == target[i]);
    }

    sort_fn(arr2, size, sizeof(int), cmp_int);
    for (size_t i = 0; i < size; i++) {
        assert(arr2[i] == target[i]);
    }

    sort_fn(arr3, size, sizeof(int), cmp_int);
    for (size_t i = 0; i < size; i++) {
        assert(arr3[i] == target[i]);
    }
}

static void test_sort_double(void (*sort_fn)(void *, size_t, size_t, int (*)(void *, void *))) {
    size_t size = 7;
    double arr1[] = {6.12, 5.1, 44.2, 3.0, -222.2, -15, 0.0123};
    double arr2[] = {44.2, 6.12, 5.1, 3.0, 0.0123, -15, -222.2};
    double arr3[] = {-222.2, -15, 0.0123, 3.0, 5.1, 6.12, 44.2};
    double target[] = {-222.2, -15, 0.0123, 3.0, 5.1, 6.12, 44.2};

    sort_fn(arr1, size, sizeof(double), cmp_double);
    for (size_t i = 0; i < size; i++) {
        assert(arr1[i] == target[i]);
    }

    sort_fn(arr2, size, sizeof(double), cmp_double);
    for (size_t i = 0; i < size; i++) {
        assert(arr2[i] == target[i]);
    }

    sort_fn(arr3, size, sizeof(double), cmp_double);
    for (size_t i = 0; i < size; i++) {
        assert(arr3[i] == target[i]);
    }
}

static void test_sort_str(void (*sort_fn)(void *, size_t, size_t, int (*)(void *, void *))) {
    size_t size = 6;
    char *target[] = {"Al", "Bob", "Bob", "Carl", "Cat", "Dave"};
    char *arr1[] = {"Bob", "Dave", "Al", "Bob", "Cat", "Carl"};
    char *arr2[] = {"Dave", "Cat", "Carl", "Bob", "Bob", "Al"};
    char *arr3[] = {"Al", "Bob", "Bob", "Carl", "Cat", "Dave"};

    sort_fn(arr1, size, sizeof(char *), cmp_str);
    for (size_t i = 0; i < size; i++) {
        assert(arr1[i] == target[i]);
    }

    sort_fn(arr2, size, sizeof(char *), cmp_str);
    for (size_t i = 0; i < size; i++) {
        assert(arr2[i] == target[i]);
    }

    sort_fn(arr3, size, sizeof(char *), cmp_str);
    for (size_t i = 0; i < size; i++) {
        assert(arr3[i] == target[i]);
    }
}

static void test_sort_empty(void (*sort_fn)(void *, size_t, size_t, int (*)(void *, void *))) {
    int arr[] = {};
    sort_fn(arr, 0, sizeof(int), cmp_int);
}

void test_merge_sort() {
    test_sort_int(merge_sort);
    test_sort_double(merge_sort);
    test_sort_str(merge_sort);
    test_sort_empty(merge_sort);
}

void test_quick_sort() {
    test_sort_int(quick_sort);
    test_sort_double(quick_sort);
    test_sort_str(quick_sort);
    test_sort_empty(quick_sort);
}

static void test_stack_int() {
    int j;
    stack s;

    stack_init(&s, sizeof(int), NULL);
    assert(stack_size(&s) == 0);

    for (int i = 0; i < 10; i++) {
        stack_push(&s, &i);
        stack_peek(&s, &j);
        assert(stack_size(&s) == i + 1);
        assert(j == i);
    }

    for (int i = 9; i > 0; i--) {
        stack_pop(&s, &j);
        assert(stack_size(&s) == i);
        assert(j == i);
        stack_peek(&s, &j);
        assert(j == i - 1);
    }

    assert(stack_size(&s) == 1);
    stack_dispose(&s);
}

static void test_stack_double() {
    double j;
    stack s;

    stack_init(&s, sizeof(double), NULL);
    assert(stack_size(&s) == 0);

    for (double i = 0; i < 10; i++) {
        stack_push(&s, &i);
        stack_peek(&s, &j);
        assert(stack_size(&s) == i + 1);
        assert(j == i);
    }

    for (double i = 9; i > 0; i--) {
        stack_pop(&s, &j);
        assert(stack_size(&s) == i);
        assert(j == i);
        stack_peek(&s, &j);
        assert(j == i - 1);
    }

    assert(stack_size(&s) == 1);
    stack_dispose(&s);
}

static void test_stack_str() {
    char *arr[] = {"Al", "Bob", "Bob", "Carl", "Cat", "Dave"};

    char *word;
    stack s;

    stack_init(&s, sizeof(char *), dispose_str);
    assert(stack_size(&s) == 0);

    for (size_t i = 0; i < 6; i++) {
        word = strdup(arr[i]);
        stack_push(&s, &word);
        stack_peek(&s, &word);
        assert(stack_size(&s) == i + 1);
        assert(strcmp(word, arr[i]) == 0);
    }

    for (size_t i = 5; i > 0; i--) {
        stack_pop(&s, &word);
        assert(stack_size(&s) == i);
        assert(strcmp(word, arr[i]) == 0);
        free(word);
        stack_peek(&s, &word);
        assert(strcmp(word, arr[i - 1]) == 0);
    }

    assert(stack_size(&s) == 1);
    stack_dispose(&s);
}

static void test_stack_empty() {
    stack s;
    stack_init(&s, sizeof(int), NULL);
    assert(stack_size(&s) == 0);
    stack_dispose(&s);
}

void test_stack() {
    test_stack_int();
    test_stack_double();
    test_stack_str();
    test_stack_empty();
}

static void test_queue_int() {
    int j;
    queue q;

    queue_init(&q, sizeof(int), NULL);
    assert(queue_size(&q) == 0);

    for (int i = 0; i < 10; i++) {
        queue_enqueue(&q, &i);
        queue_front(&q, &j);
        assert(queue_size(&q) == i + 1);
        assert(j == 0);
    }

    for (int i = 0; i < 9; i++) {
        queue_dequeue(&q, &j);
        assert(queue_size(&q) == 9 - i);
        assert(j == i);
        queue_front(&q, &j);
        assert(j == i + 1);
    }

    assert(queue_size(&q) == 1);
    queue_dispose(&q);
}

static void test_queue_double() {
    double j;
    queue q;

    queue_init(&q, sizeof(double), NULL);
    assert(queue_size(&q) == 0);

    for (double i = 0; i < 10; i++) {
        queue_enqueue(&q, &i);
        queue_front(&q, &j);
        assert(queue_size(&q) == i + 1);
        assert(j == 0);
    }

    for (double i = 0; i < 9; i++) {
        queue_dequeue(&q, &j);
        assert(queue_size(&q) == 9 - i);
        assert(j == i);
        queue_front(&q, &j);
        assert(j == i + 1);
    }

    assert(queue_size(&q) == 1);
    queue_dispose(&q);
}

static void test_queue_str() {
    char *arr[] = {"Al", "Bob", "Bob", "Carl", "Cat", "Dave"};

    char *word;
    queue q;

    queue_init(&q, sizeof(char *), dispose_str);
    assert(queue_size(&q) == 0);

    for (size_t i = 0; i < 6; i++) {
        word = strdup(arr[i]);
        queue_enqueue(&q, &word);
        queue_front(&q, &word);
        assert(queue_size(&q) == i + 1);
        assert(strcmp(word, arr[0]) == 0);
    }

    for (size_t i = 0; i < 5; i++) {
        queue_dequeue(&q, &word);
        assert(queue_size(&q) == 5 - i);
        assert(strcmp(word, arr[i]) == 0);
        free(word);
        queue_front(&q, &word);
        assert(strcmp(word, arr[i + 1]) == 0);
    }

    assert(queue_size(&q) == 1);
    queue_dispose(&q);
}

static void test_queue_empty() {
    queue q;
    queue_init(&q, sizeof(int), NULL);
    assert(queue_size(&q) == 0);
    queue_dispose(&q);
}

void test_queue() {
    test_queue_int();
    test_queue_double();
    test_queue_str();
    test_queue_empty();
}
