/** @copyright (C) Andre Duarte Bueno  @file  List-19-1-TPonto.h */
#ifndef _TPonto_
#define _TPonto_

#include <iostream>

//Define a classe TPonto, define o tipo de usu�rio TPonto.
class TPonto
{ 
 private:
  int x;
  int y; 
  static int contador; 

 public:
  //Construtor default
  TPonto() : x(0) , y(0)   { contador++; };   
  
  //Construtor sobrecarregado
  TPonto( int _x , int _y ) : x( _x ) ,y( _y )   { contador++; };
  
  //Construtor de c�pia
  TPonto(const TPonto& p)
    { 
      x = p.x;
      y = p.y;
      contador++ ;
    }; 

  //Destrutor virtual
  virtual   ~TPonto()
    {
      contador--;
    };

  //Seta ponto
  inline void Set( TPonto& p ); 

  //Seta ponto
  inline void Set(int & x, int & y); 

  //M�todo inline, obt�m x
  int Getx() const { return x; }; 

  //M�todo inline, obt�m y
  inline int Gety()const; 

  //M�todo virtual, desenha o ponto
  virtual void Desenha(); 

  //M�todo Est�tico
  static int GetContador();

  //Declara��o da sobrecarga de operadores un�rios como m�todo membro
  inline TPonto& operator++(int); 
  inline TPonto& operator--(int); 
  inline TPonto& operator++(); 
  inline TPonto& operator--(); 

  //Declara��o da sobrecarga de operadores bin�rios como m�todo membro
  inline TPonto& operator+(const TPonto& p2) const; 
  inline TPonto& operator-(const TPonto& p2) const; 
  inline TPonto& operator=(const TPonto& p2); 
  inline TPonto& operator+=(const TPonto& p2); 
  inline TPonto& operator-=(const TPonto& p2); 

  //Declara��o da sobrecarga de operadores bin�rios como fun��o friend
  friend bool    operator==(const TPonto& p1,const TPonto& p2);
  friend bool    operator!=(const TPonto& p1,const TPonto& p2); 
  
  friend std::ostream& operator<<(std::ostream& out, const TPonto& p);
  friend std::istream& operator>>(std::istream& in, TPonto& p);
};
#endif

/*
Novidades:
----------
-Defini��o de operadores sobrecarregados, como o operador soma
TPonto& operator+  (TPonto& p2); 

-Sobrecarga como m�todo membro e como fun��o friend.
*/
