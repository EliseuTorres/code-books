<?php
	function quadrado($valor) {
		return pow($valor,2);
	}

	if(function_exists("quadrado")) {
		echo "A fun��o Quadrado existe e o resultado de quadrado(5) � " .
			quadrado(5) . "<br>";
	}

	if(function_exists("mysql_connect")) {
		echo "A fun��o mysql_connect est� disponivel <br>";
	}

	if(function_exists("minha_fun��o")) {
		echo "A fun��o minha_fun��o existe";
	}
	else {
		echo "oops.. A fun��o minha_fun��o n�o existe...";
	}

?>
