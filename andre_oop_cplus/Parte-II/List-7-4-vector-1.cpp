/** @copyright (C) Andre Duarte Bueno @file List-7-4-vector-1.cpp */

#include <iostream>
#include <vector>		// Classe de vetores, do container vector

int main ()			// Defini��o da fun��o main.
{
  // Cria um vector, do tipo int, com nome v (um vetor de inteiros)
  // Como um vector pode armazenar objetos de diferentes tipos (char, int, float, 
  // Complexo) preciso informar dentro de <> o tipo a ser manipulado pelo vetor.
  std::vector < int >v;

  int data;

  std::cout << "No DOS um Ctrl+z encerra a entrada de dados." << std::endl;
  std::cout << "No Mac um Ctrl+d encerra a entrada de dados." << std::endl;
  std::cout << "No GNU/Linux um Ctrl+d encerra a entrada de dados." << std::endl;

  do
    {
      std::cout << "\nEntre com o dado (" << v.size () << "): ";
      std::cin >> data;
      std::cin.get ();

      if (std::cin.good ())	// Se a entrada for v�lida 
	v.push_back (data);	// Adiciona data ao final do vetor v 
    }
  while (std::cin.good ());

  // Acessa partes do vetor usando m�todos front e back
  std::cout << "\nPrimeiro elemento do vetor = " << v.front ()
	    << "\n�ltimo elemento do vetor = " << v.back () << std::endl;

  // Mostra o vetor       
  for (int i = 0; i < v.size (); i++)	
    std::cout << "v[" << i << "]=" << v[i] << ' ';
  std::cout << std::endl;

  if( v.empty () )
    std::cout << "O vetor est� vazio" << std::endl;
  else
    std::cout << "O vetor n�o est� vazio" << std::endl;

  // Chama m�todo clear, que zera o vetor, apagando todos os objetos armazenados.
  v.clear ();
  if( v.empty () )
    std::cout << "O vetor est� vazio" << std::endl;
  else
    std::cout << "O vetor n�o est� vazio" << std::endl;
  std::cin.get ();

  return 0;
}

