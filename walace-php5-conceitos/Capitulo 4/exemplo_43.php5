<?php
	$var = "Carol";
	$nome =  $var; // Atribui��o direta (c�pia)
	$Nome = & $var; // Atribui��o por referencia
	$nome = "Isabelle"; // s� modifica $nome, $var continua = "Carol"
	$Nome = "Anna Carolina"; // $var � modificada tamb�m
	echo "\$var  = $var <br>";  
	echo "\$nome = $nome <br>";
	echo "\$Nome = $Nome <br>";
?>
