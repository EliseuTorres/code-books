<?php
	// Retorna o alfabeto em min�sculas
	for($i=97;$i<123;$i++) {
		echo chr($i) . " ($i)" . ($i<122 ? ", "  : "");
	}
?>
