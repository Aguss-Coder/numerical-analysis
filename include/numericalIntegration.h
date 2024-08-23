#ifndef NUMERICALINTEGRATION_H
#define NUMERICALINTEGRATION_H

#include <iostream>

using namespace std;

class NumericalIntegration
{
protected:
  int n;
  double *x;
  double *y;
  double *dydx;

public:
  NumericalIntegration();
  void trapezoidalRule();
  void simpsonsRule();
};

#endif