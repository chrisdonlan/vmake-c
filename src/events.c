#include "events.h"
int receive_event(queue_t * events, const event_t * event){
  event_t * new_event;

  if((new_event = (event_t *) malloc(sizeof(event_t))) == NULL)
    return -1;

  memcpy((void *) event,new_event,sizeof(event_t));

  return queue_enqueue(events,new_event);
}
int process_event(queue_t * events, int (*dispatch)(event_t * event)){
  event_t * event;

  if (queue_size(events) == 0)
    return -1;

  else {
    if(queue_dequeue(events,(void **) & event) != 0)
      return -1;
    else{
      dispatch(event);
      free(event);
    }
  }
  return 0;
}
