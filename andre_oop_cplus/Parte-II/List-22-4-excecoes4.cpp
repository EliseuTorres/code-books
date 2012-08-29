/** @copyright (C) Andre Duarte Bueno @file List-22-4-excecoes4.cpp */

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Teste
{
public:

  void f3 (int resp)
  {
    cout << "In�cio f3." << endl;
    if (resp == 1)
      throw (string ("Funcao 3"));
    cout << "Fim f3." << endl;
  }

  void f2 (int resp)
  {
    cout << "In�cio f2." << endl;
    f3 (resp);
    cout << "Fim f2." << endl;
  }

  void f1 (int resp)
  {
    cout << "In�cio f1." << endl;
    f2 (resp);
    cout << "Fim f1." << endl;
  }
};

int main ()
{
  int resp;

  cout << "\nDeseja executar sem exce��o (0) ou com exce��o (1):";
  cin >> resp;
  cin.get ();

  Teste obj;

  try
    {
      obj.f1 (resp);
    }
  catch (string s)
    {
      cout << "\nOcorreu Exce��o na fun��o :" << s << endl;
    }

  return 0;
}
