#include "queue.h"

#include <assert.h>
#include <stdlib.h>

#include "stack.h"

static void queue_move_elems(queue *q) {
    void *elem = malloc(q->elem_size);
    size_t in_size = stack_size(&q->in_stack);

    for (size_t i = 0; i < in_size; i++) {
        stack_pop(&q->in_stack, elem);
        stack_push(&q->out_stack, elem);
    }

    free(elem);
}

void queue_init(queue *q, size_t elem_size, void (*dispose)(void *)) {
    q->size = 0;
    q->elem_size = elem_size;

    stack_init(&q->in_stack, elem_size, dispose);
    stack_init(&q->out_stack, elem_size, dispose);
}

void queue_dispose(queue *q) {
    stack_dispose(&q->in_stack);
    stack_dispose(&q->out_stack);
}

void queue_enqueue(queue *q, void *elem_addr) {
    stack_push(&q->in_stack, elem_addr);
    q->size++;
}

void queue_dequeue(queue *q, void *elem_addr) {
    assert(q->size > 0);
    if (stack_size(&q->out_stack) == 0) {
        queue_move_elems(q);
    }

    stack_pop(&q->out_stack, elem_addr);
    q->size--;
}

void queue_front(queue *q, void *elem_addr) {
    assert(q->size > 0);
    if (stack_size(&q->out_stack) == 0) {
        queue_move_elems(q);
    }

    stack_peek(&q->out_stack, elem_addr);
}

size_t queue_size(queue *q) {
    return q->size;
}
