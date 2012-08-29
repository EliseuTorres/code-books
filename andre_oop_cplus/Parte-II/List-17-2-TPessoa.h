/** @copyright (C) Andre Duarte Bueno  @file  List-17-2-TPessoa.h */
#ifndef TPessoa_h
#define TPessoa_h

#include <fstream>		// Utilizarei objetos fstream (sa�da disco,tela,..)
#include <string>		// Utilizarei objetos string's

/* A classe TPessoa representa uma pessoa (um aluno, um professor, um funcion�rio). 
Tem um nome, uma matricula. E m�todos b�sicos para entrada e sa�da de dados. 
Tem alguns construtores e um destrutor. */

class TPessoa
{
private:			// Acesso privado (somente nesta classe)

  std::string nome;
  std::string matricula;

public:			// Acesso p�blico 

  TPessoa(); // construtor
  TPessoa(const TPessoa & obj);// Construtor de c�pia 

  TPessoa(std::string _nome, std::string _matricula);	// Construtor sobrecarregado 

  virtual ~TPessoa();	// Destrutor

  virtual void Entrada();

  virtual void Saida(std::ostream & os) const;

  std::string Getnome () const
    {
      return nome;
    };

  std::string Getmatricula () const
    {
      return matricula;
    };

  void Setnome(std::string _nome)
    {
      nome = _nome;
    }

  void Setmatricula(std::string _m)
    {
      matricula = _m;
    }
};

#endif
