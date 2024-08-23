#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <iostream>
#include "matrix.h"

using namespace std;

class Solutions : public Matrix
{
public:
  Solutions();
  void gaussianElimination();
  void gaussSeidel(double tol, int maxIter);
  void LuMethod();
};

#endif