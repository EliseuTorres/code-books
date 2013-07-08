<html>
<head>
  <title>PHP5 - Guia do Programador - Exemplo de um formul�rio WEB</title>
</head>
	<?php
		function lista_estados($nome_campo="USR_UF",$MULT=FALSE) {
			$ufs = array("SP" => "S�o Paulo",
							"ES" => "Esp�rito Santo",
							"RJ" => "Rio de Janeiro",
							"MG" => "Minas Gerais",
							"RS" => "Rio Grande do Sul",
							"AM" => "Amazonas",
							"CE" => "Cear�",
							"BA" => "Bahia",
							"MT" => "Mato Grosso");
			$ret = "<SELECT NAME='$nome_campo'";
			$ret.= ($MULT) ? " MULTIPLE" : "";
			$ret.= ">\n";
			foreach($ufs as $chv => $vlr) {
					$ret.=	 "<OPTION VALUE='$chv'>$vlr</OPTION>\n";
			}
			$ret.= "</SELECT>\n";
			return $ret;
		}
	?>
<body>
<form name="usr" method="post" action="cadastra_usuario.php5">
 <table border="0" cellpadding="3" cellspacing="0" width="100%">
  			<tr>
			  <td height="30" bgcolor="#8CDAFF">
					<b>PHP 5 - Guia do Programador: Cadastro de Usu�rio</b>
			  </td>
			  <td align="right" bgcolor="#8CDAFF">
			    <?=date("d-m-Y H:i:s")?>&nbsp;
			  </td>
			</tr>
 </table>
 <table border="0" cellpadding="5" cellspacing="5">
  			<tr>
			  <td colspan=2 height="30"><font color="#0000A0">
					<b>Informe seus dados:</b></font>
			  </td>
			</tr>
			<tr>
			<td width="25%" height="30">Nome:</td>
  			<td height="30" >
				<input type="text" name="USR_NOME" size="30">
			</td>
			</tr>
  			<td width="10%" height="30" valign="top">Endere�o:</td>
  			<td  height="30" >
				<TEXTAREA NAME="USR_ENDERE�O" COLS="60" ROWS="5">
				</TEXTAREA>
			</td>
			</tr>
			</tr>
			<tr>
  			<td width="10%" height="30">Bairro:</td>
  			<td height="30">
				<input type="text" name="USR_BAIRRO" size="30">
			</td>
			</tr>
			<tr>
  			<td width="10%" height="30" class="login">Cidade:</td>
  			<td height="30">
				<input type="text" name="USR_CIDADE" size="30">
			</td>
			</tr>
			<tr>
  			<td width="10%" height="30" class="login">Estado:</td>
  			<td height="30">
				<?=lista_estados();?>
			</td>
			</tr>
			<tr>
  			<td width="10%" height="30">E-mail:</td>
  			<td height="30" >
				<input type="text" name="USR_EMAIL" size="30" >
			</td>
			</tr>
			<tr>
  			<td width="10%" height="30">Login:</td>
  			<td height="30" >
				<input type="text" name="USR_LOGIN" size="10">
			</td>
			</tr>
			<tr>
  			<td width="10%" height="30">Senha:</td>
  			<td height="30" >
				<input type="password" name="USR_SENHA" size="10">
			</td>
			</tr>
			<tr>
  			<td width="20%" height="30">Confirma��o de Senha:</td>
  			<td height="30" align="left" >
				<input type="password" name="USR_SENHA2" size="10">
			</td>
			</tr>
			<tr height="60" valign="bottom">
  			<td width="20%" ></td>
  			<td height="30" valign="bottom">
			<input type="submit" value="     OK     ">&nbsp;&nbsp;&nbsp;
			<input type="reset" value= "   Limpar   ">
			</td>
			</tr>
  </table>
</form>
</body>
</html>
