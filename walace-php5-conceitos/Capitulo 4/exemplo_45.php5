<?php
	$valor = 10;
	function dobro() {
	    $valor = 6;
		$valor = $valor * 2;
		echo "\$valor na fun��o " . __FUNCTION__ . " = " . $valor;
	}
	echo "\$valor = $valor <br>";
	dobro();
	echo "<br>\$valor = $valor <br>";
?>
