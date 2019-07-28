#ifndef __CHTBL_H__
#define __CHTBL_H__

#include <stdlib.h>
#include "list.h"

struct chtbl {
  int buckets;
  int (*h)(const void *key);
  int (*match)(const void *key1,const void * key2);
  void (*destroy)(void *data);

  int sz;
  list_t * table;
} typedef chtbl_t;

int chtbl_init(chtbl_t * htbl, int buckets, int (*h)(const void * key), int (*match)(const void * key1, const void * key2), void (*destroy) (void * data));

void chtbl_destroy(chtbl_t * htbl);

int chtbl_insert(chtbl_t * htbl, const void * data);
int chtbl_remove(chtbl_t * htbl, void **data);
int chtbl_lookup(const chtbl_t * htbl, void ** data);
int chtbl_size(chtbl_t * htbl);

#endif
