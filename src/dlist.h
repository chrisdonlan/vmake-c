#ifndef __DLIST_H__
#define __DLIST_H__
typedef struct dlist_elmt_ {
  struct dlist_elmt_ * prev;
  struct dlist_elmt_ * next;
  void * o;
} dlist_elmt_t;

typedef struct dlist_ {
  int sz;
  dlist_elmt_t * head;
  dlist_elmt_t * tail;

  int (*match)(const void * key1, const void * key2);
  int (*destroy)(void * o);

} dlist_t;
void dlist_init(dlist_t * dlist, int (*destroy) (void * o));
void dlist_destroy(dlist_t * dlist);
int dlist_rm(dlist_t * dlist, dlist_elmt_t * element, void ** o);
int dlist_pop(dlist_t * dlist, void ** o);

int dlist_ins_next(dlist_t * dlist, dlist_elmt_t * element, const void * o);
int dlist_ins_prev(dlist_t * dlist, dlist_elmt_t * element, const void * o);
int dlist_ins(dlist_t * dlist, dlist_elmt_t * element, const void * o);

int dlist_size(dlist_t * dlist);
dlist_elmt_t * dlist_head(dlist_t * dlist);
dlist_elmt_t * dlist_tail(dlist_t * dlist);
int dlist_is_head(dlist_t * dlist, dlist_elmt_t * element);
int dlist_is_tail(dlist_t * dlist, dlist_elmt_t * element);
void * dlist_o(dlist_elmt_t * element);
dlist_elmt_t * dlist_next(dlist_elmt_t * element);
dlist_elmt_t * dlist_prev(dlist_elmt_t * element);
#endif

/* TODO: ideas for potentially useful extensions
dlist_elmt_t * scan_to(dlist_t * dlist, int n);
*/
