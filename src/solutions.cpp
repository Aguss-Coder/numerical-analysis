#include <iostream>
#include <vector>
#include <cmath>
#include "../include/functions.h"
#include "../include/solutions.h"

using namespace std;

Solutions::Solutions(int rows, int cols) : Matrix(rows, cols) {}

void Solutions::menu()
{
  bool exit = false;

  while (!exit)
  {
    int option;
    vector<double> solution;

    cout << "Metodos para sistemas de ecuaciones" << endl;
    cout << "1. Eliminacion de Gauss" << endl;
    cout << "2. Gauss-Seidel" << endl;
    cout << "3. Metodo de LU" << endl;
    cout << "4. Salir" << endl;

    cout << "Opcion: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
      clearScreen();
      solution = gaussianElimination();
      cout << "Solucion usando eliminacion de Gauss:" << endl;
    }
    break;
    case 2:
    {
      // gaussSeidel();
    }
    break;
    case 3:
    {
      // LuMethod();
    }
    break;
    case 4:
    {
      exit = true;
    }
    break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }

    for (int i = 0; i < solution.size(); i++)
    {
      cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
  }
}

vector<double> Solutions::gaussianElimination()
{
  int n = data.size();

  for (int i = 0; i < n; i++)
  {
    // pivoteo parcial
    int maxRow = i;
    for (int j = i + 1; j < n; j++)
    {
      if (abs(data[j][i]) > abs(data[maxRow][i]))
      {
        maxRow = j;
      }
    }
    swapRows(i, maxRow);

    // convertir a triangular superior
    for (int j = i + 1; j < n; j++)
    {
      double factor = data[j][i] / data[i][i];
      addMultipleOfRow(j, i, -factor);
    }
  }

  // sustitución hacia atrás
  vector<double> solution(n);

  for (int i = n - 1; i >= 0; i--)
  {
    solution[i] = data[i][n] / data[i][i];
    for (int j = i - 1; j >= n; j--)
    {
      data[j][n] -= data[j][i] * solution[i];
    }
  }

  return solution;
}

vector<double> Solutions::gaussSeidel()
{
  return {};
}

vector<double> Solutions::LuMethod()
{
  return {};
}