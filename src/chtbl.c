#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "chtbl.h"


int chtbl_init(chtbl_t * htbl, int buckets, int (*h)(const void * key), int (*match)(const void * key1, const void * key2), void (*destroy) (void * data)){
  int i;
  if((htbl->table = (list_t *) malloc(buckets * sizeof(list_t))) == NULL)
    return -1;

  htbl->buckets = buckets;
  for(i = 0; i < htbl->buckets; i++)
    list_init(&htbl->table[i],destroy);

  htbl->h = h;
  htbl->match = match;
  htbl->destroy = destroy;
  htbl->sz = 0;

  return 0;
}

void chtbl_destroy(chtbl_t * htbl){
  int i;
  for (i = 0; i < htbl->buckets; i++){
    list_destroy(&htbl->table[i]);
  }
  free(htbl->table);

  memset(htbl, 0, sizeof(chtbl_t));

  return;
}

int chtbl_insert(chtbl_t * htbl, const void * data){
  void * temp;
  int bucket, retval;

  temp = (void *) data;

  if (chtbl_lookup(htbl, &temp) == 0)
    return 1;

  bucket = htbl->h(data) % htbl->buckets;

  if((retval = list_ins_next(&htbl->table[bucket],NULL,data)) == 0)
    htbl->sz++;

  return retval;

}

int chtbl_remove(chtbl_t * htbl, void **data){
  list_elmt_t * element, * prev;
  int bucket;


  bucket = htbl->h(*data) % htbl->buckets;

  prev = NULL;

  for(element = htbl->table[bucket].head; element != NULL; element = element->next){
    if (htbl->match(*data,element->o)) {
      if (list_rm_next(&htbl->table[bucket],prev,data) == 0) {
        htbl->sz--;
        return 0;
      } else return -1;

    }
    prev = element;
  }
  return -1; // data was not found
}
int chtbl_lookup(const chtbl_t * htbl, void ** data){
  list_elmt_t * element;
  int bucket;
  bucket = htbl->h(*data) % htbl->buckets;

  for (element = htbl->table[bucket].head; element != NULL; element = element->next) {
    if (htbl->match(*data, element->o)) {
      *data = element->o;
      return 0;
    }
  }
  return -1; // data was not found
}
int chtbl_size(chtbl_t * htbl){
  htbl->sz;
}
