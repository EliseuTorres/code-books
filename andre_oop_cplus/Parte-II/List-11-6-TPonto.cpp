/** @copyright (C) Andre Duarte Bueno @file List-11-6-TPonto.cpp */

#include <iostream>

#include "List-11-5-TPonto.h" 

int   TPonto::contador = 0;

void TPonto::Set (TPonto & p)
{
  x = p.Getx ();
  y = p.Gety ();
}

// Defini��o de m�todo inline
int      TPonto::Gety () const 
{
  return y;
}

int TPonto::GetContador ()
{
  return contador;
}

void TPonto::Desenha ()
{
  std::cout << "\nTPonto: Coordenada x = " << x;
  std::cout << "\nTPonto: Coordenada y = " << y << std::endl;
}
