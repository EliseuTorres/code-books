<?php
	$texto = "Este � um texto com \' e \" e \\\ ";
	echo $texto;
	echo "<br>";
	echo stripslashes($texto) . "\ ";
?>
