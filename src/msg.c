#include "msg.h"
void msg_init(msg_t * msg, int (*copy)(void * tgt_o, void * o), int (*destroy)(void *o)){
  msg->code = 0;
  msg->type = 0;
  msg->o = NULL;
  msg->copy = copy;
  msg->destroy = destroy;
  return;
}

void msg_copy(msg_t * tgt,msg_t* msg){
  memcpy((void *) tgt,msg,sizeof(msg_t));
  msg->copy((void *) tgt->o,(void *) msg->o);
  return;
}
void msg_destroy(msg_t * msg){
  msg->destroy(msg->o);
  memset(msg,0,sizeof(msg));
  return;
}
