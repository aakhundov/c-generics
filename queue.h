#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>

#include "stack.h"

typedef struct queue {
    size_t size;
    size_t elem_size;
    stack in_stack;
    stack out_stack;
} queue;

void queue_init(queue *q, size_t elem_size, void (*dispose)(void *));
void queue_dispose(queue *q);

void queue_enqueue(queue *q, void *elem_addr);
void queue_dequeue(queue *q, void *elem_addr);
void queue_front(queue *q, void *elem_addr);
size_t queue_size(queue *q);

#endif  // QUEUE_H_
