/* *******  c program using a SAC module exported as a c library ****** */
#include <stdlib.h>
#include <stdio.h>
#include "sac_cinterface.h"
#include "tutorialMod.h"

#define SMALLARRAY 20

int main()
{
  int i;
  int *int_data_in;
  int *int_data_out;

  SAC_arg vector_out;
  SAC_arg vector_in;
  SAC_arg parameter;

  SAC_InitRuntimeSystem();
  
  /* init data */
  int_data_in=(int*)malloc(SMALLARRAY*sizeof(int));
  for(i=0; i<SMALLARRAY; i++) {int_data_in[i]=i+1;}

  /* convert c data to abstract datatype SAC_arg */
  vector_in = SAC_IntArray2Sac(SAC_CONSUME_ARG, int_data_in, 1, SMALLARRAY);
  parameter = SAC_Int2Sac(99);

  /* call to SAC-function */
  if(SAC_tutorialMod_addValue_1_2(&vector_out, vector_in, parameter)) {
    printf("some error occured, calling the function!\n\n");
    exit(1);
  }

  /* reuse arg for next function call */
  vector_in = vector_out;

  /* increase refcounter to use argument twice */
  SAC_SetRefcounter(vector_in, 2);

  /* call to SAC-function */
  if(SAC_tutorialMod_addVectors_1_2(&vector_out, vector_in, vector_in)) {
    printf("some error occured, calling the function!\n\n");
    exit(1);
  }
  
  /* convert and consume the result */
  int_data_out = SAC_Sac2IntArray(SAC_CONSUME_ARG, vector_out);
  
  /* print result */
  /* print elements of c array */
  for(i=0; i<SMALLARRAY; i++)	
    printf("%d ", int_data_out[i]);
  printf("\n");

  free(int_data_out); 
  SAC_FreeRuntimeSystem();
  return(0);
}
