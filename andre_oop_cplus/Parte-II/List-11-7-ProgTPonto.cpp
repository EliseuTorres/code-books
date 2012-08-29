/** @copyright (C) Andre Duarte Bueno @file List-11-7-ProgTPonto.cpp */

#include <iostream>

#include "List-11-5-TPonto.h"

using namespace std;

// Exemplo de cria��o e uso do objeto TPonto
int main ()
{
  int x = 5;
  int y = 4;
  {
    TPonto ponto;		// Cria objeto do tipo TPonto com nome ponto
    ponto.Set (x, y);		// Chama m�todo Set do objeto ponto
    ponto.Desenha ();
  }				// Sai de escopo e detr�i o objeto ponto

  // Chama m�todo est�tico e p�blico, 
  // observe que n�o precisa de um objeto
  cout << "Contador = " << TPonto::GetContador () << endl;
  return 0;
}
