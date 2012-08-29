/** @copyright (C) Andre Duarte Bueno 
    @file List-15-3-especificador-heranca.cpp */

#include <iostream>
using namespace std;

class A
{
public:
  int x;

protected:
  int y;

private:
  int z;
};

class B:public A
{
public:
  int X ()
  {
    return x;
  };				// Ok x � p�blico

  int Y ()
  {
    return y;
  };				// Ok y � protegido

  int Z ()
  {
    return z;
  };				// Erro n�o tem acesso a z
};

class C:private A
{
public:
  int X ()
  {
    return x;
  };				// Ok x � privado

  int Y ()
  {
    return y;
  };				// Ok y � privado

  int Z ()
  {
    return z;
  };				// Erro n�o tem acesso a z
};
