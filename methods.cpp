#include <iostream>
#include "methods.h"
#include "include/functions.h"

using namespace std;

Methods::Methods()
{
  expression = "e^(-x) - x";
}

void Methods::setExpression(string expression)
{
  this->expression = expression;
}

string Methods::getExpression()
{
  return expression;
}

void Methods::bisection()
{
  double a, b, c;
  double errMax;

  cout << "Ingrese el intervalo [a, b]: ";
  cin >> a >> b;

  cout << "Ingrese el error maximo: ";
  cin >> errMax;

  c = (a + b) / 2;

  while (abs(f(expression, c)) > errMax)
  {
    if (f(expression, a) * f(expression, c) < 0)
    {
      b = c;
    }
    else
    {
      a = c;
    }

    c = (a + b) / 2;
  }

  cout << "Raiz: " << c << endl;
}

void Methods::fixedPoint()
{
  double x0, x1;
  double tol;
  int maxIter;

  cout << "Ingrese el valor inicial: ";
  cin >> x0;

  cout << "Ingrese la tolerancia: ";
  cin >> tol;

  cout << "Ingrese el numero maximo de iteraciones: ";
  cin >> maxIter;

  x1 = f(expression, x0);

  for (int i = 0; i < maxIter; i++)
  {
    cout << "Iteracion " << i + 1 << ": x = " << x1 << endl;

    if (abs(x1 - x0) < tol)
    {
      cout << "Raiz: " << x1 << endl;
      return;
    }

    x0 = x1;
    x1 = f(expression, x0);
  }

  cerr << "El metodo no converge" << endl;
}

void Methods::newtonRaphson()
{
  double x0, x1;
  double tol;
  int maxIter;
  int iterations = 0;

  cout << "Ingrese el valor inicial: ";
  cin >> x0;

  cout << "Ingrese la tolerancia: ";
  cin >> tol;

  cout << "Ingrese el numero maximo de iteraciones: ";
  cin >> maxIter;

  while (iterations < maxIter)
  {
    x1 = x0 - f(expression, x0) / fPrime(expression, x0);

    cout << "Iteracion " << iterations + 1 << ": x = " << x1 << endl;

    if (fabs(x1 - x0) < tol)
    {
      cout << "Raiz: " << x1 << endl;
      return;
    }

    x0 = x1;
    iterations++;
  }
}

void Methods::secant()
{
  double x0, x1, x2;
  double tol;
  int maxIter;

  cout << "Ingrese el valor inicial x0: ";
  cin >> x0;

  cout << "Ingrese el valor inicial x1: ";
  cin >> x1;

  cout << "Ingrese la tolerancia: ";
  cin >> tol;

  cout << "Ingrese el numero maximo de iteraciones: ";
  cin >> maxIter;

  for (int i = 0; i < maxIter; i++)
  {
    x2 = x1 - f(expression, x1) * (x1 - x0) / (f(expression, x1) - f(expression, x0));

    cout << "Iteracion " << i + 1 << ": x = " << x2 << endl;

    if (abs(x2 - x1) < tol)
    {
      cout << "Raiz: " << x2 << endl;
      return;
    }

    x0 = x1;
    x1 = x2;
  }

  cerr << "El metodo no converge" << endl;
}