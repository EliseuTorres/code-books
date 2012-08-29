/** @copyright (C) Andre Duarte Bueno  @file  List-E-6-funcao-inline.cpp */
#include <iostream>
using  std::cout;
using  std::cin;
using  std::endl;

//Declara��o da fun��o em linha
inline double
cubo (const double lado)
{
  return lado * lado * lado;
}

int main ()
{
  cout << "Entre com a dimens�o do cubo:  ";
  double dim;
  cin >> dim;
  cin.get ();
  cout << "Volume do cubo " << dim << " � " << cubo (dim) << endl;

  return 0;
}
