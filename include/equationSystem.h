#ifndef equationSystem_H
#define equationSystem_H

#include <iostream>
#include "matrix.h"

using namespace std;

class equationSystem : public Matrix
{
public:
  equationSystem(int, int);
  void menu();
  vector<double> gaussianElimination();
  vector<double> gaussSeidel();
  vector<double> LuMethod();
};

#endif