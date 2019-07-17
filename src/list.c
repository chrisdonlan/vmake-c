#include<stdlib.h>
#include<string.h>
#include"list.h"

int list_size(list_t * list)
{ return list->sz; }
list_elmt_t * list_head(list_t * list)
{ return list->head; }
list_elmt_t * list_tail(list_t * list)
{ return list->tail; }
int list_is_head(list_t * list, list_elmt_t * element)
{ return element == list->head ? 1 : 0; }
int list_is_tail(list_t * list, list_elmt_t * element)
{ return element == list->tail ? 1 : 0; }
void * list_o(list_elmt_t * element)
{ return element->o; }
list_elmt_t * list_next(list_elmt_t * element)
{ return element->next; }

void list_init(list_t * list, int (*destroy) (void * o))
{
	list->head = NULL;
	list->tail = NULL;
	list->sz = 0;
	list->destroy = destroy;
	return;
}

void list_destroy(list_t * list)
{
	void * o;
	while(list->sz > 0){
		if(list_rm_next(list,NULL,o) == 0 && list->destroy != NULL)
			list->destroy(o);
	}
	memset(list,0,sizeof(list_t));
	return;
}


int list_rm_next(list_t * list, list_elmt_t * element, void ** o)
{
	list_elmt_t * old_element;

	if(list_size(list) == 0)
		return -1;
	
	if(element == NULL)
	{
		old_element = list->head;
		list->head = old_element->next;

		if(list_size(list) == 1)
			list->tail = NULL;
	}
	else 
	{
		if(element->next == NULL)
			return -1;

		old_element = element->next;
		element->next = old_element->next;

		if(element->next == NULL)
			list->tail = element;
	}

	o = old_element->o;
	free(old_element);
	list->sz--;
	return 0;
}

int list_insert_next(list_t * list, list_elmt_t * element, const void * o)
{
	list_elmt_t * new_element;

	if((new_element = (list_elmt_t *) malloc(sizeof(list_elmt_t))) == NULL)
		return -1;
	
	new_element->o = (void *) o;

	if(element == NULL)
	{
		if(list_size(list) == 0)
			list->tail = new_element;

		new_element->next = list->head;
		list->head = new_element;
	}
	else
	{
		if(element->next == NULL)
			list->tail = new_element;

		element->next = new_element;
		new_element->next = element->next;
	}
	return 0;
}
