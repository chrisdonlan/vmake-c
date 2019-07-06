#include "llst.h"
llst_t * erase(llst_t * element,uint8_t favor_first)
{
	llst_t * out = 0;
	if (element->prev != 0 && element->next != 0)
	{
		((llst_t *)element->prev)->next = element->next;
		((llst_t *)element->next)->prev = element->prev;
		if(favor_first)
			out = (llst_t *) element->prev;
		else
			out = (llst_t *) element->next;
	} 
	else if (element->prev != 0 && element->next == 0)
	{
		((llst_t *)element->prev)->next = 0;
		out = (llst_t *) element->prev;
	}
	else if (element->prev == 0 && element->next != 0)
	{
		((llst_t *)element->next)->prev = 0;
		out = (llst_t *) element->next;
	}
	// if both are zero, and this is the only element, just delete.

	free(element->content);
	free(element);

	return out;
}

llst_t * tail(llst_t * list)
{
	if(list->next == 0)
		return list;

	llst_t * cursor = (llst_t *) list->next;
	while(cursor->next != 0)
		cursor = (llst_t *) cursor->next;
	return cursor;
}

llst_t * head(llst_t * list)
{
	if(list->prev == 0)
		return list;

	llst_t * cursor = (llst_t *) list->prev;
	while(cursor->prev != 0)
		cursor = (llst_t *) cursor->prev;
	return cursor;
}

llst_t * headn(llst_t * list, int n)
{
	llst_t * cursor = head(list);

	int i = 0; 
	for(int i = 0; i < n; i++){
		if(cursor->next == 0)
			break;
		cursor = (llst_t *) cursor->next;
	}
}

void d_llst(llst_t * list){
	llst_t * tl = tail(list);
	llst_t * cursor = erase(tl,1);
	while(cursor != 0)
		cursor = erase(cursor,1);
}
