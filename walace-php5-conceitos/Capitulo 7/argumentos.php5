<?php
		function minha_fun��o($n,$a,$vlr) {
			echo "\$n = $n <br>";
			echo "\$a = $a <br>";
			echo "\$vlr = $vlr <br>";
			if(func_num_args()>3) {
			  for($k=3;$k<func_num_args();$k++) {
				echo "Argumento " . ($k+1) . " = " . func_get_arg($k) . "<br>";
			  }
			}
		}

		minha_fun��o("a","b","c",10,35,"Teste");
?>
