/*
 *
 * $Log$
 * Revision 3.1  2000/11/20 18:07:15  sacbase
 * new release made
 *
 * Revision 1.1  2000/11/17 13:29:07  nmw
 * Initial revision
 *
 *
 */

ModuleSpec overloadMod :
own:
{
functions:
  int sumFun(int[1] a);
  int sumFun(int[5] a);
  int sumFun(int[10] a);
  int sumFun(int[5,5,5] a);

  double sumFun(double[2] a);
  double sumFun(double[20] a);
  double sumFun(double[200] a);
  double sumFun(double[10,10] a);
}

