ModuleSpec relaxMod:

own:
{
functions:
  double[+] relax(double[10,10] A, int steps);
  double[+] relax(double[90,90] A, int steps);
  double[+] relax(double[400,400] A, int steps);
  double[+] relax(double[1000,1000] A, int steps);
}
