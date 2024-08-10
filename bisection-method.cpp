#include <iostream>
#include <string>
#include "include/exprtk.hpp"
#include <cmath>

using namespace std;

double f(const string &expression, double x)
{
  typedef exprtk::symbol_table<double> symbol_table_t;
  typedef exprtk::expression<double> expression_t;
  typedef exprtk::parser<double> parser_t;

  symbol_table_t symbol_table;
  symbol_table.add_variable("x", x);
  symbol_table.add_constant("e", exp(1));
  symbol_table.add_constants();

  expression_t expr;
  expr.register_symbol_table(symbol_table);

  parser_t parser;
  if (!parser.compile(expression, expr))
  {
    cout << "Error: " << parser.error() << endl;
    return 0.0;
  }

  return expr.value();
}

int main(int argc, char const *argv[])
{
  double a, b, c;
  double errMax;
  string expression;

  cout << "Ingrese la funcion: ";
  cin >> expression;

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

  return 0;
}
