/** @copyright (C) Andre Duarte Bueno @file List-29-3-deque.cpp */

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main ()
{
  // Cria container do tipo deque para string, com o nome container_deque
  deque <string> container_deque;
  
  // Adicionando objetos ao deque
  container_deque.push_front	("Cidade de sol");	// Adicionar no in�cio
  container_deque.push_front	("Florian�polis");
  container_deque.push_back	("e mar.");		// Adicionar no fim

  cout	<< "Conte�do do container deque: " << endl;
  for (int i = 0; i < container_deque.size (); ++i)
    cout	<< container_deque[i] << ' ';
  
  // Setando um objeto do container diretamente
  container_deque[2] = string ("e mar com belezas sem par.");
  cout	<< "\nAp�s atribui��o direta:\n";
  for (int i = 0; i < container_deque.size (); ++i)
    cout << container_deque[i] << ' ';
  cout	<< endl;
  
  // Retirando primeiro elemento do deque
  container_deque.pop_front ();
  cout	<< "Ap�s um pop_front: " << endl;
  for (int i = 0; i < container_deque.size (); ++i)
    cout << container_deque[i] << ' ';
  cout	<< endl;
  
  return 0;
}
