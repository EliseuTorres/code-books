<?php
	$texto = "Este � um texto\ncom line-feed como quebra\n de p�gina";
	echo "sem nl2br():<br>$texto<br><br>Com nl2br():<br>" . nl2br($texto);
?>
