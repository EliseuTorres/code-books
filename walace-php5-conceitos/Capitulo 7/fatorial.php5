<?php
	function fatorial($n) {
		if($n<0) {
			return "N�o existe fatorial de n�mero negativo";
		}
		elseif($n<=1) {
			return 1;
		}
		else {
			return $n * fatorial($n-1);
		}
	}
	$v = 10;
	echo "Fatorial de $v = " . fatorial($v);
?>
