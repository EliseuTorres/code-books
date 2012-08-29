/** @copyright (C) Andre Duarte Bueno  @file  List-15-2-TCirculo.cpp */
#include <iostream>
#include "List-15-1-TCirculo.h"

//Implementa��o dos m�todos de  TCirculo
void TCirculo::Set(int x,int y, int raio)
{
  TPonto::Set(x,y);
  this->r1 = raio;
}

void TCirculo::Set(TPonto&  p, int raio)
{
  //Set(p.x,p.y);
  this->x  = p.Getx();
  this->y  = p.Gety();
  r1 = raio;
}

void TCirculo::Set(TCirculo & c)
{
  this->x  = c.x;
  this->y  = c.y;
  this->r1 = c.r1;
}

//Implementa��o  de Desenha
//Usa o m�todo desenha da classe base e acrescenta o desenho do circulo
void TCirculo::Desenha()
{
  //chama fun��o da classe base
  TPonto::Desenha();

  //instru��o para desenhar o circulo;
  std::cout << "\nTCirculo: Coordenada r1=" << r1 << std::endl;
}


