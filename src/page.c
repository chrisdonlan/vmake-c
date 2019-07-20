#include "clist.h"
#include "page.h"
int replace_page(clist_elmt_t** current){
  while (((page_t *) (*current)->o)->reference != 0) {
    ((page_t *) (*current)->o)->reference = 0;
    *current = clist_next(*current);
  }

  return ((page_t *)(*current)->o)->number;
}
