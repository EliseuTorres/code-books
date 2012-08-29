/** @copyright (C) Andre Duarte Bueno @file List-B-3-escopo-b.cpp*/

int x2;				// Cria objeto do tipo int, com nome x2, global, permanente

extern int x1;			// J� existe um objeto do tipo int com nome x1, 

// definido em outro arquivo
extern int x3;			// J� existe um objeto do tipo int com nome x3, 

// definido em outro arquivo
void funcao1 ();		// Declara��o da fun��o1

void funcao1 ()
{
  //Cria o objeto y2 do tipo float, o mesmo � vis�vel dentro da fun��o1, � tempor�rio 
  float y2 = x2;

  /* Se tentar usar a linha abaixo, causa erro de linkagem, pois x3 
     foi definido como sendo est�tico, s� podendo ser usado no  arquivo 
     em que foi definido.*/
  /* float t = x3;*/

  for (int i = 0; i < 5; i++)
    {
      static int r3;		// Cria r3 na primeira passagem.  
				// r3 tem escopo de bloco, � permanente
      int r4 = 3;		// Cria r4 que tem escopo de bloco, tempor�rio
      r3++;
      x2 = r3 * i + r4;
    }				// Destr�i r4
}				// Destr�i y2.
// r3 est�tico, � destru�do quando o programa for encerrado.
