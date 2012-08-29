/** @copyright (C) Andre Duarte Bueno 
    @file List-11-2-class-atributo-metodo-normal.cpp */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* A classe TPessoa representa uma pessoa (um aluno ou um professor) 
   de uma universidade. 
   Tem um nome, uma matricula.
   E m�todos b�sicos para entrada e sa�da de dados. */
class TPessoa
{

public:
  string nome;			// Atributos normais
  string matricula;

  void Entrada ();		// M�todos
  void Saida () const;
};

// Defini��o dos m�todos
void TPessoa::Entrada ()
{
  cout << "Entre com o nome do aluno: ";
  getline (cin, nome);
  cout << "Entre com a matr�cula do aluno: ";
  getline (cin, matricula);
}

void      TPessoa::Saida () const 
{
  cout << "Nome do aluno: " << nome << endl;
  cout << "Matr�cula: " << matricula << endl;
}

int main ()
{
  string linha =    "-----------------------------------------------------------\n";
  const int numeroAlunos = 5;

  // Cria um objeto do tipo TPessoa com nome professor
  TPessoa professor;
  cout << "Entre com o nome do professor: ";
  getline (cin, professor.nome);
  cout << "Entre com a matr�cula do professor: ";
  getline (cin, professor.matricula);
  
  // Cria um vetor de objetos do tipo TPessoa com nome aluno
  vector < TPessoa > aluno (numeroAlunos);
  for (int contador = 0; contador < numeroAlunos; contador++)
    {
      cout << "Aluno " << contador << endl;
      aluno[contador].Entrada ();
    }

  cout << "\n" << linha << "RELA��O DE PROFESSORES E ALUNOS: \n" << linha;
  cout << "Nome do professor: " << professor.nome << endl;
  cout << "Matr�cula: " << professor.matricula << endl;
  for (int contador = 0; contador < numeroAlunos; contador++)
    {
      cout << linha << "Aluno " << contador << endl;
      aluno[contador].Saida ();
    }

  cout << linha;

  return 0;
}
