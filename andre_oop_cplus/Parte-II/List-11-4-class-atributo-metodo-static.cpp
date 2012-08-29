/** @copyright (C) Andre Duarte Bueno 
    @file List-11-4-class-atributo-metodo-static.cpp */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*A classe TPessoa representa uma pessoa (um aluno ou um professor)
  de uma universidade. Tem um nome, uma matricula, um IAA,
  e m�todos b�sicos para entrada e sa�da de dados.*/
class TPessoa
{

public:
  string nome;
  string matricula;
  float iaa;

private:
  static int numeroAlunos;

public:
  void Entrada();
  void Saida() const;

  // Um m�todo est�tico s� pode acessar e alterar atributos est�ticos
  static int GetnumeroAlunos()
  {
    return numeroAlunos;
  }
};

// Atributo est�tico � aquele que pertence a classe e n�o ao objeto
// e precisa ser definido depois da classe
int   TPessoa::numeroAlunos = 0;

void TPessoa::Entrada()
{
  cout << "Entre com o nome do aluno: ";
  getline (cin, nome);

  cout << "Entre com a matr�cula do aluno: ";
  getline (cin, matricula);

  cout << "Entre com o IAA do aluno: ";
  cin >> iaa;
  cin.get ();
}

void      TPessoa::Saida() const 
{
  cout << "Nome do aluno: " << nome << endl;
  cout << "Matr�cula: " << matricula << endl;
  cout << "IAA: " << iaa << endl;
}

int main()
{
  string linha =    "--------------------------------------------------------------\n";

  cout << "Entre com o n�mero de alunos da disciplina (ex: 3): ";

  int numeroAlunos;
  cin >> numeroAlunos;
  cin.get();

  TPessoa professor;

  vector < TPessoa > aluno(numeroAlunos);

  cout << "Entre com o nome do professor: ";
  getline(cin, professor.nome);

  cout << "Entre com a matr�cula do professor: ";
  getline(cin, professor.matricula);
  for (int contador = 0; contador < aluno.size(); contador++)
    {
      cout << "Aluno " << contador << endl;
      aluno[contador].Entrada();
    }

  cout << linha << "RELA��O DE PROFESSORES E ALUNOS: \n" << linha;
  cout << "Nome do professor: " << professor.nome << "\n" << "Matr�cula: "
       << professor.matricula << "\n";

  for (int contador = 0; contador < aluno.size(); contador++)
    {
      cout << linha << "Aluno " << contador << endl;
      aluno[contador].Saida();
    }

  return 0;
}
