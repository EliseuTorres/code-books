<?php
	function minha_fun��o() {
		echo "Esta fun��o recebeu " . func_num_args() . " Argumentos";
		for($k=0;$k<func_num_args();$k++) {
			echo "<br>Argumento " . ($k+1) . " = " . func_get_arg($k);
		}
	}
	minha_fun��o("a","n",10,5);
?>
