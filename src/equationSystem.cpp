#include <iostream>
#include <vector>
#include <cmath>
#include "../include/functions.h"
#include "../include/equationSystem.h"

using namespace std;

equationSystem::equationSystem(int rows, int cols) : Matrix(rows, cols) {}

void equationSystem::menu()
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
      clearScreen();
      solution = gaussSeidel();
      cout << "Solucion usando Gauss-Seidel:" << endl;
    }
    break;
    case 3:
    {
      clearScreen();
      solution = LuMethod();
      cout << "Solucion usando metodo de LU:" << endl;
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

vector<double> equationSystem::gaussianElimination()
{
  upperTriangular();

  vector<double> solution(data.size());

  for (int i = data.size() - 1; i >= 0; i--)
  {
    double sum = 0;

    for (int j = i + 1; j < data.size(); j++)
    {
      sum += data[i][j] * solution[j];
    }

    solution[i] = (data[i][data.size()] - sum) / data[i][i];
  }

  return solution;
}

vector<double> equationSystem::gaussSeidel()
{
  vector<double> x(data.size(), 0);
  vector<double> xOld(data.size(), 0);
  double error = 1;
  double tol;
  int maxIter = 100;
  int iter = 0;

  cout << "Ingrese la tolerancia: ";
  cin >> tol;

  while (error > tol && iter < maxIter)
  {
    for (int i = 0; i < data.size(); i++)
    {
      double sum = 0;

      for (int j = 0; j < data.size(); j++)
      {
        if (j != i)
        {
          sum += data[i][j] * x[j];
        }
      }

      x[i] = (data[i][data.size()] - sum) / data[i][i];
    }

    error = 0;

    for (int i = 0; i < data.size(); i++)
    {
      error += pow(x[i] - xOld[i], 2);
    }

    error = sqrt(error);
    xOld = x;
    iter++;
  }

  return x;
}

vector<double> equationSystem::LuMethod()
{
  vector<vector<double>> L(data.size(), vector<double>(data.size(), 0));
  vector<vector<double>> U(data.size(), vector<double>(data.size(), 0));
  vector<double> z(data.size(), 0);
  vector<double> x(data.size(), 0);

  for (int i = 0; i < data.size(); i++)
  {
    L[i][i] = 1;
  }

  for (int i = 0; i < data.size(); i++)
  {
    for (int j = i; j < data.size(); j++)
    {
      double sum = 0;

      for (int k = 0; k < i; k++)
      {
        sum += L[i][k] * U[k][j];
      }

      U[i][j] = data[i][j] - sum;
    }

    for (int j = i; j < data.size(); j++)
    {
      double sum = 0;

      for (int k = 0; k < i; k++)
      {
        sum += L[j][k] * U[k][i];
      }

      L[j][i] = (data[j][i] - sum) / U[i][i];
    }
  }

  for (int i = 0; i < data.size(); i++)
  {
    double sum = 0;

    for (int j = 0; j < i; j++)
    {
      sum += L[i][j] * z[j];
    }

    z[i] = (data[i][data.size()] - sum) / L[i][i];
  }

  for (int i = data.size() - 1; i >= 0; i--)
  {
    double sum = 0;

    for (int j = i + 1; j < data.size(); j++)
    {
      sum += U[i][j] * x[j];
    }

    x[i] = (z[i] - sum) / U[i][i];
  }

  return x;
}