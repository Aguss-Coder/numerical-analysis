#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
protected:
  vector<vector<double>> data;

public:
  Matrix(int, int);

  void input();

  // elementary row operations
  void swapRows(int, int);
  void multiplyRow(int, double);
  void addMultipleOfRow(int, int, double);
  void print() const;
};

#endif