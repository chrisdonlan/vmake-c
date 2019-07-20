#ifndef __STACK_H__
#define __STACK_H__
#include "list.h"

// stack has the following functions
// push
// pop
// init
// destroy
// peek

typedef list_t stack_t;
#define stack_init list_init
#define stack_destroy list_destroy
#define stack_size list_size
int stack_push(stack_t * stack, const void * o);
int stack_pop(stack_t * stack, void** o);
void * stack_peek(stack_t * stack);
#endif
