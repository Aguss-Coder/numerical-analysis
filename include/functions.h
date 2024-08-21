#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include "exprtk.hpp"

using namespace std;

double f(const string &expression, double x);

double fPrime(const string &expression, double x);

void clearScreen();

#endif