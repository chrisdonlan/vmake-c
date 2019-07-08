#ifndef __DLST_H__
#define __DLST_H__
#include<stdlib.h>
#include<string.h>
struct dlist_elmt {
	struct dlist_elmt * prev;
	struct dlist_elmt * next;
	void * obj;
} typedef dlist_elmt_t;

struct dlist {
	int sz;
	dlist_elmt_t * head;
	dlist_elmt_t * tail;

	int (*match)(const void * key1, const void * key2);
	int (*destroy)(void * obj);

} typedef dlist_t;
void dlist_init(dlist_t * dlist, int (*destroy) (void * obj));
void dlist_destroy(dlist_t * dlist);
int dlist_rm(dlist_t * dlist, dlist_elmt_t * element, void ** obj);
int dlist_pop(dlist_t * dlist, void ** obj);

int dlist_insert_next(dlist_t * dlist, dlist_elmt_t * element, const void * obj);
int dlist_insert_prev(dlist_t * dlist, dlist_elmt_t * element, const void * obj);
int dlist_insert(dlist_t * dlist, dlist_elmt_t * element, const void * obj);

int dlist_size(dlist_t * dlist);
dlist_elmt_t * dlist_head(dlist_t * dlist);
dlist_elmt_t * dlist_tail(dlist_t * dlist);
int dlist_is_head(dlist_t * dlist, dlist_elmt_t * element);
int dlist_is_tail(dlist_t * dlist, dlist_elmt_t * element);
void * dlist_obj(dlist_elmt_t * element);
dlist_elmt_t * dlist_next(dlist_elmt_t * element);
dlist_elmt_t * dlist_prev(dlist_elmt_t * element);
#endif

/* TODO: ideas for potentially useful extensions
dlist_elmt_t * scan_to(dlist_t * dlist, int n);
*/
