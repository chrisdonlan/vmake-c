#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "list.h"

typedef list_t queue_t;
#define queue_init list_init
#define queue_destroy list_destroy
#define queue_size list_size
int queue_enqueue(queue_t * queue, const void * o);
int queue_dequeue(queue_t * queue, void ** o);
void * queue_peek(const queue_t * queue);


#endif
