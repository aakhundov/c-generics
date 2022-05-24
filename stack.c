#include "stack.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void stack_double(stack *s) {
    s->allocated *= 2;
    s->data = realloc(s->data, s->allocated * s->elem_size);
    assert(s->data != NULL);
}

void stack_init(stack *s, size_t elem_size, void (*dispose)(void *)) {
    s->size = 0;
    s->allocated = 4;
    s->elem_size = elem_size;
    s->dispose = dispose;

    s->data = malloc(s->allocated * s->elem_size);
    assert(s->data != NULL);
}

void stack_dispose(stack *s) {
    if (s->dispose != 0) {
        void *elem = s->data;
        for (size_t i = 0; i < s->size; i++) {
            s->dispose(elem);
            elem = (char *)elem + s->elem_size;
        }
    }

    free(s->data);
}

void stack_push(stack *s, void *elem_addr) {
    if (s->size == s->allocated) {
        stack_double(s);
    }

    void *elem = (char *)s->data + s->size * s->elem_size;
    memcpy(elem, elem_addr, s->elem_size);
    s->size += 1;
}

void stack_pop(stack *s, void *elem_addr) {
    assert(s->size > 0);

    s->size -= 1;
    void *elem = (char *)s->data + s->size * s->elem_size;
    memcpy(elem_addr, elem, s->elem_size);
}

void stack_peek(stack *s, void *elem_addr) {
    assert(s->size > 0);

    void *elem = (char *)s->data + (s->size - 1) * s->elem_size;
    memcpy(elem_addr, elem, s->elem_size);
}

size_t stack_size(stack *s) {
    return s->size;
}
