/** @copyright (C) Andre Duarte Bueno @file List-E-7-funcao-randomico.cpp */

#include <iostream>
#include <iomanip>

using namespace std;

// A biblioteca abaixo, no C chama stdlib.h, no C++ chama cstdlib
// Fornece a fun��o srand e rand (n�mero randomico de C)
#include <cstdlib>

int main ()
{
  int semente;
  cout << "Entre com uma semente : ";
  cin >> semente;
  cin.get ();

  int min;
  cout << "Entre com o valor m�nimo (a) : ";
  cin >> min;
  cin.get ();

  int max;
  cout << "Entre com o valor m�ximo (b) : ";
  cin >> max;
  cin.get ();

  srand (semente);		// Passa a semente para o gerador de n�meros aleat�rios
  for (int i = 1; i <= 50; i++)	// Chama 50 vezes a fun��o rand
    {
      cout << setw (10) << (min + (rand () % (max - min + 1)));
      if (i % 5 == 0)
	cout << endl;
    }

  return 0;
}
