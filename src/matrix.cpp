#include <iostream>
#include <vector>
#include <cmath>
#include "../include/matrix.h"

using namespace std;

Matrix::Matrix(int rows, int cols)
{
  data.resize(rows, vector<double>(cols));
}

void Matrix::input()
{
  for (size_t i = 0; i < data.size(); i++)
  {
    for (size_t j = 0; j < data[i].size(); j++)
    {
      cout << "Enter element " << i + 1 << ", " << j + 1 << ": ";
      cin >> data[i][j];
    }
  }
}

void Matrix::swapRows(int row1, int row2)
{
  swap(data[row1], data[row2]);
}

void Matrix::multiplyRow(int row, double scalar)
{
  for (size_t i = 0; i < data[row].size(); i++)
  {
    data[row][i] *= scalar;
  }
}

void Matrix::addMultipleOfRow(int targetRow, int sourceRow, double scalar)
{
  for (size_t i = 0; i < data[targetRow].size(); i++)
  {
    data[targetRow][i] += scalar * data[sourceRow][i];
  }
}

void Matrix::upperTriangular()
{
  for (size_t i = 0; i < data.size(); i++)
  {
    for (size_t j = i + 1; j < data.size(); j++)
    {
      double factor = -data[j][i] / data[i][i];
      addMultipleOfRow(j, i, factor);
    }
  }
}

void Matrix::lowerTriangular()
{
  for (size_t i = 0; i < data.size(); i++)
  {
    for (size_t j = 0; j < i; j++)
    {
      double factor = -data[j][i] / data[i][i];
      addMultipleOfRow(j, i, factor);
    }
  }
}

void Matrix::print() const
{
  for (const auto &row : data)
  {
    for (double val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }
}