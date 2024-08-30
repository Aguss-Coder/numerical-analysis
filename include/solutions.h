#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <iostream>
#include "matrix.h"

using namespace std;

class Solutions : public Matrix
{
public:
  Solutions(int, int);
  void menu();
  vector<double> gaussianElimination();
  vector<double> gaussSeidel();
  vector<double> LuMethod();
};

#endif