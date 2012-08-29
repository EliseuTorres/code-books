/** @copyright (C) Andre Duarte Bueno @file List-E-3-funcao.cpp */

#include <iostream>

using namespace std;

int cubo (int y);		// Declara��o da fun��o

int main ()
{
  int min, max;
  cout << "Entre com o intervalo (valor m�nimo e m�ximo)(ex: 3 e 10):";
  cin >> min >> max;
  cin.get ();
  for (int x = min; x <= max; x++)
    cout << "cubo de (" << x << ") = " << cubo (x) << endl;
  return 0;
}

// Defini��o da fun��o: 
// retorno_da_fun��o Nome_da_fun��o (par�metros) {corpo_da_fun��o}
int cubo (int y)
{
  return y * y * y;
}
