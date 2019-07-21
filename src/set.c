#include "set.h"

void set_init(set_t* set, int (*match)(const void * key1, const void * key2), void (*destroy)(void * o))
{
  list_init((list_t*)set,destroy);
  set->match = match;
}

int set_insert(set_t* set, const void * o)
{
  if (set_is_member(set,o))
    return 1;
  return list_ins_next((list_t*)set,set->tail,o);
}

int set_remove(set_t* set, void** o)
{
  list_elmt_t *member,*prev;

  prev = NULL;

  for (member = set->head; member != NULL; member= member->next) {
    if (set->match(*o,list_o(member)))
      break;
    prev = member;
  }

  if (member == NULL)
    return -1;

  return list_rm_next(set,prev,o);
}

int set_union(set_t* U, const set_t * A, const set_t* B)
{
  list_elmt_t * member;
  void * o;

  set_init(U,A->match,NULL);

  for (member = A->head; member != NULL; member = member->next) {
    o = member->o;

    if (list_ins_next(U, U->tail, o) != 0) {
      set_destroy(U);
      return -1;
    }
  }

  for (member = B->head; member != NULL; member = member->next){
    if(set_is_member(A,member->o))
      continue;
    else {
      o = member->o;

      if(list_ins_next(U,U->tail,o) != 0) {
        set_destroy(U);
        return -1;
      }
    }
  }
  return 0;
}

int set_intersection(set_t* I, const set_t * A, const set_t * B)
{
  list_elmt_t * member;
  void * o;

  set_init(I,A->match,NULL);

  for(member = A->head; member != NULL; member = member->next) {
    if (set_is_member(B, member->o)) {
      o = member->o;

      if (list_ins_next(I,I->tail,o) != 0) {
        set_destroy(I);
        return -1;
      }
    }
  }

  return 0;
}

int set_difference(set_t * D, const set_t* A, const set_t * B)
{
  list_elmt_t * member;
  void * o;

  set_init(D,A->match,NULL);

  for (member = A->head; member != NULL; member = member->next) {
    if(!set_is_member(B,member->o)) {
      o = member->o;

      if (list_ins_next(D,D->tail,o) != 0){
        set_destroy(D);
        return -1;
      }
    }
  }
  return 0;
}

int set_is_member(const set_t * set, const void * o)
{
  list_elmt_t * member;

  for (member = set->head; member != NULL; member = member->next) {
    if (set->match(o,member->o))
      return 1;
  }

  return 0;
}

int set_is_subset(const set_t * A,const set_t * B)
{
  list_elmt_t * member;

  if (set_size(A) > set_size(B))
    return 0;

  for (member = A->head; member != NULL; member = member->next) {
    if (!set_is_member(B,member->o))
      return 0;
  }

  return 1;
}

int set_is_equal(const set_t * A, const set_t * B)
{
  if (set_size(A) != set_size(B))
    return 0;

  return set_is_subset(A,B);
}

int set_size(const set_t * set)
{
  list_size((list_t *) set);
}
