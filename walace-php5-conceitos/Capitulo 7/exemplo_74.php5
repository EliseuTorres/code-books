<?php
	// Cria a fun��o
	$func = create_function('$valor,$exp','return "$valor elevado a $exp � igual � " . pow($valor,$exp) . "<br>";');
		
	echo "Nome da fun��o: $func  <br>";
	echo $func(13,5);
	echo $func(5,7);
	echo $func(2,10);
?>
