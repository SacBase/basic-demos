/*
 *  Implementation of SAC standard module List
 */


#include "List.h"


#ifdef TAGGED_ARRAYS

#define elems_nt (elems, (AUD, (NHD, (NUQ,))))

int empty( SAC_ND_PARAM_in( elems_nt, list))
{
  int res;

  res = (elems->rest == NULL);

  if (--(*(elems->rc)) == 0) {
    free_list( elems);
  }

  return( res);
}

#undef elems_nt

#else

int empty( SAC_ND_PARAM_in_rc( list *, elems))
{
  /*
   * we do have now:
   * - list *elems;
   * -  int *__elems_rc;
   */
  int res;

  res = (elems->rest == NULL);

  if (--(*(elems->rc)) == 0) {
    free_list( elems);
  }

  return( res);
}

#endif
