#include "queue.h"
int queue_enqueue(queue_t * queue, const void * o){
  return list_ins_next((list_t *) queue,(list_elmt_t *) queue->tail, o);
}
int queue_dequeue(queue_t * queue, void ** o){
  return list_rm_next((list_t *) queue,NULL,o);
}
void * queue_peek(const queue_t * queue){
  return queue->head == NULL ? NULL : queue->head->o;
}
