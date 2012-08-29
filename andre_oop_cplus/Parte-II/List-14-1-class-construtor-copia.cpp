/** @copyright (C) Andre Duarte Bueno @file List-14-1-class-construtor-copia.cpp */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*A classe TPessoa representa uma pessoa (um aluno ou um professor)
  de uma universidade. Tem um nome, uma matricula e um IAA (indice aproveitamento).
  E m�todos b�sicos para entrada e sa�da de dados.
  Inclui construtor e destrutor (declarados e definidos dentro da classe).*/
class TPessoa
{

private:			// Acesso privado
  string nome;			// Atributo normal � criado para cada objeto
  string matricula;
  double iaa;

  static int numeroAlunos;	// Atributo est�tico � criado na classe

public:				// Acesso p�blico (tendo um objeto pode acessar
                                // os m�todos publicos)

                                // Construtor default, chamado automaticamente
                                // na contru��o do objeto
  TPessoa ():iaa (0),nome(""),matricula("")
  {
    numeroAlunos++;
    cout << "Criou objeto " << numeroAlunos << " construtor default" << endl;
  }

  TPessoa (const TPessoa & obj)	// Construtor de c�pia, cria uma c�pia 
  {				// de um objeto existente 
    nome = obj.nome;
    matricula = obj.matricula;
    iaa = obj.iaa;
    numeroAlunos++;
    cout << "Criou objeto " << numeroAlunos << " construtor de c�pia" << endl;
  }

  ~TPessoa ()			// M�todo Destrutor, chamada automaticamente 
  {				// na destrui��o do objeto
    numeroAlunos--;
    cout << "Destruiu objeto " << numeroAlunos << endl;
  }

  // M�todos do objeto, alteram os atributos do objeto e seu estado
  void Entrada ();

  void Saida (ostream & os) const;

  string Getnome () const
  {
    return nome;
  }

  string Getmatricula () const
  {
    return matricula;
  }

  double Getiaa () const
  {
    return iaa;
  }
  
  void Setiaa (double _iaa)
  {
    iaa = _iaa;
  }

  void Setnome (string _nome)
  {
    nome = _nome;
  }

  void Setmatricula (string _m)
  {
    matricula = _m;
  }

  // M�todos estaticos e p�blicos podem ser chamados sem um objeto e 
  // s� podem manipular atributos static
  static int GetnumeroAlunos ()
  {
    return numeroAlunos;
  };
};

// A linha a seguir define (aloca mem�ria) para o atributo numeroAlunos.
int   TPessoa::numeroAlunos = 0;

void TPessoa::Entrada ()
{
  cout << "Entre com o nome do aluno: ";
  getline (cin, nome);
  cout << "Entre com a matr�cula do aluno: ";
  getline (cin, matricula);
  cout << "Entre com o IAA do aluno: ";
  cin >> iaa;
  cin.get ();
}

void      TPessoa::Saida (ostream & os) const 
{
  os << "Nome do aluno: " << nome << endl;
  os << "Matr�cula: " << matricula << endl;
  os << "IAA: " << iaa << endl;
}

int main ()
{
  string linha = "-------------------------------------------------------\n";

  TPessoa professor;		// Cria um objeto do tipo TPessoa com nome professor

  cout << "Entre com o nome do professor: ";

  string nome;

  getline (cin, nome);		// Compare esta entrada com a do exemplo anterior

  professor.Setnome (nome);

  cout << "Entre com a matr�cula do professor: ";
  string matricula;
  getline (cin, matricula);
  professor.Setmatricula (matricula);

  cout << "Entre com o n�mero de alunos da disciplina (ex: 3): ";
  int numeroAlunos;
  cin >> numeroAlunos;
  cin.get ();


  // Cria vetor de TPessoa com nome aluno
  vector < TPessoa > aluno (numeroAlunos);

  for (int contador = 0; contador < aluno.size (); contador++)
    {
      cout << "Aluno " << contador << endl;
      aluno[contador].Entrada ();
    }

  cout << linha << "RELA��O DE PROFESSORES E ALUNOS: \n" << linha;
  cout << "Nome do professor: " << professor.Getnome () << endl;
  cout << "Matr�cula: " << professor.Getmatricula () << endl;
  for (int contador = 0; contador < aluno.size (); contador++)
    {
      cout << linha << "Aluno " << contador << endl;
      aluno[contador].Saida (cout);
    }

  cout << linha << "N�mero de alunos = " << TPessoa::GetnumeroAlunos () << endl;

  cout << linha << "chamando : TPessoa professor2(professor); " << endl;

  TPessoa professor2 (professor);
  professor2.Saida (cout);
  {
    cout << linha << "chamando: TPessoa professor3 = professor2;" << endl;

    // Uso do construtor de c�pia pela atribui��o
    TPessoa professor3 = professor2;
    professor3.Saida (cout);
  }				// <-Destr�i professor3

  return 0;
}
