/*
 *
 * $Log$
 * Revision 3.2  2001/06/28 11:38:15  cg
 * automatically converted to new array type syntax.
 *
 * Revision 3.1  2000/11/20 18:07:16  sacbase
 * new release made
 *
 * Revision 1.1  2000/11/17 13:30:32  nmw
 * Initial revision
 *
 *
 */

ModuleSpec tutorialMod :

own:
{
functions:
  int[+] addValue(int[10] v, int value);
  int[+] addValue(int[20] v, int value);
  int[+] addValue(int[30] v, int value);

  int[+] addVectors(int[10] v1, int[10] v2);
  int[+] addVectors(int[20] v1, int[20] v2);
  int[+] addVectors(int[30] v1, int[30] v2);
}

