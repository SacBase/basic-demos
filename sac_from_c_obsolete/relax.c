#include <stdio.h>
#include <stdlib.h>
#include "relaxMod_c.h"

int main()
{
  double *mat_in;
  double *mat_out;
  double sum;
  int i;
  int j;
  int size;
  int loops;

  SACarg *result;
  
#ifndef FIXED
  printf("Welcome to the SAC<->C interface demo!\n\n"
	 "this program does some relaxation on a matrix.\n\n"
	 "The relaxMod contains a generic relax function for a\n"
	 "2-dimensional matrix. It has been specialized for the\n"
	 "following shapes (see spec-file):\n"
	 "1. [10,10]\n"
	 "2. [90,90]\n"
	 "3. [400,400]\n"
	 "4. [1000,1000]\n\n"
	 "please select the matrix size (if you select an unsupported shape,\n"
	 "you will get an runtime error of the SAC-runtime-system)\n"
	 "size: ");
  scanf("%d", &size);
  printf("iterations: ");
  scanf("%d", &loops);
  printf("\nfirst we build up a matrix: [%d, %d]\n", size, size);
#else
  size = 1000;
  loops = 100;
#endif
  
  mat_in=(double*)malloc(size*size*sizeof(double));
  for(i=0; i<size; i++)
    for(j=0; j<size; j++)
      mat_in[i*size+j]=0;

  printf("setting up one inital element: at [0,1] = 500\n");
  mat_in[0*size+1]=500.0;

  printf("Calling SAC-function relax(matrix, iterations)...");
  relaxMod__relax2(&result,
			 SACARGconvertFromDoublePointer(
					     mat_in, 2, size, size),
			 SACARGconvertFromIntScalar(loops));
  mat_out = SACARGconvertToDoubleArray(result);
  printf("finished!\n");
  
  sum=0;
  for(i=0; i<size; i++)
    for(j=0; j<size; j++)
      sum+=mat_out[i*size+j];
  
  printf("calculating the resulting sum: %.10g\n\n", sum);
  
  printf(" --- demonstration finished ---\n");
  return(0);
}


