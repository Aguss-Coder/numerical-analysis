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
      cout << "Ingrese la expression: ";
      cin >> expression;
      setExpression(expression);
      bisection();
    }
    break;
    case 2:
    {
      clearScreen();
      string expression;
      cout << "Ingrese la expression despejada: ";
      cin >> expression;
      setExpression(expression);
      fixedPoint();
    }
    break;
    case 3:
    {
      clearScreen();
      string expression;
      cout << "Ingrese la expression: ";
      cin >> expression;
      setExpression(expression);
      newtonRaphson();
    }
    break;
    case 4:
    {
      clearScreen();
      string expression;
      cout << "Ingrese la expression: ";
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

void Roots::calculateInterval(double a, double b, int maxRoots)
{
  double fa = f(expression, a);
  double fb = f(expression, b);
  int intervalsFound = 0;

  do
  {
    if (fa * fb < 0)
    {
      intervals.push_back(make_pair(a, b));
      intervalsFound++;
    }

    a = b;
    b += 0.1;
    fa = f(expression, a);
    fb = f(expression, b);
  } while (intervalsFound < maxRoots);

  if (intervals.size() == 0)
  {
    cout << "No se encontraron intervalos" << endl;
  }
}

void Roots::bisection()
{
  double a, b, tol;
  int maxRoots;

  cout << "Ingrese el intervalo [a, b]: ";
  cin >> a >> b;
  cout << "Ingrese la tolerancia: ";
  cin >> tol;
  cout << "Ingrese el numero maximo de raices: ";
  cin >> maxRoots;

  calculateInterval(a, b, maxRoots);

  for (int i = 0; i < intervals.size(); i++)
  {
    a = intervals[i].first;
    b = intervals[i].second;

    double fa = f(expression, a);
    double fb = f(expression, b);

    if (fa * fb > 0)
    {
      cout << "No se puede aplicar el metodo de biseccion" << endl;
      continue;
    }

    double c = (a + b) / 2;
    double fc = f(expression, c);

    while (abs(fc) > tol)
    {
      if (fa * fc < 0)
      {
        b = c;
        fb = fc;
      }
      else
      {
        a = c;
        fa = fc;
      }

      c = (a + b) / 2;
      fc = f(expression, c);
    }

    roots.push_back(c);
  }

  if (roots.size() == 0)
  {
    cout << "No se encontraron raices" << endl;
  }
  else
  {
    cout << "Raices encontradas: ";
    for (int i = 0; i < roots.size(); i++)
    {
      cout << roots[i] << " ";
    }
    cout << endl;
  }

  intervals.clear();
  roots.clear();
}

void Roots::fixedPoint()
{
  double x, error, v_ant, a, b, epsilon;

  cout << "Ingrese el intervalo [a, b]: ";
  cin >> a >> b;
  cout << "Ingrese el valor de epsilon (numero que maximiza la expression entre a y b): ";
  cin >> epsilon;
  cout << "ingrese el error maximo: ";
  cin >> error;

  if ((f(expression, a) < a || f(expression, a) > b) || (f(expression, b) < a || f(expression, b) > b))
  {
    cout << "La expression no converge" << endl;
  }
  else if (abs(fPrime(expression, epsilon)) > 1)
  {
    cout << "La expression no converge" << endl;
  }
  else
  {
    do
    {
      v_ant = x;
      x = f(expression, x);
    } while (abs(x - v_ant) > error);
  }
  cout << "La raiz es: " << x << endl;
}

void Roots::newtonRaphson()
{
  double x, error, v_ant;
  cout << "Ingrese el valor de x: ";
  cin >> x;
  cout << "Ingrese el valor del error: ";
  cin >> error;
  do
  {
    v_ant = x;
    x = x - (f(expression, x) / fPrime(expression, x));
  } while (abs(x - v_ant) > error);
  cout << "La raiz es: " << x << endl;
}

void Roots::secant()
{
  double error, x_i, x_mas_uno, x_menos_uno;
  cout << "Ingrese el valor de x_i: ";
  cin >> x_i;
  cout << "Ingrese el valor de x_i+1: ";
  cin >> x_mas_uno;
  cout << "Ingrese el valor del error: ";
  cin >> error;

  x_menos_uno = 0;
  do
  {
    x_mas_uno = x_i - (f(expression, x_i) * (x_menos_uno - x_i)) / (f(expression, x_menos_uno) - f(expression, x_i));
    x_menos_uno = x_i;
    x_i = x_mas_uno;
  } while (abs(x_mas_uno - x_menos_uno) > error);

  cout << "La raiz es: " << x_mas_uno << endl;
}