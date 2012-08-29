/** @copyright (C) Andre Duarte Bueno 
    @file List-25-6-Entrada-Saida-Redirecionamento.cpp 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
  string nomeArquivoDisco;

  cout << "Entre com o nome do arquivo de disco: ";
  getline(cin, nomeArquivoDisco);

  cout << "Entre com o n�mero de repeti��es: ";
  int repeticoes = 0;
  cin >> repeticoes;
  cin.get();

  cout << "Entre com a precis�o do solver: ";
  double precisao = 0.0001;
  cin >> precisao;
  cin.get();

  cout << "VALORES INTRODUZIDOS / LIDOS" << endl;
  cout << "nome do arquivo de disco = " << nomeArquivoDisco << endl;
  cout << "n�mero de repeti��es = " << repeticoes << endl;
  cout << "precisao = " << precisao << endl;

  return 0;
}
