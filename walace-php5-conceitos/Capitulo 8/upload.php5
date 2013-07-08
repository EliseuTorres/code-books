<html>
<head>
	<title>PHP5 - Guia do Programador - Exemplo de um formul�rio WEB com 		Upload de arquivo</title>
</head>
<body>
<table border="0" cellpadding="3" cellspacing="0" width="100%">
	<tr>
	  <td height="30" bgcolor="#8CDAFF">
		<b>PHP 5 - Guia do Programador: Upload de Arquivo - 								Resultado</b>
	  </td>
	  <td align="right" bgcolor="#8CDAFF">
	    <?=date("d-m-Y H:i:s")?>&nbsp;
	  </td>
	</tr>
</table>
<?php
	/* 	upload.php5
		Valida��o de arquivo enviado pelo usu�rio
		Walace Soares
		Janeiro de 2004
	*/
	// 1�. Definir os par�metros de teste
	$tamanho_maximo = 100000; // em bytes
	$tipos_aceitos = array("image/gif",
								"image/pjpeg",
								"image/x-png",
								"image/bmp");
	// 2�. Validar o arquivo enviado
	$arquivo = $_FILES['ARQUIVO'];
	if($arquivo['error'] != 0) {
		echo '<p><b><font color="red">Erro no Upload do arquivo<br>';
		switch($arquivo['erro']) {
		case  UPLOAD_ERR_INI_SIZE:
						echo 'O Arquivo excede o tamanho m�ximo permitido';
						break;
		case UPLOAD_ERR_FORM_SIZE:
				echo 'O Arquivo enviado � muito grande';
				break;
		case  UPLOAD_ERR_PARTIAL:
				echo 'O upload n�o foi completo';
				break;
		case UPLOAD_ERR_NO_FILE:
				echo 'Nenhum arquivo foi informado para upload';	
				break;
		}
		echo	'</font></b></p>';
	  	exit;
	}
	if($arquivo['size']==0 OR $arquivo['tmp_name']==NULL) {
		echo '<p><b><font color="red">Nenhum arquivo enviado
				</font></b></p>';
		exit;
	}
	if($arquivo['size']>$tamanho_maximo) {
		echo '<p><b><font color="red">O Arquivo enviado � muito grande
			(Tamanho M�ximo = ' . $tamaho_maximo .	'</font></b></p>';
		exit;
	}
	if(array_search($arquivo['type'],$tipos_aceitos)===FALSE) {
		echo '<p><b><font color="red">O Arquivo enviado n�o � do tipo (' . 
				$arquivo['type'] . ') aceito 					para upload. 
				Os Tipos Aceitos S�o:	</font></b></p>';
		echo '<pre>';
		print_r($tipos_aceitos);
		echo '</pre>';
		exit;
	}
	// Agora podemos copiar o arquivo enviado
	$destino = 'C:\\Inetpub\\wwwroot\\PHP5\\Capitulo 8\\arquivos_upload\\' . $arquivo['name'];
	if(move_uploaded_file($arquivo['tmp_name'],$destino)) {
		// Tudo Ok, mostramos os dados 
		echo  '<p><font color="navy"><b>';
		echo 'O Arquivo foi carregado com sucesso!</b></font></p>';
		echo "<img src='$destino' border=0>";
	}
	else {
		echo '<p><b><font color="red">Ocorreu um erro durante o upload 						</font></b></p>';
	}
?>
</body>
</html>
