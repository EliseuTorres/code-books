<?php
	function marca_texto($_str,$_sw,$_bg="gray") {
	foreach($_sw as $_s) {
		$_str = eregi_replace("($_s)",'<span style="background-color:	'.$_bg.'">\\1</span>', $_str);
	}
	return $_str;
	}

	$_texto = <<<EOF
A fun�ao ereg() realiza uma busca conforme a express�o regular informada, 
retornando verdadeiro(TRUE) se a busca for bem sucedida (ou seja, se a express�o informada 
for encontrada na string) ou falso (FALSE) caso contr�rio. Opcionalmente � poss�vel armazenar
o resultado da busca (somente os elementos entre par�ntesis) em um array informado.
EOF;
	echo marca_texto($_texto,Array("express�o regular","TRUE"),"yellow");
		 
?>
