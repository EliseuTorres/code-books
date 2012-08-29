#ifndef TAlunoFuncionario_h
#define TAlunoFuncionario_h

/** @copyright (C) Andre Duarte Bueno @file List-17-8-TAlunoFuncionario.h */
#include <fstream>		// vou usar objetos fstream (saida disco,tela,..)

#include "List-17-4-TAluno.h"	
#include "List-17-6-TFuncionario.h"

/* A classe TAlunoFuncionario representa um funcion�rio que � aluno.
Tem um nome, uma matr�cula. E m�todos b�sicos para entrada e sa�da de dados.
Tem alguns construtores e um destrutor */

class TAlunoFuncionario : public TAluno, public TFuncionario
{
  double ip;			// Por default � private

 public:

  TAlunoFuncionario ();

    virtual ~ TAlunoFuncionario ();

    virtual void Entrada ();

    virtual void Saida (std::ostream & os) const;
    void Setip (double _ip)
      {
	ip = _ip;
      }

    double Getip () const
      {
	return ip;
      }
};
#endif
