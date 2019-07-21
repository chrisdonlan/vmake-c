#include "msgs.h"
int receive_msg(queue_t * msgs, const msg_t * msg){
  msg_t * new_msg;

  if((new_msg = (msg_t *) malloc(sizeof(msg_t))) == NULL)
    return -1;

  msg_copy(new_msg,msg);
  return queue_enqueue(msgs,new_msg);
}
int process_msg(queue_t * msgs, int (*dispatch)(msg_t * msg)){
  msg_t * msg;

  if (queue_size(msgs) == 0)
    return -1;

  else {
    if(queue_dequeue(msgs,(void **) & msg) != 0)
      return -1;
    else{
      dispatch(msg);
      msg_destroy(msg);
      free(msg);
    }
  }
  return 0;
}
