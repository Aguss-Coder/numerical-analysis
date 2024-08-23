#include <iostream>
#include "../include/matrix.h"

using namespace std;

Matrix::Matrix()
{
  rows = 0;
  cols = 0;
  data = NULL;
}

void Matrix::swapRows(int i, int j)
{
  double *temp = data[i];
  data[i] = data[j];
  data[j] = temp;
}

void Matrix::scaleRow(int i, double k)
{
  for (int j = 0; j < cols; j++)
  {
    data[i][j] *= k;
  }
}

void Matrix::addRows(int i, int j, double k)
{
  for (int l = 0; l < cols; l++)
  {
    data[i][l] += k * data[j][l];
  }
}