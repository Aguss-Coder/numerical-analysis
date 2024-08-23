#ifndef ROOTS_H
#define ROOTS_H

#include <iostream>

using namespace std;

class Roots
{
private:
  string expression;

public:
  Roots();
  void Menu();
  void setExpression(string);
  string getExpression();
  void bisection();
  void fixedPoint();
  void newtonRaphson();
  void secant();
};

#endif