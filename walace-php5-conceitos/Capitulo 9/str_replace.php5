<?php
	$texto = "PHP 5 - Guia do Programador - Editora �rica";
	$vog = array("a","e","i","o","u");
	$s1 = str_replace($vog,"_",$texto,$cont);
	$s2 = str_ireplace("php","*","$texto",$cont2);
	echo "Texto original: $texto<br>";
	echo "str_replace: $s1 . N�mero de substiui��es: $cont <br>";
	echo "str_ireplace: " .  $s2 . " N�mero de substiui��es: $cont2<br>";
	// N�o funciona
	$texto = "ABCDEFGH";
	$s3 = stR_ireplace("a","*",$texto,$cont3);
	echo "<bR>n�o funciona::<br>str_ireplace: " .  $s3 . " N�mero de substiui��es: $cont3<br>";
	$s3 = stR_ireplace("a","*","a$texto",$cont3);
	echo "<bR>funciona::<br>str_ireplace: " .  $s3 . " N�mero de substiui��es: $cont3<br>";

?>
