/*
 *
 * $Log$
 * Revision 1.1  2000/11/17 13:30:32  nmw
 * Initial revision
 *
 *
 */

ModuleSpec tutorialMod :

own:
{
functions:
  int[] addValue(int[10] v, int value);
  int[] addValue(int[20] v, int value);
  int[] addValue(int[30] v, int value);

  int[] addVectors(int[10] v1, int[10] v2);
  int[] addVectors(int[20] v1, int[20] v2);
  int[] addVectors(int[30] v1, int[30] v2);
}
