<?php
/**
 * Fun��o Fatorial 
 * Onde Fatorial(n) = n * Fatorial(n-1), se n<=1, Fatorial(n)=1
 * N�o existe Fatorial de n�meros negativos (n<0)
 * @return		int
*/	 
function fatorial($_num) {
		if($_num<0) {
			return FALSE;
		}
		elseif($_num<=1) {
			return 1;
		}
		return $_num * fatorial($_num-1);
}

$_f = new ReflectionFunction('fatorial'); 
// Mostra o nome da Fun��o e sua Documenta��o
echo "Fun��o : " . $_f->getName() . "<br/>";
	"Declarada no Arquivo:  " . $_f->getFileName();
echo "Documenta��o:<pre>" . $_f->getDocComment() . "</pre><br/>";

// O m�todo export mostra todos os dados da fun��o
echo "<pre><b>Utilizando ReflectionFunction::export</b>\n";
echo ReflectionFunction::export('fatorial');
echo "</pre>";
?>
