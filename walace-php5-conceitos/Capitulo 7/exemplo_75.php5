<?php
	function executa_fun��o($func,$args) {
		foreach($func as $nome_func) {
			$ret .= $nome_func . ": " . $nome_func($args[0],$args[1]) . "<br>";
		}
		return $ret;
	} 

	// Vamos criar um array de fun��es
	$logica_1 =  'if($a>$b) { return "O Maior valor � $a"; } elseif($a==$b)	{return "S�o 	iguais";} else { return "O maior valor � $b";}';
	$logica_2 = 'return "$a elevado a $b = " . pow($a,$b);';
	$logica_3 = 'return "Raiz quadrada da soma dos quadrados de $a e $b � igual � " . sqrt($a*$a+$b*$b);';
	$a_func = array(create_function('$a,$b',$logica_1),
						create_function('$a,$b',$logica_2),
						create_function('$a,$b',$logica_3));
	$vlr = Array(4,3);
	echo "Resultado das fun��es: <br>"  . executa_fun��o($a_func,$vlr);
?>
