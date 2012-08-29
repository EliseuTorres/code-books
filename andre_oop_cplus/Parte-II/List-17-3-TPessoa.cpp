/** @copyright (C) Andre Duarte Bueno  @file  List-17-3-TPessoa.cpp */
#include <iostream>
#include "List-17-2-TPessoa.h"
using namespace std;	

//Construtor default (sem par�metros)
TPessoa::TPessoa(): nome(""),matricula("")
{
  cout <<"criou objeto TPessoa construtor default" << endl;
};

TPessoa::TPessoa(const TPessoa& obj)
{
  nome = 	obj.nome;
  matricula = 	obj.matricula;
  cout << "criou objeto TPessoa construtor de c�pia" << endl;
}

TPessoa::TPessoa(string _nome, string _matricula):nome(_nome),matricula(_matricula)
{
  cout << "criou objeto TPessoa construtor sobrecarregado" << endl;
}

TPessoa::~TPessoa()
{
  cout<<"destruiu objeto TPessoa"<<endl;
};

void TPessoa::Entrada()
{
  cout << "Entre com o nome: ";
  getline(cin,nome);

  cout << "Entre com a matricula: ";
  getline(cin,matricula);
}

//Sa�da de dados
void TPessoa::Saida(ostream &os) const
{
  os << "Nome : "    	<< nome << endl;
  os << "Matricula : "  << matricula << endl;
}
