#ifndef TPonto_h
#define TPonto_h

/** @copyright (C) Andre Duarte Bueno @file List-11-5-TPonto.h */
// Define a classe TPonto, o tipo de usu�rio TPonto.
class TPonto
{

 protected:
  int x;
  int y;
  static int contador;

 public:
  TPonto ():x (0), y (0)    
    {      
      contador++;    
    };
  TPonto (int _x, int _y):x (_x), y (_y)    
    {      
      contador++;    
    };

  // Seta ponto
  inline void Set (TPonto & p);

  inline void Set (int &_x, int &_y)
    {
      x = _x;
      y = _y;
    }

  // M�todo inline definido dentro da classe
  int Getx () const
  {
    return x;
  };

  // M�todo inline, declarado aqui, definido no arquivo cpp
  inline int Gety () const;

  // M�todo virtual, desenha o ponto
  virtual void Desenha ();

  // M�todo Est�tico 
  static int GetContador ();
};
#endif
