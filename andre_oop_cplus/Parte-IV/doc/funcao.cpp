/*
  =========================================================================
  PROJETO:    Biblioteca LIB_LMPT
  Assunto/Ramo: TTeste...
  =========================================================================
  @author     Andr� Duarte Bueno
  @file       TTeste.h
  @begin      Sat Sep 16 2000
  @copyright  (C) 2000 by Andr� Duarte Bueno
  @email      bueno@lenep.uenf.br
*/

#include "config.h"

namespace teste {
  /**
   * Classe de teste mostra exemplo de fun��o documentada com f�rmulas do latex.
   * @see http://www.stack.nl/~dimitri/doxygen/formulas.html
   */
  class TFuncao
  {
  public:
    /**
     * Com JAVA_DOC e LATEX � poss�vel incluir f�rmulas no meio do c�digo,
     * o que � extremamente �til quando se trabalha com programas de engenharia,
     * matem�tica e f�sica.   Veja um exemplo no formato utilizado pelo latex:
      \begin{equation}
      P_{c}=\frac{2(d-1)\sigma}{r_{m}}
      \end{equation}
      
      o mesmo exemplo � setado no JAVA_DOC de forma embutida usando  \f$ P_{c}=\frac{2(d-1)\sigma}{r_{m}} \f$

      ou em um par�grafo separado usando 
      \f[
      P_{c}=\frac{2(d-1)\sigma}{r_{m}}
      \f]
      
      A dica � criar a fun��o usando o editor LyX, converter a mesma para o formato latex,
      copiar e colar no meio do c�digo.
    */
    void funcao_exemplo(){};
  };
  
} //fim do namespace teste


