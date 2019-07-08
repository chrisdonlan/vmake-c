#ifndef __LIST_H__
#define __LIST_H__
struct list_elmt {
	struct list_elmt * next;
	void * obj;
} typedef list_elmt_t;

struct list {
	int sz;
	list_elmt_t * head;
	list_elmt_t * tail;

	int (*match)(const void * key1, const void * key2);
	int (*destroy)(void * obj);
} typedef list_t;


void list_init(list_t * list, int (*destroy) (void * obj));
void list_destroy(list_t * list);
int list_rm_next(list_t * list, list_elmt_t * element, void ** obj);

int list_insert_next(list_t * list, list_elmt_t * element, const void * obj);


int list_size(list_t * list);
list_elmt_t * list_head(list_t * list);
list_elmt_t * list_tail(list_t * list);
int list_is_head(list_t * list, list_elmt_t * element);
int list_is_tail(list_t * list, list_elmt_t * element);
void * list_obj(list_elmt_t * element);
list_elmt_t * list_next(list_elmt_t * element);
#endif