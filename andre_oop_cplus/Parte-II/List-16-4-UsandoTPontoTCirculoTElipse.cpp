/** @copyright (C) Andre Duarte Bueno 
    @file List-16-4-UsandoTPontoTCirculoTElipse.cpp */

#include <iostream>
using namespace std;

// #include "List-11-5-TPonto.h"
// #include "List-15-1-TCirculo.h"
#include "List-16-2-TElipse.h"

int main ()
{
  int x = 5;
  int y = 4;

  {
    cout << "\n----------------Testando TPonto:" << endl;
    TPonto ponto;		// Cria objeto do tipo TPonto com nome ponto
    ponto.Set (x, y);		// Chama m�todo Set do objeto ponto
    ponto.Desenha ();		// Chama m�todo Desenha do objeto ponto
  }				// Sai de escopo e detr�i objeto ponto

  cout << "\n----------------Testando TPonto din�mico:" << endl;

  TPonto *ptr = NULL;		// Cria ponteiro para TPonto

  ptr = new TPonto;		// Cria objeto do tipo TPonto 

  x = 6;
  y = 7;

  ptr->Set (x, y);		// Chama m�todo Set do objeto usando ptr 
  ptr->Desenha ();
  int xx = ptr->Getx ();
  delete ptr;

  // Chama m�todo est�tico da classe TPonto, observe que n�o precisa de um objeto
  // Utiliza o nome da classe seguido do operador de resolu��o de escopo.
  cout << "Contador = " << TPonto::GetContador () << endl;

  cout << "\n----------------Testando TCirculo:" << endl;
  TCirculo c (55, 44, 33);
  c.Desenha ();

  cout << "\n----------------Testando TElipse:" << endl;
  TElipse e (555, 444, 333, 222);
  e.Desenha ();

  return 0;
}
