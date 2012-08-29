/** @copyright (C) Andre Duarte Bueno @file List-13-1-ProgTPontoDinamico.cpp */

#include <iostream>

#include "List-11-5-TPonto.h"

// Exemplo de cria��o e uso do objeto TPonto
int main()
{
  int x = 5;
  int y = 4;

  TPonto *ptr = NULL;		// Cria ponteiro para objeto do tipo TPonto

  // Cria objeto do tipo TPonto, e coloca endere�o em ptr. 
  ptr = new TPonto;             // Deveria testar a aloca��o
  
  ptr->Set(x, y);		// Chama m�todo Set do objeto ptr
  ptr->Desenha();		// Chama m�todo  Desenha
  int xx = ptr->Getx();

  return 0;
}
