/** @copyright (C) Andre Duarte Bueno @file List-16-6-TCirculoElipse.cpp */

#include "List-16-5-TCirculoElipse.h"

TCirculoElipse::TCirculoElipse (int xc, int yc, int rc, int r1e, int r2e)
{
  // Utiliza o operador de resolu��o de escopo para acessar m�todo ancestral
  TCirculo::Set (xc, yc, rc);

  TElipse::Set (xc, yc, r1e, r2e);
}

void TCirculoElipse::Set (int xc, int yc, int rc, int r1e, int r2e)
{
  TCirculo::Set (xc, yc, rc);

  TElipse::Set (xc, yc, r1e, r2e);
}

// Construtor de convers�o. Como o circulo n�o preenche totalmente o TCirculoElipse
// e quero construir um TCirculoElipse a partir de um TCirculo, 
// crio um construtor de convers�o
TCirculoElipse (TCirculo & circulo)
{
  TCirculo::Set (circulo);

  // Observe abaixo que passa circulo.r1 como r1 e r2 da TElipse
  TElipse::Set (circulo.x, circulo.y, circulo.r1, circulo.r1);
}

// Implementa��o de Desenha, uso do operador de resolu��o de escopo 
// para identificar o m�todo da classe-base
void TCirculoEPonto::Desenha ()
{
  TElipse::Desenha ();		// Desenha a elipse 

  TCirculo::Desenha ();		// Desenha o c�rculo
}
