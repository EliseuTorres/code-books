<?php
	function minha_fun��o() {
		echo "Fun��o " . __FUNCTION__;
		echo "<br>"; 
	}

	function dobro($valor) {
		return $valor*2;
	}

	$func = "minha_fun��o";	
	$func();
	$func = "dobro";
 	$vlr = 12;
 	echo "O dobro  de $vlr � " . $func($vlr);
?>
