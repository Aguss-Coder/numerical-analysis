#ifndef METHODS_H
#define METHODS_H

#include <iostream>

using namespace std;

class Methods
{
private:
  string expression;

public:
  Methods();
  void setExpression(string);
  string getExpression();
  void bisection();
  void fixedPoint();
  void newtonRaphson();
  void secant();
};

#endif