#include <stdio.h>
#include <stdlib.h>
#include "sac_cinterface.h"
#include "IntStack.h"
#include "objectsMod.h"

#define LOOPS 20

int main()
{
  int i;
  SAC_arg data;
  SAC_arg stack;
  
  /* first of all init the SAC Runtime-System */
  SAC_InitRuntimeSystem();
  
  printf("Welcome to the SAC<->C interface demo!\n\n");
  printf("today we use the IntStack Class...\n\n");

  printf("\nthe global stack is:\n");
  if(SAC_IntStack_print_0_0()) {
    printf("some error occured, calling the print function!\n\n");
    exit(1);
  }
  
  printf("\n\nnow we fill the stack with data...\n");
  for(i=1; i<=LOOPS; i++) {
    data = SAC_Int2Sac(i);
    if(SAC_IntStack_push_0_1(data)) {
      printf("some error occured, calling the push function!\n\n");
      exit(1);
    }
    else {
      printf("pushed %d to gobal stack!\n", i);
    }
  }

  printf("\nand now the global stack is:\n");
  if(SAC_IntStack_print_0_0()) {
    printf("some error occured, calling the print function!\n\n");
    exit(1);
  }

  /* now again with an own stack */
  printf("\n****************************************************************\n"
	 "now we create an own stack and pop 10 items\n"
	 "from the global stack and push them to our new\n"
	 "own stack.");
  if(SAC_IntStack_create_stack_1_0(&stack)) {
    printf("some error occured, calling the create function!\n\n");
    exit(1);
  }
  /* increase refcounter for multiple stack usage */
  SAC_SetRefcounter(stack, 1000);

  printf("\nthe new stack is:\n");
  if(SAC_IntStack_print_0_1(stack)) {
    printf("some error occured, calling the print function!\n\n");
    exit(1);
  }
  
  for(i=0; i<10; i++) {
    if(SAC_IntStack_pop_1_0(&data)) {
      printf("some error occured, calling the pop function!\n\n");
      exit(1);
    }
    else {
      printf("pop %d from gobal stack ... ", SAC_Sac2Int(data));
    }

    if(SAC_IntStack_push_0_2(stack, data)) {
      printf("some error occured, calling the push function!\n\n");
      exit(1);
    }
    else {
      printf("and push %d to own stack\n", SAC_Sac2Int(data));
    }
  }

  printf("\n**************************************************************\n");
  printf("the global stack is:\n");
  if(SAC_IntStack_print_0_0()) {
    printf("some error occured, calling the print function!\n\n");
    exit(1);
  }  
  printf("\n\nand the own stack is:\n");
  if(SAC_IntStack_print_0_1(stack)) {
    printf("some error occured, calling the print function!\n\n");
    exit(1);
  }  

  printf("\n\n**************************************************************\n");
  printf("now we access the global stack from a second module.\n"
	 "the functions pops of all elements and returns the last one.\n\n");


  if(SAC_objectsMod_GetLastItemFromStack_1_0(&data)) {
    printf("some error occured, calling the print function!\n\n");
    exit(1);
  }

  printf("this element of the global stack is: %d\n", SAC_Sac2Int(data));

  printf(" --- demonstration finished ---\n");

  SAC_FreeRuntimeSystem();
  return(0);
}

