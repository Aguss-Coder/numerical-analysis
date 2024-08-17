#include <iostream>
#include "exprtk.hpp"

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

double fixedPointMethod(const string &expression, double initialGuess, double tolerance, int maxIterations)
{
  double x0 = initialGuess;
  double x1;
  int iterations = 0;

  while (iterations < maxIterations)
  {
    x1 = f(expression, x0);

    cout << "Iteracion " << iterations + 1 << ": x = " << x1 << endl;

    if (fabs(x1 - x0) < tolerance)
    {
      return x1;
    }

    x0 = x1;
    iterations++;
  }

  cerr << "El metodo no converge" << endl;
  return x1;
}

int main(int argc, char const *argv[])
{
  string expression = "e^(-x)";
  double initialGuess = 0.5;
  double tolerance = 1e-6;
  int maxIterations = 100;

  double root = fixedPointMethod(expression, initialGuess, tolerance, maxIterations);

  cout << "Raiz: " << root << endl;

  return 0;
}
