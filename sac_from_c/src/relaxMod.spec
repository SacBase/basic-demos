/*
 *
 * $Log$
 * Revision 3.1  2000/11/20 18:07:15  sacbase
 * new release made
 *
 * Revision 1.1  2000/11/17 13:29:43  nmw
 * Initial revision
 *
 *
 */

ModuleSpec relaxMod :

own:
{
functions:
  double[] relax(double[10,10] A, int steps);
  double[] relax(double[90,90] A, int steps);
  double[] relax(double[400,400] A, int steps);
  double[] relax(double[1000,1000] A, int steps);
}

