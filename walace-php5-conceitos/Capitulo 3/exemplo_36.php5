<?php
	$s1 =  "Titulo: \"PHP5 - Guia do Programador\" ";
	$s2 = <<< EOL
Exemplo da sintaxe heredoc, os caracteres escape
Funcionam, por exemplo \\ (barra invertida) e \$,
Al�m disto a expans�o de vari�veis tamb�m.
\$s1  = $s1 
EOL;
	echo "$s1<br><pre>$s2</pre>";
?>
