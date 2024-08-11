#include <iostream>
#include "methods.h"
#include "include/functions.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Methods methods;
  bool exit = false;

  while (!exit)
  {
    int option;

    cout << "Metodos numericos" << endl;
    cout << "1. Biseccion" << endl;
    cout << "2. Newton-Raphson" << endl;
    cout << "3. Secante" << endl;
    cout << "4. Salir" << endl;
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
      methods.setExpression(expression);
      methods.bisection();
    }
    break;
    case 2:
      // methods.newtonRaphson();
      break;
    case 3:
      // methods.secant();
      break;
    case 4:
      exit = true;
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
  }

  return 0;
}
