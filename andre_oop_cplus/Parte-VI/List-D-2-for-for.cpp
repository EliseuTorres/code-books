/** @copyright (C) Andre Duarte Bueno @file List-D-2-for-for.cpp */

#include <iostream>

using namespace std;

int main ()
{
  int x, y;

  cout << "Entre com dois n�meros inteiros positivos (a espa�o b enter): ";
  cin >> x >> y;
  cin.get ();

  for (int i = 1; i <= y; i++)
    {
      for (int j = 1; j <= x; j += 1)
	cout << '.';
      cout << endl;
    }

  return 0;
}
