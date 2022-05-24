#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>

typedef struct stack {
    size_t size;
    size_t allocated;
    size_t elem_size;
    void *data;
    void (*dispose)(void *);
} stack;

void stack_init(stack *s, size_t elem_size, void (*dispose)(void *));
void stack_dispose(stack *s);

void stack_push(stack *s, void *elem_addr);
void stack_pop(stack *s, void *elem_addr);
void stack_peek(stack *s, void *elem_addr);
size_t stack_size(stack *s);

#endif  // STACK_H_
