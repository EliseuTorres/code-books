<?php
	echo "Diret�rio Atual: " . getcwd() .  "<br/> ";
	$_dir = "../Capitulo 10";
	if(chdir($_dir)===FALSE) {
		echo "O Diret�rio $_dir n�o existe ou voc� n�o tem permiss�o..";
	}
	else {
		echo "Diret�rio Atual: " . getcwd() .  "<br/> ";
	}
?> 
 
