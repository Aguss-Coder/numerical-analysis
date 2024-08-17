#include <iostream>
#include "include/functions.h"

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

void clearScreen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
