
#include <stdio.h>
#include <stdlib.h>
#include "sac_cinterface.h"
#include "usePhmMod.h"

int main()
{
  SAC_arg data;
  SAC_arg array;
  SAC_arg result;

  int val[]={1,2,3,4,5,6,7,8,9,0};
  
  /* first of all init the SAC Runtime-System */
  SAC_InitRuntimeSystem();

  printf("Welcome to the SAC<->C interface demo!\n\n");
  printf("today we use the private heap manager...\n\n");


  data=SAC_Int2Sac(10);
  array=SAC_IntArray2Sac(SAC_COPY_ARG, val, 1, 10);

  if(SAC_usePhmMod_myPhmTestFun_1_2(&result, array, data)) {
    printf("some error occured, calling the function!\n\n");
    exit(1);
  }
  else {
    printf("the result is: %d\n", SAC_Sac2Int(result));
  }


  printf(" --- demonstration finished ---\n");
  SAC_FreeRuntimeSystem();
  return(0);
}


