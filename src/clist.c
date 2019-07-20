#include <stdlib.h>
#include <string.h>
#include "clist.h"

void clist_init(clist_t* list, void (*destroy) (void* o)) {
  list->sz=0;
  list->destroy = destroy;
  list->head = NULL;
  return;
}

void clist_destroy(clist_t* list) {
  void* o;
  while (clist_size(list) > 0) {
    if (clist_rm_next(list,list->head,(void **)&o) == 0 && list->destroy != NULL)
      list->destroy(o);
  }
  memset(list,0,sizeof(clist_t));
  return;
}

int clist_ins_next(clist_t* list, clist_elmt_t* element, const void* o){
  clist_elmt_t* new_element;

  if ((new_element = (clist_elmt_t*) malloc(sizeof(clist_elmt_t))) == NULL)
    return -1;

  new_element->o = (void*) o;

  if (clist_size(list) == 0) {
    new_element->next = new_element;
    list->head = new_element;
  }
  else {
    new_element->next = element->next;
    element->next = new_element;
  }

  list->sz++;
  return 0;
}


int clist_rm_next(clist_t* list, clist_elmt_t* element, void** o){
  clist_elmt_t* old_element;

  if (clist_size(list) == 0)
    return -1;

  *o = element->next->o;

  if (element->next == element) {
    old_element = element->next;
    list->head = NULL;
  }
  else {

    old_element = element->next;
    element->next = element->next->next;

    if (old_element == clist_head(list))
      list->head = old_element->next;

  }

  free(old_element);
  list->sz--;

  return 0;
}

