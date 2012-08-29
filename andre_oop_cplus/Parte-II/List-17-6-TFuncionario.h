#ifndef TFuncionario_h
#define TFuncionario_h

/** @copyright (C) Andre Duarte Bueno @file List-17-6-TFuncionario.h */
#include <fstream>
#include <string>

#include "List-17-2-TPessoa.h"


/* A classe TFuncionario � herdeira da classe TPessoa, e representa um funcionario de uma universidade. 
Redefine os m�todos Entrada/Saida e a diciona o indiceProdutividade e m�todos GetindiceProdutividade(), 
SetindiceProdutividade() */
class TFuncionario: /*virtual */ public TPessoa
{

 private:

  double indiceProdutividade;

 public:

  TFuncionario ();
  TFuncionario (const TFuncionario & obj);
  TFuncionario (std::string _nome, std::string _matricula, double _ip = 0);
  virtual ~ TFuncionario ();
  virtual void Entrada ();
  virtual void Saida (std::ostream & os) const;

  double GetindiceProdutividade () const
    {
      return indiceProdutividade;
    }

  void SetindiceProdutividade (double _ip)
    {
      indiceProdutividade = _ip;
    }
};
#endif
