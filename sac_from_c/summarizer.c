#include <stdio.h>
#include <stdlib.h>
#include "cwrapper.h"

int *SecretCFunctionThatProducesAVector(int size)
{
  int *vector = malloc( sizeof(int) * size);
  int cnt;

  for (cnt = 0; cnt < size; cnt++)
  {
    vector[cnt] = cnt+1;
  }

  return vector;
}

int main( int argc, char *argv[])
{
  int *vector;
  int *result;
  SACarg *theVector, *theResult;
 
  vector = SecretCFunctionThatProducesAVector( 100);

  theVector = SACARGconvertFromIntPointer( vector, 1, 100);

  // SAC_InitRuntimeSystem( argv, argc);
  Sum__sum1( &theResult, theVector);
  // SAC_FreeRuntimeSystem();

  result = SACARGconvertToIntArray( theResult);

  printf( "The result is %d.\n", *result);

  return 0;
}




