/********  c program using a SAC module exported as a c library *******/

#include <stdlib.h>
#include <stdio.h>
#include "sacinterface.h"
#include "include/tutorialMod_c.h"

#define SMALLARRAY 20

int main()
{
  int i;
  int *int_data_in;
  int *int_data_out;

  SACarg vector_out;
  SACarg vector_in;
  SACarg parameter;

  /**
   *  init C data vector:
   */
  int_data_in=(int*)malloc(SMALLARRAY*sizeof(int));
  for(i=0; i<SMALLARRAY; i++) {
    int_data_in[i]=i+1;
  }

  /**
   * convert c data to abstract datatype SAC_arg:
   */
  vector_in = SACARGconvertFromIntPointer( int_data_in, 1, SMALLARRAY);
  parameter = SACARGconvertFromInt(99);

  /**
   * Now, we call a SAC-function. Note here, that this consumes
   * both our SACargs. As a consequence, any reference to int_data_in
   * is illegal!! In fact, the memory of int_data_in might have been
   * released or reused!!
   */
  tutorialMod__addValue2( & vector_out,
                          vector_in,
                          parameter);

  /**
   * Now, we use the result of the last SaC function call as argument
   * for another SaC function call. However, since we want to use the
   * same SACarg twice, we have to use SACARGnewReference() in one of
   * the argument positions.
   */
  tutorialMod__addVectors2( & vector_out,
                            SACARGnewReference( vector_out),
                            vector_out);

  
  /**
   * Finally, we want to "transfer" the result of the last call back
   * into the C world. Note again, that this is a consuming operation,
   * i.e., the SACarg vector_out is being freed implicitly here.
   * Instead, we obtain int_data_out whose memory management is now
   * entirely in our control.
   */
  int_data_out = SACARGconvertToIntArray( vector_out);
  
  /**
   * Print the elements of the c array
   * and free the memory associated to the pointer
   */
  for(i=0; i<SMALLARRAY; i++)	
    printf("%d ", int_data_out[i]);
  printf("\n");

  free(int_data_out); 

  return(0);
}

