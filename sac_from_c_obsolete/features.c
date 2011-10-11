#include <stdio.h>
#include <stdlib.h>
#include "sac_cinterface.h"
#include "featuresMod_fix.h"
#include "featuresMod_gen.h"

/* problem sizes */
#define ARRAYSIZE 100
#define SMALLARRAY 20
#define MATRIXSIDE 10

#define WAIT_FOR_KEY()                            \
 { printf("*** press enter to continue ***\n"); \
   scanf("%c", &c); }


void VectorDemo()
{
  int *int_data;
  int value;
  int value2;
  int i;
  
  SAC_arg data_arg;
  SAC_arg result;
  
  printf(" --- Sum of vector elements ---\n\n");
  printf("now we are going to init a c-array with %d elements.\n", ARRAYSIZE);
  printf("and values from 10 to %d\n", ARRAYSIZE+10-1);

  int_data=(int*)malloc(ARRAYSIZE*sizeof(int));
  
  value2=0;
  for(i=0; i<ARRAYSIZE; i++) {
    int_data[i]=10+i;
    value2+=int_data[i];
  }
  
  printf("in the next step, we convert this vector to a SAC_arg.\n"
	 "this abstract datatype is used for calling a SAC function\n"
	 "from a c program.\n");
  data_arg = SAC_IntArray2Sac(SAC_CONSUME_ARG, int_data, 1, ARRAYSIZE);
  
  printf("Now we can check, if this SAC_arg contains valid data.\n"
	 "data_arg valid? %d\n\n", SAC_isValid(data_arg));
  printf("now we are going to call the SAC-function\n"
	 "calcSumOfVector in featuresMod_fix...");
  if(SAC_featuresMod_fix_calcSumOfVector_1_1(&result, data_arg)) {
    printf("some error occured, calling the function!\n\n");
    exit(1);
  }
  else {
    printf("function call successfull!\n");
  }
  
  printf("Because the SAC functions do refcounting on array types\n"
	 "it can consume data items.\n"
	 "Does the argument contain valid data anymore? %d\n",
	 SAC_isValid(data_arg));
  
  printf("Does the result contain valid data? %d\n", SAC_isValid(result));
  printf("So we convert this result to an integer an print it.\n");
  value = SAC_Sac2Int(result);
  printf("The computed result is: %d (c result: %d)\n\n\n", value, value2);
  printf("\n\n");
  printf(" --- Sum of vector elements finished ---\n\n");
}


void MatrixStructureDemo()
{
  int *int_matrix;
  int i;
  int j;

  SAC_arg result;
  SAC_arg parameter;
  
  printf(" --- Generating Matrix %dx%d with structure ---\n", 
	 MATRIXSIDE, MATRIXSIDE);
  
  /* create parameter */
  parameter = SAC_Int2Sac(42);
  printf("We call the SAC-function MatrixWithBorder from featuresMod_fix.\n"
	 "it generates a matrix with values 42 and a border of value 0\n");
  /* call SAC-function */
  if(SAC_featuresMod_fix_MatrixWithBorder_1_1(&result, parameter)) {
    printf("some error occured, calling the function!\n\n");
    exit(1);
  }
  else {
    printf("function call successfull!\n");
  }

  /* get result */
  printf("We get a resulting matrix. Does it contain valid data? %d\n",
	 SAC_isValid(result)); 
  int_matrix = SAC_Sac2IntArray(SAC_CONSUME_ARG, result);
  printf("Is the result valid any more after are consuming conversion? %d\n",
	 SAC_isValid(result));
  
  printf("\n\nThe result is:\n");
  /* print result */
  for(i=0; i<MATRIXSIDE; i++) {
    for(j=0; j<MATRIXSIDE; j++) {
      printf("%d\t", int_matrix[MATRIXSIDE*i+j]);
    }
    printf("\n");
  }
  printf("\n\n");
  printf(" --- Generating Matrix with structure finished ---\n\n");
  free(int_matrix);
}

void AnalyseVectorDemo()
{
  int *int_data;
  int i;

  SAC_arg data_arg;
  SAC_arg minval;
  SAC_arg maxval;
  SAC_arg sum;
  
  printf(" --- analyse vector elements ---\n\n");
  printf("now we are going to init a c-array with %d elements.\n", ARRAYSIZE);
  printf("and values from 1 to %d\n", ARRAYSIZE);
  int_data=(int*)malloc(ARRAYSIZE*sizeof(int));
  
  for(i=0; i<ARRAYSIZE; i++) {
    int_data[i]=i+1;
  }
  printf("in the next step we convert the int array into an SAC_arg\n"
	 "to use it as an argument.\n");
  /* convert parameter */
  data_arg = SAC_IntArray2Sac(SAC_CONSUME_ARG, int_data, 1, ARRAYSIZE);

  
  printf("now we are going to call the SAC-function\n"
	 "analyseVector in featuresMod_fix. This function has 3 results.\n");
  if(SAC_featuresMod_fix_analyseVector_3_1(&minval, &maxval, &sum, data_arg)) {
    printf("some error occured, calling the function!\n\n");
    exit(1);
  }
  else {
    printf("function call successfull!\n");
  }
  
  printf("the computed results are:\n");
  printf("\t min: %d\n", SAC_Sac2Int(minval));
  printf("\t max: %d\n", SAC_Sac2Int(maxval));
  printf("\t sum: %d\n\n\n", SAC_Sac2Int(sum));
  printf("\n");
  printf(" --- analyse vector elements finished ---\n\n");
}

