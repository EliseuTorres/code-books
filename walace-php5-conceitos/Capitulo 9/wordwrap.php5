<?php
	$texto = "A fun��o wrodwrap insere na string informada o caracter de
			quebra de linha \\n (ou um outro caracter qualquer, por exemplo
			<BR>), a cada n caracteres (o padr�o � 75). O par�metro corte
			serve para for�armos a quebra mesmo para palavras extremamente
			exxxxxxxxteeeeeeeeeeeeenssssssssssssssaaaaaaaaaaasssssssss.";
	$texto = htmlentities($texto);
	echo wordwrap($texto);
	echo "<br><br><b>Sem o par�metro corte:</b><br>";
	echo wordwrap($texto,30,"<br/>");
	echo "<br><br><b>Cem o par�metro corte:</b><br>";
	echo wordwrap($texto,30,"<br/>",TRUE);
?>
