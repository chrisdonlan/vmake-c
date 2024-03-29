#include<stdlib.h>
#include<string.h>
#include "dlist.h"

int dlist_size(dlist_t * dlist)
{
  return dlist->sz;
}
dlist_elmt_t * dlist_head(dlist_t * dlist)
{
  return dlist->head;
}
dlist_elmt_t * dlist_tail(dlist_t * dlist)
{
  return dlist->tail;
}
int dlist_is_head(dlist_t * dlist, dlist_elmt_t * element)
{
  return dlist->head == element ? 1 : 0;
}
int dlist_is_tail(dlist_t * dlist, dlist_elmt_t * element)
{
  return dlist->tail == element ? 1 : 0;
}
void * dlist_o(dlist_elmt_t * element)
{
  return element->o;
}
dlist_elmt_t * dlist_next(dlist_elmt_t * element)
{
  return element->next;
}
dlist_elmt_t * dlist_prev(dlist_elmt_t * element)
{
  return element->prev;
}
void dlist_init(dlist_t * dlist, int (*destroy) (void * o))
{
    dlist->sz = 0;
    dlist->destroy = destroy;
    dlist->match = NULL;
    dlist->head = NULL;
    dlist->tail = NULL;
}

void dlist_destroy(dlist_t * dlist)
{
  void * o;
  while(dlist_size(dlist) > 0) {
    if(dlist_rm(dlist,dlist->head,(void **) &o) == 0 && dlist->destroy != NULL)
      dlist->destroy(o);
  }
  memset(dlist,0,sizeof(dlist));
  return;
}

int dlist_rm(dlist_t * dlist, dlist_elmt_t * element, void ** o)
{
  dlist_elmt_t * old_element;

  if(dlist_size(dlist) == 0 || element == NULL)
    return -1;

  if(element->next == NULL)
    dlist->tail = element->prev;
  if(element->prev == NULL)
    dlist->head = element->next;


  *o = old_element->o;

  if(element == dlist->head)
  {
    dlist->head = element->next;

    if(dlist->head == NULL)
      dlist->tail = NULL;
    else
      dlist->head->prev = NULL;
  }
  else
  {
    element->prev->next = element->next;

    if(element->next == NULL)
      dlist->tail = element->prev;
    else
      element->next->prev = element->prev;
  }

  dlist->sz--;
  free(element);
  return 0;
}


int dlist_pop(dlist_t * dlist, void ** o)
{
  return dlist_rm(dlist,dlist->head,o);
}

int dlist_ins_next(dlist_t * dlist, dlist_elmt_t * element, const void * o)
{
  dlist_elmt_t * new_element;

  if((new_element = (dlist_elmt_t *) malloc(sizeof(dlist_elmt_t))) == NULL)
    return -1;

  new_element->o = (void *) o;

  if(dlist_size(dlist) == 0){

    new_element->prev = NULL;
    new_element->next = NULL;
    dlist->head = new_element;
    dlist->tail = new_element;

  } else {

    new_element->prev = element;
    new_element->next = element->next;
    element->next = new_element;

    if(element->next == NULL)
      dlist->tail = new_element;
    else
      element->next->prev = new_element;
  }

  dlist->sz++;
  return 0;
}

int dlist_ins_prev(dlist_t * dlist, dlist_elmt_t * element, const void * o)
{
  dlist_elmt_t * new_element;

  if((new_element = (dlist_elmt_t *) malloc(sizeof(dlist_elmt_t))) == NULL)
    return -1;

  new_element->o = (void *) o;

  if(dlist_size(dlist) == 0){

    new_element->prev = NULL;
    new_element->next = NULL;
    dlist->head = new_element;
    dlist->tail = new_element;

  } else {
    new_element->next = element;
    new_element->prev = element->prev;
    element->prev = new_element;

    if(element->prev == NULL)
      dlist->head = new_element;
    else
      element->prev->next = new_element;
  }

  dlist->sz++;
  return 0;
}


int dlist_ins(dlist_t * dlist, dlist_elmt_t * element, const void * o)
{
  return dlist_ins_next(dlist,element,o);
}
