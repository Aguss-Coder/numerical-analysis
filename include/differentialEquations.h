#ifndef DIFFERENTIALEQUATIONS_H
#define DIFFERENTIALEQUATIONS_H

#include <iostream>

using namespace std;

// ordinary differential equations

class DifferentialEquations
{
protected:
  int n;
  double *x;
  double *y;
  double *dydx;

public:
  DifferentialEquations();
  void eulerMethod();
  void HeunMethod();
  void rungeKuttaMethod();
  void predictorCorrectorMethod();
};

#endif