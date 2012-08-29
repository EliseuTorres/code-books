/** @copyright (C) Andre Duarte Bueno  @file  List-17-1-Polimorfismo.cpp */
#include <iostream>
#include "List-11-5-TPonto.h"
#include "List-15-1-TCirculo.h"
#include "List-16-2-TElipse.h"
using namespace std;

//Exemplo de cria��o e uso do objeto TPonto, TCirculo e TElipse
int main()
{
  //1- Crie um ponteiro para a classe base
  TPonto * ptr = NULL; 
  
  int selecao;
  //2- Pergunte para o usu�rio qual objeto deve ser criado
  do
    {
      cout << "\nQual objeto criar? ";
      cout << "\nTPonto................(1)";
      cout << "\nTCirculo..............(2)";
      cout << "\nTElipse...............(3)";
      cout << "\nPara sair 4?:";
      cin >> selecao;  cin.get();

      //3- Crie o objeto selecionado
      switch(selecao)
	{
	case 1: ptr = new TPonto(1,2);          break;
	case 2: ptr = new TCirculo(1,2,3);      break;
	case 3: ptr = new TElipse(1,2,3,4);     break;
	default:ptr = new TCirculo(1,2,3);      break;
	}
      
      //4- Agora voc� pode fazer tudo o que quiser com o objeto  criado.
      ptr->Desenha ();

      //....
      //ptr->outros m�todos
      //....

      //5- Para destruir o objeto criado, use
      delete ptr; 
      ptr = NULL;
    } while ( selecao < 4 );
  return 0;
}
