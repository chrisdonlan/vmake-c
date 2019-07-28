#ifndef __COVER_H__
#define __COVER_H__
#include "set.h"
struct kset {
  void * key;
  set_t set;
} typedef kset_t;

int cover(set_t * members, set_t * subsets, set_t * covering);

#endif
