<?php
		$i = 10;  // Inteiro
		$nome = "Walace";  // String
		$falso = FALSE;  // Booleano
		$valor = 100.50; /// Ponto flutuante
		$nulo = NULL;
		echo '$i � do Tipo ' . gettype($i) . '<br>';
		echo '$nome � do Tipo ' . gettype($nome) . '<br>';
		echo '$falso � do Tipo ' . gettype($falso) . '<br>';
		echo '$nulo � do Tipo ' . gettype($nulo) . '<br>';
		echo '$valor � do Tipo ' . gettype($valor);
		if(is_scalar($nulo)) echo "<br>NULO � escalar tb";
		
		
?>
