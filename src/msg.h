#ifndef __MSG_H__
#define __MSG_H__
#include <string.h>
#include "queue.h"
struct msg {
  int code;
  int type;
  void * o;

  int (*copy)(void * tgt_o,void * o);
  int (*destroy)(void * o);
} typedef msg_t;

void msg_init(msg_t * msg, int (*copy)(void * tgt_o,void * o), int (*destroy)(void *o));
void msg_copy(msg_t * tgt,msg_t* msg);
void msg_destroy(msg_t * msg);
#endif
