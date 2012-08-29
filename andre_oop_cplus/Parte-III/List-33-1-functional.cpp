/** @copyright (C) Andre Duarte Bueno @file List-33-1-functional.cpp */

#include <iostream>
#include <functional>
#include <deque>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

// Classe Fun��o
// Cria uma fun��o objeto a partir de uma fun��o un�ria
// unary_function<retorno, par�metro>
template<class Arg>
class TFatorial : public unary_function<Arg, Arg>
{ 
public:
  Arg operator()(const Arg& arg)
  { 
    Arg a = 1;
    for( Arg i = 2; i <= arg; i++ )
      a *= i;
    return a;
  }
};

int main()
{ 
  // Cria um deque 
  deque<int> d(10);
		
  for( int i = 0; i < d.size(); i++) 
    d[i] = i;

  // Cria um vetor para armazenar os fatoriais
  vector<int> v(10);		
  
  // Determina o fatorial dos n�meros armazenados em d e armazena no vetor v
  transform(d.begin(), d.end(), v.begin(), TFatorial<int>());
  cout	<< "N�meros: " << endl << " ";
  copy(d.begin(),d.end(),ostream_iterator<int>(cout," \t"));
  cout	<< "\n e fatoriais: " << endl << " ";
  copy(v.begin(),v.end(),ostream_iterator<int>(cout," \t"));
  cout	<< endl << endl;
  char resp;
  
  TFatorial<int> objeto_funcao;
  do {
    cout << "Entre com um n�mero (int):";
    int numero;
    cin >> numero; cin.get();
    cout << "N�mero = "<< setw(7) << numero <<" fatorial = " << setw(7) << objeto_funcao(numero) << endl;
    cout << "Continuar (s/n)?";
    cin.get(resp); cin.get();
  } while(resp == 's' || resp == 'S');
  
  return 0; 
}
