<?php
  	setlocale(LC_TIME,'pt_BR');
	echo date("F j, Y, g:i a") . "<br/>";                
	echo date("m.d.y") . "<br/>";
	echo date("j, n, Y") . "<br/>";
	echo date("Ymd") . "<br/>";
	echo date('h-i-s, j-m-y, it is w Day z ') . "<br/>";
	echo date("D M j G:i:s T Y") . "<br/>";
	echo date("H:i:s") . "<br/>";
	if(date("L")==TRUE) {
		echo  date("Y") . "  � um ano bissexto";
	}
	else  {
		echo date("Y") . " n�o � um ano bissexto";
	}
	echo "<br/>";
	$dia_sem = Array("Domingo", "Segunda", "Ter�a", "Quarta",
					 "Quinta", "Sexta","S�bado");
	$hj = date("w");
	echo "Hoje � " . $dia_sem[$hj] .  " e amanh� ser� " . 
			($hj==6 ? $dia_sem[0] : $dia_sem[++$hj]);
?>
