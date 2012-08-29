/** @copyright (C) Andre Duarte Bueno @file List-8-1-namespace.cpp */

#include <iostream>

int x = 3;			// Objeto x global

namespace teste			// Cria um bloco namespace com o nome teste
{
  const int x = 7;		// Objeto x do namespace
  void Print ();		// Fun��o Print do namespace

  namespace teste2		// namespace teste2 dentro de teste
  {
    int y = 4;
  }
}

int main ()			// Fun��o main
{
  std::cout << x << std::endl;	// Utiliza x global
  std::cout << teste::x << std::endl;	// Utiliza x do namespace teste
  std::cout << teste::teste2::y << std::endl;
  teste::Print ();		// chama fun��o do namespace

  return 0;
}

// Defini��o da fun��o Print do namespace teste
void teste::Print ()
{
  std::cout << "\nfun��o print do namespace" << std::endl;
  std::cout << x << std::endl;	// x do namespace
  std::cout <<::x << std::endl;	// x global
  std::cout << teste2::y << std::endl;
}
