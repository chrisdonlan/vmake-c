#include <stdlib.h>
#include "list.h"
#include "frames.h"
int alloc_frame(list_t* frames) {
  int frame_number,
      *o;

  if (list_size(frames) == 0)
    return -1;

  else {
    if (list_rm_next(frames,NULL,(void **)&o) != 0)
      return -1;
    else {
      frame_number = *o;
      free(o);
    }
  }

  return frame_number;
}

int free_frame(list_t* frames, int frame_number) {
  int* o;

  if ((o = (int *) malloc(sizeof(int))) == NULL)
    return -1;

  *o = frame_number;

  if (list_ins_next(frames, NULL, o) != 0)
    return -1;

  return 0;
}
