<?php
	function retira_acentos($valor) {
		$char = array("�" => "c","�" => "C","�" => "a","�" => "A",
		              "�" => "a","�" => "A","�" => "a","�" => "A",
					  "�" => "a","�" => "A","�" => "e","�" => "E",
					  "�" => "e","�" => "E","�" => "e","�" => "E",
     				  "�" => "i","�" => "I","�" => "i","�" => "I",
					  "�" => "i","�" => "I","�" => "o","�" => "O",
					  "�" => "o","�" => "O","�" => "o","�" => "O",
					  "�" => "o","�" => "O","�" => "u","�" => "U",
					  "�" => "u","�" => "U","�" => "u","�" => "U");

  		return strtr($valor,$char);
	}	
	
	$texto = "Esta � uma forma de retirarmos acentos do textos, por exemplo: ";
	$texto.= "�, �, �, �, �, �";
	echo $texto . "<br>";
	echo retira_acentos($texto);
?> 
