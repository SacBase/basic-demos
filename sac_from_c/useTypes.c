#include <stdio.h>
#include <stdlib.h>
#include "sac_cinterface.h"
#include "useTypesMod.h"

int main()
{
  SAC_arg list1;
  SAC_arg list2;
  SAC_arg result;

  /* first of all init the SAC Runtime-System */
  SAC_InitRuntimeSystem();

  printf("Welcome to the SAC<->C interface types demo!\n"
	 "************************************************\n\n");
  printf("this programm uses the user-defined datatype 'List'.\n"
	 "it creates two lists, fills in random numbers, \n"
	 "appends the lists to one list and calls printList\n"
	 "function to show the elements of the result.\n"
	 "the interal parts of the list-datatype is are not\n"
         "accessable from the c program.\n"
	 "SAC_arg's containing lists can only be used to call\n"
	 "other SAC functions, accepting lists as argument\n\n");

  printf("creating two empty lists...\n");

  SAC_useTypesMod_newList_1_0(&list1);
  SAC_SetRefcounter(list1, 2);
  SAC_useTypesMod_printList_0_1(list1);

  SAC_useTypesMod_newList_1_0(&list2);
  SAC_SetRefcounter(list2, 2);
  SAC_useTypesMod_printList_0_1(list2);


  printf("\nadd 10 or 5 random numbers to the lists...\n");

  SAC_useTypesMod_fillList_1_2(&list1, list1, SAC_Int2Sac(10));
  SAC_SetRefcounter(list1, 2);
  SAC_useTypesMod_printList_0_1(list1);

  SAC_useTypesMod_fillList_1_2(&list2, list2, SAC_Int2Sac(5));
  SAC_SetRefcounter(list2, 2);
  SAC_useTypesMod_printList_0_1(list2);


  printf("\nappend the two lists two one...\n");
  SAC_useTypesMod_appendList_1_2(&result, list1, list2);

  printf("\nprint the elements of the resulting list:\n");
  SAC_useTypesMod_printList_0_1(result);

  printf("\n --- demonstration finished ---\n");
  SAC_FreeRuntimeSystem();
  return(0);
}

