#ifndef __MSGS_H__
#define __MSGS_H__
#include <stdlib.h>
#include <string.h>
#include "msg.h"
#include "queue.h"
int receive_msg(queue_t * msgs, const msg_t * msg);
int process_msg(queue_t * msgs, int (*dispatch)(msg_t * msg));
#endif
