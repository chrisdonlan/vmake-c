#ifndef __CLIST_H__
#define __CLIST_H__

typedef struct clist_elmt_ {
	void                *o;
	struct clist_elmt_  *next;
} clist_elmt_t;

typedef struct clist_ {
	int            size;
	int            (*match)(const void *key1, const void * key2);
	void           (*destroy)(void * o);
	clist_elmt_t   *head;
	
} clist_t;
void clist_init(clist_t* list, void (* destroy) (void* o));
void clist_destroy(clist_t* list);
void clist_ins_next(clist_t* list, clist_elmt_t* element, const void* o);
int clist_rm_next(clist_t* list, clist_elmt_t* element, void** o);
int clist_size(const clist_t* list);
clist_elmt_t* clist_head(const clist_t* list);
void* clist_o(const clist_elmt_t* element);
clist_elmt_t* clist_next(const clist_elmt_t* element);
#endif
