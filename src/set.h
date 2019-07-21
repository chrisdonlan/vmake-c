#ifndef __SET_H__
#define __SET_H__
#include <stdlib.h>
#include "list.h"

typedef list_t set_t;

#define set_destroy list_destroy
void set_init(set_t* set, int (*match)(const void * key1, const void * key2), void (*destroy)(void * data));
int set_insert(set_t* set, const void * o);
int set_remove(set_t* set, void** o);
int set_union(set_t* U, const set_t * A, const set_t* B);
int set_intersection(set_t* I, const set_t * A, const set_t * B);
int set_difference(set_t * D, const set_t* A, const set_t * B);
int set_is_member(const set_t * set, const void * o);
int set_is_subset(const set_t * A,const set_t * B); // A in B?
int set_is_equal(const set_t * A, const set_t * B);
int set_size(const set_t * set);
#endif
