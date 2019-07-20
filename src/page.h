#ifndef __PAGE_H__
#define __PAGE_H__
#include "clist.h"
struct page {
  int number;
  int reference;
} typedef page_t;

int replace_page(clist_elmt_t** current);
#endif
