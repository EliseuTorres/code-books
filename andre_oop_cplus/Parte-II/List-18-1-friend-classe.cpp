/** @copyright (C) Andre Duarte Bueno   @file List-18-1-friend-classe.cpp */
#include <iostream>
class B;			// Somente declara a classe B
class A				// Declara��o e defini��o da classe A
{
  int a;

public:
  void fA (B & obj_b);		// M�todo da classe A que recebe como par�metro um objeto B 

};

// Declara��o e defini��o da classe B
class B
{

private:
  int b;
  friend class A;		// A classe A � amiga, o m�todo fA pode acessar os atributos de B
};

void A::fA (B & obj_b)
{
  a = obj_b.b;
}

int main ()
{
  std::cout << "Criando objetos A obj_a; B obj_b; " << std::endl;
  A obj_a;
  B obj_b;

  obj_a.fA (obj_b);

  return 0;
}