void AddValue2VectorDemo()
{
  int i;
  int *int_data_in;
  int *int_data_out;
  int *int_data_out2;

  SAC_arg vector_out;
  SAC_arg vector_in;
  SAC_arg parameter;

  printf(" --- Add value to a refcounted vector  ---\n");
  printf("This demo uses the function addValue from featuresMod_gen. The\n"
	 "module contains a generic function. This function cannot be\n"
	 "exported to a c library. But in an additional spec file\n"
	 "all needed specialization are documented. These specializations\n"
	 "are created, optimized and exported.\n\n");
  printf("First we init an array with elements from 1 to %d.\n", SMALLARRAY);

  /* create parameter */
  int_data_in=(int*)malloc(SMALLARRAY*sizeof(int));
  for(i=0; i<SMALLARRAY; i++) {
    int_data_in[i]=i+1;
  }

  vector_in = SAC_IntArray2Sac(SAC_COPY_ARG, int_data_in, 1, SMALLARRAY);
  parameter = SAC_Int2Sac(99);

  printf("We have to increase the initial refcounter of the array type,\n"
	 "because it will be used two times as an argument of a\n"
	 "sac function.\n");
  printf("Refcount is set to %d.\n", SAC_SetRefcounter(vector_in, 2));

  /* call SAC-function */
  printf("Now we do a first function call (add 99)...");
  if(SAC_featuresMod_gen_addValue_1_2(&vector_out, vector_in, parameter)) {
    printf("some error occured, calling the function!\n\n");
    exit(1);
  }
  else {
    printf("function call successfull!\n");
  }
  printf("Refcount is now: %d\n", SAC_GetRefcounter(vector_in));

  /* get first result */
  int_data_out = SAC_Sac2IntArray(SAC_CONSUME_ARG, vector_out);
 
  parameter = SAC_Int2Sac(1);

  printf("Now we do the second function call (add 1)...");
  /* call SAC-function again */
  if(SAC_featuresMod_gen_addValue_1_2(&vector_out, vector_in, parameter)) {
    printf("some error occured, calling the function again!\n\n");
    exit(1);
  }
  else {
    printf("second function call successfull!\n");
  }
  printf("Refcount is now: %d\n", SAC_GetRefcounter(vector_in));

  int_data_out2 = SAC_Sac2IntArray(SAC_CONSUME_ARG, vector_out);
  
  /* print result */
  printf("\nAnd the computed results are:\n");
  for(i=0; i<SMALLARRAY; i++) {
    printf("%d.\t before: %d\t after 1: %d\t after 2: %d\n",
	   i, int_data_in[i], int_data_out[i], int_data_out2[i]);
  }
  printf("\n\n");
  printf(" --- Add value to a refcounted vector finished ---\n\n");
  free(int_data_in);
  free(int_data_out);
  free(int_data_out2);
}


void RefcountingDemo()
{
  int i;
  int *int_data_in;
  int *int_data_out;
  int *int_data_out2;

  SAC_arg vector_out;
  SAC_arg vector_in;
  SAC_arg parameter;

  printf(" --- Some refcount experiments ---\n");
  
  /* create parameter */
  int_data_in=(int*)malloc(SMALLARRAY*sizeof(int));
  printf("\n\nthe vector is: [");
  for(i=0; i<SMALLARRAY; i++) {
    int_data_in[i]=i+1;
    printf("%d ", i+1); 
  }
  printf("]\n");

  vector_in = SAC_IntArray2Sac(SAC_CONSUME_ARG, int_data_in, 1, SMALLARRAY);
  parameter = SAC_Int2Sac(99);

  printf("We call addValue from featuresMod_gen to add a constant to an\n"
	 "initialized vector with %d elements...\n", SMALLARRAY);
  /* call SAC-function */
  if(SAC_featuresMod_gen_addValue_1_2(&vector_out, vector_in, parameter)) {
    printf("some error occured, calling the function!\n\n");
    exit(1);
  }

  /* get first result */
  int_data_out = SAC_Sac2IntArray(SAC_COPY_ARG, vector_out);
  printf("\nthe vector is now: [");
  for(i=0; i<SMALLARRAY; i++) printf("%d ", int_data_out[i]);
  printf("]\n");

  printf("Now we want to use the the result as arguments of another function\n"
	 "that expect two vectors and adds them.\n"
	 "So we have to increase the refcounter.\n");
  /* reuse arg for next function call */
  vector_in=vector_out;

  printf("Increase refcounter of vector_in to %d.\n", SAC_SetRefcounter(vector_in, 2));
  /* call SAC-function again */
  if(SAC_featuresMod_gen_addVectors_1_2(&vector_out, vector_in, vector_in)) {
    printf("some error occured, calling the function again!\n\n");
    exit(1);
  }

  printf("Refcount is now: %d\n", SAC_GetRefcounter(vector_in));

  int_data_out2 = SAC_Sac2IntArray(SAC_CONSUME_ARG, vector_out);
  
  /* print result */
  printf("\n\nthe result is: [");
  for(i=0; i<SMALLARRAY; i++) printf("%d ", int_data_out2[i]);
  printf("]\n");
  printf("\n\n");
  free(int_data_out);
  free(int_data_out2);
  printf(" --- Some refcount experiments finished ---\n\n");
}


int main()
{
  char c;
  /* first of all init the SAC Runtime-System */
  SAC_InitRuntimeSystem();
  
  printf("Welcome to the SAC<->C interface demo!\n\n");
  printf("This demo program shows several features of the C-interface\n\n");

  VectorDemo();
  WAIT_FOR_KEY();

  MatrixStructureDemo();
  WAIT_FOR_KEY();
 
  AnalyseVectorDemo();
  WAIT_FOR_KEY();

  AddValue2VectorDemo();
  WAIT_FOR_KEY();

  RefcountingDemo();

  printf(" --- demonstration finished ---\n");

  SAC_FreeRuntimeSystem();
  return(0);
}
