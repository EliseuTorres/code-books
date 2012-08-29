/** @copyright (C) Andre Duarte Bueno 
    @file List-11-1-funcao-por-valor-referencia-ponteiro.cpp */

#include <iostream>

using std::cout;
using std::endl;

class Teste
{

public:
  int  Soma_Valor (int, int);
  int  Soma_Referencia (int &, int &);
  int  Soma_Ponteiro (int *, int *);
  int  Soma_ReferenciaPonteiro (int *&, int *&);
};

// Defini��o de um m�todo por valor (int)
int Teste::Soma_Valor (int x, int y)
{
  int soma = x + y;

  x = 5;			// in�til, usado apenas para mostrar que x,y
  y = 7;			// externos n�o s�o alterados
  return soma;
}

// Defini��o de um m�todo com refer�ncia (int &)
int Teste::Soma_Referencia (int &x, int &y)
{
  int soma = x + y;

  x = 55;
  y = 77;
  return soma;
}

// Defini��o de um m�todo por ponteiro (int*)
int Teste::Soma_Ponteiro (int *x, int *y)
{
  int soma = *x + *y;

  *x = 555;
  *y = 777;
  return soma;
}

// Defini��o de um m�todo refer�ncia para um ponteiro (int*&)
int Teste::Soma_ReferenciaPonteiro (int *&x, int *&y)
{
  int soma = *x + *y;

  *x = 5555;
  *y = 7777;
  return soma;
}

int main ()
{
  int a = 1;
  int b = 2;

  cout << "a=" << a << " b=" << b << endl;

  Teste obj;

  cout << "Soma = " << obj.Soma_Valor (a, b) << endl;
  cout << "Ap�s chamar Soma_Valor(a,b); a = " << a << ", b = " << b << endl;
  cout << "Soma = " << obj.Soma_Referencia (a, b) << endl;
  cout << "Ap�s chamar Soma_Referencia(a,b); a = " << a << ", b = " << b <<    endl;
  cout << "Soma = " << obj.Soma_Ponteiro (&a, &b) << endl;
  cout << "Ap�s chamar Soma_Ponteiro(&a,&b); a = " << a << ", b = " << b <<    endl;

  int *pa = &a;
  int *pb = &b;
  cout << "Soma = " << obj.Soma_ReferenciaPonteiro (pa, pb) << endl;
  cout << "Ap�s chamar Soma_ReferenciaPonteiro(pa,pb); a="  << a << ", b=" << b << endl;

  return 0;
}
