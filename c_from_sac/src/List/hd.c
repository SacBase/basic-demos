/*
 *  Implementation of SAC standard module List
 */


#include "List.h"


#ifdef TAGGED_ARRAYS

#define elems_nt (elems, (AUD, (NHD, (NUQ,))))

int hd( SAC_ND_PARAM_in( elems_nt, list))
{
  int res;

  if (elems->rest == NULL) {
    SAC_RuntimeError( "hd applied to NIL\n");
  }
  res = elems->elem;

  if (--(*(elems->rc)) == 0) {
    free_list( elems);
  }

  return( res);
}

#undef elems_nt

#else

int hd( SAC_ND_PARAM_in_rc( list *, elems))
{
  /*
   * we do have now: 
   * - list *elems;
   * -  int *__elems_rc;
   */
  int res;

  if (elems->rest == NULL) {
    SAC_RuntimeError( "hd applied to NIL\n");
  }
  res = elems->elem;

  if (--(*(elems->rc)) == 0) {
    free_list( elems);
  }

  return( res);
}

#endif
