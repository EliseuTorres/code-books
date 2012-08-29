/** @copyright (C) Andre Duarte Bueno @file List-16-3-TElipse.cpp */

#include <iostream>

#include "List-16-2-TElipse.h"

// Observe que a chamada expl�cita do construtor da classe-base TCirculo 
// � necess�ria porque TCirculo n�o tem um construtor default e 
// quero passar os atributos x,y e raio1
TElipse::TElipse (int x, int y, int raio1, int raio2):TCirculo (x, y, raio1), r2 (raio2)
{
}

void TElipse::Set (int x, int y, int raio1, int raio2)
{				// Herdou x e y de TPonto
  this->x = x;
  this->y = y;
  
  r1 = raio1;			// Herdou r1 de TCirculo
  r2 = raio2;			// Criou o atributo r2 na classe TElipse
}

void TElipse::Desenha ()
{
  TCirculo::Desenha ();		// Instru��o para desenhar o circulo;

  // Aqui voc� pode acrescentar instru��es referentes ao desenho da elipse
  std::cout << "\nTElipse: Coordenada r2=" << r2 << std::endl;
}
