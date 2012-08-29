/** @copyright (C) Andre Duarte Bueno @file List-B-1-const.cpp */

#include <iostream>
#include <iomanip>

using namespace std;

// Cria��o de objeto constante (n�o pode mudar), global (vis�vel em todo programa)
const double PI = 3.14159265358979;

int main ()
{
  // Cria��o de objeto constante (n�o pode mudar), local (vis�vel dentro de main)
  const float PI = static_cast < float >(::PI);
  cout << setprecision (20) << "Conte�do de PI local <float> = " << PI << endl;
  cout << setprecision (20) << "Conte�do de PI global�<double> = " << ::PI << endl;

  return 0;
}
