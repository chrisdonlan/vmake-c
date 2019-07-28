#include <stdlib.h>
#include "cover.h"
#include "list.h"
#include "set.h"

int cover(set_t* members, set_t* subsets, set_t* covering){
  set_t intersection;
  kset_t * subset;
  list_elmt_t * member, * max_member;
  void * data;

  int max_size;

  set_init(covering, subsets->match, NULL);

  while(set_size(members) > 0 && set_size(subsets) > 0) {
    max_size = 0;
    for (member = subsets->head; member != NULL; member = member->next) {
      if (set_intersection(&intersection, &((kset_t *) member->o)->set, members) != 0) {
        return -1;
      }
      if (set_size(&intersection) > max_size) {
        max_member = member;
        max_size = set_size(&intersection);
      }

      set_destroy(&intersection);
    }

    if (max_size == 0)
      return 1;

    subset = (kset_t *) max_member->o;

    if(set_insert(covering,subset) != 0)
      return -1;

    for (member = list_head(&((kset_t *)max_member->o)->set); member != NULL; member= member->next) {
      data = member->o;

      if ( set_remove(members, (void **)&data) == 0 && members->destroy != NULL)
        members->destroy(data);
    }

    if (set_remove(subsets, (void **)&subset) != 0)
      return -1;

  }

  if(set_size(members) > 0)
    return -1;

  return 0;
}
