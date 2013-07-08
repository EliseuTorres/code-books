<?php
	function retira_acentos($valor) {
		$char = array("�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�",
     				  "�","�","�","�","�","�","�","�","�","�","�","�","�","�",
     				  "�","�","�","�","�","�");

  		$chart = array("c","C","a","A","a","A","a","A","a","A","e","E","e","E","e","E", 
     			 	   "i","I","i","I","i","I","o","O","o","O","o","O","o","O",
					   "u","U","u","U","u","U");


  		for($i=0;$i<sizeof($char);$i++) {
    		$valor = strtr($valor,$char[$i],$chart[$i]);
  		}

  		return $valor;
	}	
	
	$texto = "Esta � uma forma de retirarmos acentos do textos, por exemplo: ";
	$texto.= "�, �, �, �, �, �";
	echo $texto . "<br>";
	echo retira_acentos($texto);
?> 
