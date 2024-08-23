#ifndef CURVEFITTING_H
#define CURVEFITTING_H

#include <iostream>

using namespace std;

class CurveFitting
{
protected:
  int n;
  double *x;
  double *y;
  double *a;
  double *b;

public:
  CurveFitting();
  void linearRegression();
  void newtonPolynomial();
  void lagrangePolynomial();
  void segmentalInterpolation();
};

#endif