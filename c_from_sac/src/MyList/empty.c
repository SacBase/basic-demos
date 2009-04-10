/*
 *  Implementation of SAC standard module List
 */


#include "List.h"


#define elems_nt (elems, T_SHP(SCL, T_HID(HID, T_UNQ(NUQ, T_EMPTY))))

int empty( SAC_ND_PARAM_in( elems_nt, list *))
{
  int res;

  res = (elems->rest == NULL);

  if (--(DESC_RC( elems->desc)) == 0) {
    free_list( elems);
  }

  return( res);
}

#undef elems_nt
