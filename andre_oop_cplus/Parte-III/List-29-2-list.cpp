/** @copyright (C) Andre Duarte Bueno @file List-29-2-list.cpp */

#include <iostream>
#include <string>
#include <list>      			// Listas
#include <algorithm>			// Algoritmo gen�rico (cap�tulo 32)

using namespace std;

// Declara��o da sobrecarga do operador de extra��o << para list
ostream & operator	<< (ostream & os, const std::list < float >&lista);

// Defini��o da fun��o main
int main()
{
  string linha = "\n-------------------------------------------------------\n";
  
  // Cria��o de duas listas para float, isto �, duas listas de n�meros float
  std::list <float>container_list, container_list2;
  container_list.push_front	(312.1f);	// Inclui valores na lista
  container_list.push_back	(313.4f);
  container_list.push_back	(316.7f);
  container_list.push_front	(312.1f);
  container_list.push_front	(313.4f);
  container_list.push_front	(314.1f);
  container_list.push_front	(315.1f);
  cout	<< linha << "Conte�do do container: \n"<< container_list << linha << endl;
  
  // Elimina primeiro elemento da lista
  container_list.pop_front();
  cout	<< "Conte�do do container ap�s: container_list.pop_front(); " << endl;
  cout	<< container_list << linha << endl;
  
  // Elimina ultimo elemento da lista
  container_list.pop_back();
  cout	<< "Conte�do do container ap�s: container_list.pop_back(); " << endl;
  cout	<< container_list << linha << endl;
  
  // Ordena o container
  container_list.sort();
  cout	<< "Conte�do do container ap�s: container_list.sort(); " << endl;
  cout	<< container_list << linha << endl;
  
  // Move os elementos repetidos para o final do container
  // e seta como �ltimo elemento v�lido, o �ltimo elemento n�o repetido.
  container_list.unique();
  cout << "Conte�do do container ap�s: container_list.unique(); " << endl;
  cout << container_list << linha << endl;  
  return 0;
}

// Mostra lista. Com vector foi poss�vel usar v[i], uma lista n�o aceita l[i],
// precisa de um iterator, como a seguir.
ostream & operator << (ostream & os, const std::list < float >&lista)
{
  std::list < float >::const_iterator it;
  for (it = lista.begin(); it != lista.end(); it++)
		os << *it << ' ';
  return os;
}
