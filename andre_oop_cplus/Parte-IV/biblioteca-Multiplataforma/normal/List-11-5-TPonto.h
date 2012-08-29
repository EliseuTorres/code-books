/** @copyright (C) Andre Duarte Bueno  @file  List-11-5-TPonto.h */
#ifndef _TPonto_
#define _TPonto_

//Define a classe TPonto, o tipo de usu�rio TPonto.
class TPonto
{ 
  //------------------------------------Atributos
  //controle de acesso
 protected: 
  
  //atributos de objeto
  int x;    
  int y; 
  
  //atributo de classe
  static int contador; 
  
  //------------------------------------M�todos 
 public:
  
  //Construtor default
  TPonto() : x(0) , y(0)  { contador++; };   
  
  //Construtor sobrecarregado
  TPonto( int _x , int _y ) : x(_x) , y(_y)   { contador++; };
  
  //Construtor de c�pia
  TPonto( const TPonto& p )
    {
      x = p.x;
      y = p.y;
      contador++ ;
    }; 
  
  //Destrutor virtual
  virtual   ~TPonto()  {contador--;};
  
  //Seta ponto
  inline void Set( TPonto& p ); 
  inline void Set( int& _x, int& _y ) 
    {
    x = _x;
    y = _y;
    }

  //M�todo inline definido dentro da classe
  int Getx() const { return x; }; 
  
  //M�todo inline, declarado aqui, definido no arquivo cpp
  inline int Gety() const; 
  
  //M�todo virtual, desenha o ponto
  virtual void Desenha(); 
  
  //M�todo Est�tico e const
  static int GetContador();
};
#endif
