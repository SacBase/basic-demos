/*
 *
 * $Log$
 * Revision 1.2  2000/11/17 13:10:53  nmw
 * cvs header added
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "sac_cinterface.h"
#include "overloadMod.h"


#define SIZE 10

int main()
{
  int i;
  int j;
  double *array;
  int *vector;
  SAC_arg result;

  SAC_InitRuntimeSystem();
  
  /* init data */
  array = (double*)malloc(SIZE * SIZE * sizeof(double));
  for(i=0; i<SIZE; i++)
    for(j=0; j<SIZE; j++)
      array[i*SIZE+j] = i+j;

  vector = (int*)malloc(SIZE * sizeof(int));
  for(i=0; i<SIZE; i++)
      vector[i] = i;

  printf("c data has been initialized:\n"
	 "array:\n");
  for(i=0; i<SIZE; i++)
    {
      for(j=0; j<SIZE; j++)
	printf("%2.2f\t", array[i*SIZE+j]);
      printf("\n");
    }
  printf("\n\nvector:\n");
  for(i=0; i<SIZE; i++)
    printf("%2.2f\t", array[i]);
  printf("\n");

  /* call SAC function */

  printf("\nnow we call the sumFun in overloadMod with the array as argument.\n");
  SAC_overloadMod_sumFun_1_1(&result,
			  SAC_DoubleArray2Sac(SAC_CONSUME_ARG, array, 2, SIZE, SIZE));
  printf("the result for the array is %3.2f\n\n", SAC_Sac2Double(result));

  printf("\nand we call the same sumFun in overloadMod with a vector as argument.\n");
  SAC_overloadMod_sumFun_1_1(&result,
			  SAC_IntArray2Sac(SAC_CONSUME_ARG, vector, 1, SIZE));
  printf("the result for the vector is %d\n\n", SAC_Sac2Int(result));

  SAC_FreeRuntimeSystem();
  return(0);
}
