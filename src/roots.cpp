#include <iostream>
#include "../include/roots.h"
#include "../include/functions.h"

using namespace std;

Roots::Roots()
{
  expression = "e^(-x) - x";
}

void Roots::Menu()
{
  bool exit = false;

  while (!exit)
  {
    int option;

    cout << "Metodos numericos" << endl;
    cout << "1. Biseccion" << endl;
    cout << "2. Punto fijo" << endl;
    cout << "3. Newton-Raphson" << endl;
    cout << "4. Secante" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
      clearScreen();
      string expression;
      cout << "Ingrese la funcion: ";
      cin >> expression;
      setExpression(expression);
      bisection();
    }
    break;
    case 2:
    {
      clearScreen();
      string expression;
      cout << "Ingrese la funcion despejada: ";
      cin >> expression;
      setExpression(expression);
      fixedPoint();
    }
    break;
    case 3:
    {
      clearScreen();
      string expression;
      cout << "Ingrese la funcion: ";
      cin >> expression;
      setExpression(expression);
      newtonRaphson();
    }
    break;
    case 4:
    {
      clearScreen();
      string expression;
      cout << "Ingrese la funcion: ";
      cin >> expression;
      setExpression(expression);
      secant();
    }
    break;
    case 5:
      exit = true;
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
  }
}

void Roots::setExpression(string expression)
{
  this->expression = expression;
}

string Roots::getExpression()
{
  return expression;
}

void Roots::bisection()
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

void Roots::fixedPoint()
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

void Roots::newtonRaphson()
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

void Roots::secant()
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