/** @copyright (C) Andre Duarte Bueno @file List-7-3-complex.cpp */

#include <iostream>

// Exemplo preliminar de defini��o de um tipo de usu�rio, por meio de uma classe
// Defini��o do tipo do usu�rio Complexo, representa um n�mero complexo
class Complexo
{

public:
  double x, y;				// Atributos x e y

  inline void Set (double _x, double _y)// M�todo usado para defini��o 
  {				        // dos valores de x e y
    x = _x;
    y = _y;
  };

  Complexo & operator+ (Complexo &);	// Sobrecarga do operador+

};

// Exemplo de defini��o de um m�todo da classe Complexo
// O operator+ cria um novo n�mero complexo com nome z onde armazena a soma
Complexo & Complexo::operator+ (Complexo & p)
{
  Complexo *
    z = new Complexo;
  z->x = x + p.x;
  z->y = y + p.y;
  return (*z);
}

int main ()				// Fun��o principal
{
  Complexo a, b;			// Cria os objetos a e b do tipo Complexo

  // Chama m�todo Set dos objetos a e b
  a.Set (5, 4);				// a.x = 5; a.y = 4
  b.Set (2, 6);				// b.x = 2; b.y = 6 
  Complexo c;				// Cria um novo objeto do tipo 
                                        // complexo com nome c
  c = a + b;				// Soma os complexos a e b e armazena em c

  // Mostra o resultado na tela
  std::cout << "c(" << c.x << "," << c.y << ") = " << "a(" << a.x << ","
	    << a.y << ") + " << "b(" << b.x << "," << b.y << ") " << std::endl;

  return 0;
}
