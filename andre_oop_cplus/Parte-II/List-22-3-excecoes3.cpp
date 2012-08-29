/** @copyright (C) Andre Duarte Bueno @file List-22-3-excecoes3.cpp */

#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main ()					// Uma divis�o por zero com tratamento de exce��es
{
  float a = 3.0;
  float b;
  float c;

  try
    {
      cout << "Entre com b:";
      cin >> b;
      cin.get ();

      if (b == 0)
	throw string ("Divis�o por zero");	// out_of_range;

      c = a / b;
      cout << "c = a / b = " << c << endl;
    }

  catch (string msg)
    {
      cout << "Exce��o: " << msg << endl;
    }
  return 0;
}
