#ifndef TPontoComSobrecarga_h
#define TPontoComSobrecarga_h

/** @copyright (C) Andre Duarte Bueno @file List-19-1-TPontoComSobrecarga.h*/
#include <iostream>

class TPonto
{
 private:
  int x;
  int y;

  static int contador;

 public:
  TPonto():x(0), y(0)    
    { 
      contador++;    
    };

  TPonto (int _x, int _y):x (_x), y (_y)
    {
      contador++;    
    };
  TPonto (const TPonto & p)  
    {   
      x = p.x; 
      y = p.y;    
      contador++;    
    };

  virtual ~TPonto()    
    {
      contador--;    
    };

  inline void Set (TPonto & p);

  inline void Set (int &x, int &y);

  int Getx () const    
    {
      return x;    
    };

  inline int Gety () const;

  virtual void Desenha ();

  static int GetContador ();

  // Declara��o da sobrecarga de operadores un�rios como m�todo membro
  inline TPonto  operator++(int);
  inline TPonto  operator--(int);
  inline TPonto& operator++();
  inline TPonto& operator--();
  
  // Declara��o da sobrecarga de operadores bin�rios como m�todo membro
  inline TPonto & operator+ (const TPonto & p2) const;
  inline TPonto & operator- (const TPonto & p2) const;
  inline TPonto & operator= (const TPonto & p2);
  inline TPonto & operator+= (const TPonto & p2);
  inline TPonto & operator-= (const TPonto & p2);
  
  // Declara��o da sobrecarga de operadores bin�rios como fun��o friend
  friend bool operator== (const TPonto & p1, const TPonto & p2);
  friend bool operator!= (const TPonto & p1, const TPonto & p2);
  friend std::ostream & operator<< (std::ostream & out, const TPonto & p);
  friend std::istream & operator>> (std::istream & in, TPonto & p);
};

#endif

