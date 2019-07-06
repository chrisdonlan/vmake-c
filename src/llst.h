#include<stdint.h>
#include<stdlib.h>
struct llst {
	void * start;
	void * prev;
	void * next;
	void * content;
} typedef llst_t;
struct llst * erase(struct llst * element,uint8_t favor_first);
struct llst * tail(struct llst * list);
struct llst * head(struct llst * list);
struct llst * headn(struct llst * list, int n);
void dllst (struct llst * list);
