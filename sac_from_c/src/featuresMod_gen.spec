/*
 *
 * $Log$
 * Revision 3.2  2001/06/28 11:38:12  cg
 * automatically converted to new array type syntax.
 *
 * Revision 3.1  2000/11/20 18:07:13  sacbase
 * new release made
 *
 * Revision 1.1  2000/11/17 13:28:16  nmw
 * Initial revision
 *
 *
 */

ModuleSpec featuresMod_gen :

own:
{
functions:
  int[+] addValue(int[100] v, int value);
  int[+] addValue(int[50] v, int value);
  int[+] addValue(int[20] v, int value);
  int[+] addValue(int[2] v, int value);

  int[+] addVectors(int[10] v1, int[10] v2);
  int[+] addVectors(int[20] v1, int[20] v2);
  int[+] addVectors(int[30] v1, int[30] v2);
}

