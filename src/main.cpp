#include <iostream>
#include "../include/roots.h"
#include "../include/equationSystem.h"
#include "../include/functions.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Roots roots;
  bool exit = false;

  while (!exit)
  {
    int option;

    cout << "Analisis numerico" << endl;
    cout << "1. Raices de ecuaciones" << endl;
    cout << "2. Sistema de ecuaciones" << endl;
    cout << "3. Regresion lineal" << endl;
    cout << "4. Interpolacion" << endl;
    cout << "5. Diferenciacion e integracion numerica" << endl;
    cout << "6. Ecuaciones diferenciales" << endl;
    cout << "7. Salir" << endl;

    cout << "Opcion: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
      clearScreen();
      roots.Menu();
      break;
    }
    case 2:
    {
      int n;
      clearScreen();

      cout << "Numero de ecuaciones: ";
      cin >> n;

      equationSystem EquationSystem(n, n + 1);
      EquationSystem.input();

      EquationSystem.menu();
      break;
    }
    case 3:
    {
      clearScreen();
      cout << "Regresion lineal" << endl;
      break;
    }
    case 4:
    {
      clearScreen();
      cout << "Interpolacion" << endl;
      break;
    }
    case 5:
    {
      clearScreen();
      cout << "Diferenciacion e integracion numerica" << endl;
      break;
    }
    case 6:
    {
      clearScreen();
      cout << "Ecuaciones diferenciales" << endl;
      break;
    }
    case 7:
    {
      exit = true;
      break;
    }
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
  }

  return 0;
}
