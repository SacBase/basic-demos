/*
 *  Implementation of SAC standard module List
 */


#include "List.h"


int length( SAC_ND_KS_DEC_IN_RC(list *, elems))
{
/*
 * we do have now:
 * - list *elems;
 * -  int *__elems_rc;
 */

  list *ptr=elems;
  int res=0;

  while( ptr->rest != NULL) {
    ptr=ptr->rest;
    res++;
  }
  if(--elems->rc == 0)
    free_list( elems);

  return( res);
}


