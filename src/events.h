#ifndef __EVENTS_H__
#define __EVENTS_H__
#include <stdlib.h>
#include <string.h>
#include "event.h"
#include "queue.h"
int receive_event(queue_t * events, const event_t * event);
int process_event(queue_t * events, int (*dispatch)(event_t * event));
#endif
