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