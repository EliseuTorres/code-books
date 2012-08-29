/**
 * \defgroup variaveis_globais
 * Define grupo de vari�veis globais.
 * As mesmas s�o inclu�das dentro do bloco.
 */
//@{ 

///vari�vel global v1
int v1;

int v2;///<vari�vel global v1

//@} 


/// @ingroup global
/// Informa que a vari�vel abaixo pertence ao grupo de vari�veis globais.
/// mesmo estando fora do bloco.
extern int VarInA;

/**
 * Define um grupo com nome funcoes_globais, onde vai armazenar fun��es globais.
 * @defgroup funcoes_globais
 */

///Documenta��o da fun��o funcao_global
///@ingroup funcoes_globais
void funcao_global();
