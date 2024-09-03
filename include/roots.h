#ifndef ROOTS_H
#define ROOTS_H

#include <iostream>
#include <vector>

using namespace std;

class Roots
{
private:
  string expression;
  vector<double> roots;
  vector<pair<double, double>> intervals;

public:
  Roots();
  void Menu();
  void setExpression(string);
  string getExpression();
  void calculateInterval(double, double, int);
  void bisection();
  void fixedPoint();
  void newtonRaphson();
  void secant();
};

#endif