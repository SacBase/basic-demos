/*
 *
 * $Log$
 * Revision 3.1  2000/11/20 18:07:05  sacbase
 * new release made
 *
 * Revision 1.2  2000/11/17 13:07:34  nmw
 * CVS header added
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "sac_cinterface.h"
#include "useTwoLibsMod1.h"
#include "useTwoLibsMod2.h"

/* problem sizes */
#define SMALLARRAY 20

int main()
{
  int i;
  int *int_data_in;
  int *int_data_out;

  SAC_arg vector_out;
  SAC_arg vector_in;
  SAC_arg parameter;
  SAC_arg param_out;
  
  /* first of all init the SAC Runtime-System */
  SAC_InitRuntimeSystem();
  
  printf("Welcome to the SAC<->C interface demo!\n\n");
  printf("-- calling functions from 2 modules, that use the same global objects --\n");
  
  /* create parameter */
  int_data_in=(int*)malloc(SMALLARRAY*sizeof(int));
  for(i=0; i<SMALLARRAY; i++) {
    int_data_in[i]=i+1;
  }

  vector_in = SAC_IntArray2Sac(SAC_COPY_ARG, int_data_in, 1, SMALLARRAY);
  parameter = SAC_Int2Sac(99);
 
  /* call SAC-function */
  if(SAC_useTwoLibsMod1_fun_1_2(&vector_out, vector_in, parameter)) {
    printf("some error occured, calling the function!\n\n");
    exit(1);
  }
  else {
    printf("function call successfull!\n");
  }

  /* get first result */
  int_data_out = SAC_Sac2IntArray(SAC_CONSUME_ARG, vector_out);
 
  /* print result */
  for(i=0; i<SMALLARRAY; i++) {
    printf("%d.\t before: %d\t after 1: %d\n",
	   i, int_data_in[i], int_data_out[i]);
  }
  printf("\n\n");

  printf("Now use second library:\n");
  if(SAC_useTwoLibsMod2_fun_1_1(&param_out, parameter)) {
    printf("some error occured, calling the function again!\n\n");
    exit(1);
  }
  else {
    printf("function call successfull!\n");
  }

  printf("Value before %d and after %d\n",SAC_Sac2Int(parameter), SAC_Sac2Int(param_out));
  
  printf(" --- demonstration finished ---\n");

  free(int_data_in);
  free(int_data_out);
  
  SAC_FreeRuntimeSystem();
  return(0);
}


