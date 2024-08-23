#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class Matrix
{
protected:
  int rows;
  int cols;
  double **data;

public:
  Matrix();

  // elementary row operations
  void swapRows(int i, int j);
  void scaleRow(int i, double k);
  void addRows(int i, int j, double k);
};

#endif