/** @copyright (C) Andre Duarte Bueno @file List-32-2-vector-3.cpp */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>				// Classe de vetores
#include <algorithm>				// Classe para algoritmos gen�ricos

using namespace std;				// Define o uso do espa�o de nomes std

// Declara��o de sobrecarga de << e >>
ostream & operator << (ostream & os, const vector <int> &v);
ofstream & operator << (ofstream & os, const vector <int> &v);

bool maiorQue5(int valor)			// Declara��o de fun��o predicado
{
  return valor > 5;
}

int main()
{
  string linha =" ----------------------------------------------------------\n";
  vector<int>v;
  int data;
  do	
    {
      cout	<< "\nEntre com o dado (" << setw (3) << v.size () << "):";
      cin	>> data;
      cin.get();
      if(cin.good())
	v.push_back(data);
    } while ( cin.good());
  cin.get();
  cin.clear(); 					// Reseta objeto cin para estado ok
  {
    ofstream fout("vector.dat");
    if (! fout)
      return 0;		fout	<< v << endl;
    fout.close();
  }
  cout	<< "\n" << linha << v << endl;

  int numero;
  cout	<< "\nEntre com o n�mero a ser localizado:";
  cin	>> numero;
  cin.get();

  // Ponteiro para a posi��o localizada
  vector <int>::iterator it = find (v.begin() , v.end() , numero) ;
  cout	<< "\nN�mero localizado na posi��o:" << (it - v.begin()) << endl;

  // Localiza primeiro elemento que satisfaz a condi��o dada pela fun��o maiorQue5
  it = find_if (v.begin() , v.end() , maiorQue5);
  cout	<< "\nN�mero maior que 5 localizado na posi��o:" << (it - v.begin())  << endl;;

  // Ordena o container
  sort(v.begin() , v.end());
  cout	<< "\nVetor ap�s ordena��o com sort(v.begin(),v.end())" << endl;
  cout	<< linha << v << endl;

  // Preenche com o valor 45
  fill(v.begin() , v.end() , 45);
  cout	<< "\nVetor ap�s fill(v.begin(), v.end() , 45);" << endl;
  cout	<< linha << v << endl;

  // Retorna dimens�o e capacidade
  cout	<< "v.size()=" << v.size() << endl;
  cout	<< "v.capacity()=" << v.capacity() << endl;

  // Redimensiona o container
  v.resize(20);
  cout	<< "\nVetor ap�s resize(20):" << endl;
  cout	<< linha << v << endl;
  cout	<< "v.size()=" << v.size() << endl;
  cout	<< "v.capacity()=" << v.capacity() << endl;
  cout	<< linha << endl;
  cin.get();
  return 0;
}

ostream & operator << (ostream & os , const vector < int >&v)
{
  for (int i = 0; i < v.size() ; i++)
    os << "v[" << setw (3) << i << "]=" << setw(5) << v[i] << ' ';
  return os;
}

ofstream & operator<< ( ofstream & os , const vector < int >&v)
{
  for (int i = 0; i < v.size() ; i++)
    os << setw (10) << v[i] << endl;
  return os;
}
