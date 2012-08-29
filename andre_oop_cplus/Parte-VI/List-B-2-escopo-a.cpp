/** @copyright (C) Andre Duarte Bueno @file List-B-2-escopo-a.cpp */
// Declara que existe uma funcao1, que � definida em outro arquivo

extern void funcao1();

int x1 = 1;			// Cria vari�vel global, do tipo int, com nome x1

static int x3 = 7;		// Cria vari�vel x3, vis�vel somente neste arquivo, 
				// permanente e global
int main()
{
  int x1 = 11;			// Cria um novo x1, vis�vel dentro de main()

  float y1 = 44;		// y1 � vis�vel dentro de main(), � tempor�ria

  for (int i = 0; i < 5; i++)	// Cria um bloco for
    {
      float z1, x1;		// Cria z1 e x1, do tipo float, vis�veis 
                                // dentro do for, e tempor�rias

      /* Existem tr�s x1, um global, um de main, e um do for. Este � do for */
      x1 = 111.0;
      z1 =::x1;			// Com o operador de escopo (::)

      // acessa x1 de main(), logo  z1 = 11
      z1 = y1;
    }				// destr�i x1 e z1 do for

  /* y1 = z1; Erro z1 indefinido fora do bloco do for */

  // Chama funcao1, definida em outro arquivo
  funcao1();
}				// Destr�i x1 definido no bloco de main().
				// x1 global ser� destru�da quando o programa for encerrado.
