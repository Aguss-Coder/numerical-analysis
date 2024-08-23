#ifndef NUMERICALDIFFERENTIATION_H
#define NUMERICALDIFFERENTIATION_H

#include <iostream>

using namespace std;

class NumericalDifferentiation
{
protected:
  int n;
  double *x;
  double *y;
  double *dydx;

public:
  NumericalDifferentiation();
  void threePointFormula();
  void fivePointFormula();
};

#endif