<?php
	define("VALOR",10);
	define("FRUTA","Manga",True);
	echo "Fruta = " . fruta; // ou Fruta ou FRUTA
	echo "<br>";
	echo "Valor = " . VALOR; // Ok
	echo "<br>";
	echo "Valor = " . Valor; // N�o ir� funcionar
    define("VALOR",990);
	echo VALOR;	
?>

