/** @copyright (C) Andre Duarte Bueno @file List-32-1-list2.cpp */
#include <iostream>
#include <list>			// Classe de listas
#include <algorithm>		// Algoritmo gen�rico	
#include <iterator>		// Iteradores

using namespace std;		// Uso de namespace

int main ()			// Defini��o da fun��o main
{

  // Cria um iterador para ostream
  ostream_iterator <float> output (cout , " ");

  // Cria��o de duas listas para float
  std::list <float> container_list , container_list2 ;

  // Inclui valores na lista
  container_list.push_front(312.1f);
  container_list.push_back(313.4f);
  container_list.push_front(312.1f);
  container_list.push_back(316.7f);

  // Mostra lista
  cout	<< "\nConte�do do container:" << endl;
  copy(container_list.begin() , container_list.end() , output);

  // Ordena lista
  container_list.sort ();
  cout << "\nConte�do do container ap�s sort: " << endl;
  copy(container_list.begin() , container_list.end() , output);

  // Adiciona elementos a lista2
  container_list2.push_front(22.0);
  container_list2.push_front(2222.0);
  cout	<< "\nConte�do do container 2: ";
  copy( container_list2.begin() , container_list2.end() , output);

  // Fun��o splice (Adiciona ao final de container_list 
  // os valores de container_list2)
  container_list.splice ( container_list.end() , container_list2 );
  cout	<< "\nConte�do do container ap�s splice: ";
  copy(container_list.begin() , container_list.end() , output);

  // Mistura as duas listas, colocando tudo em container_list 
  // e eliminando tudo de container_list2
  container_list.merge ( container_list2 );
  cout << "\nConte�do do container ap�s container_list.merge( container_list2 ):";
  copy ( container_list.begin() , container_list.end() , output);
  cout << "\nConte�do do container 2: " << endl;
  copy ( container_list2.begin() , container_list2.end() , output);

  // Elimina valores duplicados
  container_list.unique();
  cout << "\nContainer depois de unique ";
  copy ( container_list.begin() , container_list.end() , output);

  // Chama fun��es pop_front e pop_back
  container_list.pop_front();		// Elimina primeiro elemento da lista
  container_list.pop_back();		// Elimina ultimo elemento da lista
  cout << "\nContainer depois de pop_front e pop_back: ";
  copy ( container_list.begin () , container_list.end () , output);

  // Troca tudo entre as duas listas
  container_list.swap ( container_list2 );
  cout << "\nContainer depois de swap entre as duas listas:";
  copy ( container_list.begin() , container_list.end() , output);
  cout << "\nContainer_list2 cont�m :";
  copy ( container_list2.begin() , container_list2.end() , output);

  // Atribui valores de container_list2 em container_list
  container_list.assign ( container_list2.begin (),container_list2.end());
  cout << "\nContainer depois de container_list .assign ";
  cout << "( container_list2.begin(),container_list2.end()); ";
  copy ( container_list.begin() , container_list.end() , output);

  // Mistura novamente
  container_list.merge ( container_list2 );
  cout << "\nContainer depois de novo merge :";
  copy ( container_list.begin() , container_list.end() , output);

  // Remove elemento na popsi��o 2
  container_list.remove (2);
  cout << "\nContainer ap�s remove( 2 ) container_list contem:";
  copy ( container_list.begin() , container_list.end() , output);
  cout << endl; 
  return 0;
}
