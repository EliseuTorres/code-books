<?php
	echo "Chamando uma fun��o";
	minha_fun��o();
	echo "Fim";
	function minha_fun��o() {
		echo "<br>";
		for($i=0;$i<5;print "<br>",$i++) {
			echo "o Quadrado de $i  � " . ($i*$i);
		}
	}
?>




