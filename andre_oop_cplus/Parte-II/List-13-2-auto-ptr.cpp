/** @copyright (C) Andre Duarte Bueno @file List-13-2-auto-ptr.cpp */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Tipo
{

public:
  int t;
  static int cont;

  Tipo ()
  {
    cont++;
    cout << "Construtor do objeto, cont = " << cont << endl;
  }

  ~Tipo ()
  {
    cout << "Destrutor do objeto, cont = " << cont << endl;
    cont--;
  }
};

int Tipo::cont = 0;

int main ()
{
  cout << "-----vetor est�tico de C:" << endl;
  {
    Tipo v_static[2];		// Cria vetor est�tico
  }				// Destr�i vetor ao sair de escopo

  cout << "-----vetor din�mico em C++ sem STL:" << endl;
  {
    Tipo *       v_dinamico = new Tipo[3];
    // .....Utiliza o vetor...
    delete[]v_dinamico;		// precisa do delete []
  }

  // Usando auto_ptr (criar apenas um objeto), auto_ptr n�o deve apontar para um vetor. 
  cout << "-----Objeto din�mico em C++ com auto_ptr:" << endl;
  {
    auto_ptr < Tipo > v_autoptr (new Tipo);
    v_autoptr->t = 77;
    cout << "t = " << v_autoptr->t << endl;
    // .....UTiliza o vetor...
  }				// apagado automaticamente

  cout << "-----vetor din�mico em C++ com STL:" << endl;
  {
    vector < Tipo > v_stl (4, Tipo ());	// � din�mico
    for (int i = 0; i < v_stl.size (); i++)
      {
	v_stl[i].t = i;
	cout << i << " = " << v_stl[i].t << endl;
      }
  }				// Destr�i objeto ao sair de escopo

  Tipo::cont = 0;
  cout << "-----vetor de ponteiros em C++ com STL:" << endl;
  {
    vector < Tipo * >v_stl (5);
    for (int i = 0; i < v_stl.size (); i++)
      {
	v_stl[i] = new Tipo ();
	v_stl[i]->t = i;
	cout << "i = " << i << "  t = " << v_stl[i]->t << endl;
      }
    for (int i = 0; i < v_stl.size (); i++)
      delete v_stl[i];
  }
  return 0;
}
