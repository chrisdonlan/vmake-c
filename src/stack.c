#include "stack.h"

int stack_push(stack_t * stack, const void * o) {
  return list_ins_next((list_t *) stack,NULL,o);
}
int stack_pop(stack_t * stack, void** o) {
  return list_rm_next((list_t *) stack,NULL,o);
}
void * stack_peek(stack_t * stack){
  return stack->head == NULL ? NULL : stack->head->o;
}
