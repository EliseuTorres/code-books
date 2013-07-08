	<?php
		$_con  = new mysqli("localhost","root","","BD_PHP5");
		if(!$_con) {  
			echo "N�o foi possivel conectar ao MySQL. Erro #" .
					mysqli_connect_errno() . " : " . mysql_connect_error();
			exit;
		}
		// Clausula para inclus�o de Usuarios
		$_sql_i  = "INSERT INTO Usuario VALUES(NULL,?,?,?,?,?)";
		// Clausula para consulta
		$_sql_s  = "SELECT UserLogin, UserName FROM Usuario WHERE ";
		$_sql_s .= "userId = ?";

		// Preparar as clausulas
		$_qi = $_con->prepare($_sql_i);
		$_qs = $_con->prepare($_sql_s);
		// Informar quais vari�veis ser�o utilizadas como par�metros
		$_qi->bind_param('sssis',$_nome,$_login,$_senha,$_nivel,$_email);
		$_qs->bind_param('i',$_id);
		$_qs->bind_result($_l,$_n);
	
		// Incluir um usu�rio
		$_nome = "Paula Soares";
		$_login = "Paula";
		$_senha = "paula";
		$_nivel = 1;
		$_email = "paula@walace.com.br";
		if($_qi->execute()) {
			$_id = $_con->insert_id;   
			echo "incluido $_login como registro $_id<br/>";
		} 
		
		$_qi->close();

		// Listar os dados do usu�rios
		if($_qs->execute()) {
			$_qs->store_result();
			$_nr = $_qs->num_rows;
			if($_nr>0) {
				// Primeiro o cabe�alho com os campos da tabela
				echo "<table border=1>";
				echo "<tr bgcolor='#f0f0f0'>";
				$_res = $_qs->result_metadata();
				for($_i=0;$_i<$_res->field_count;$_i++) {
					$_f = $_res->fetch_field_direct($_i);
					echo "<td>" . $_f->name . "</td>";
				}														
				echo "</tr>";
				// Agora o resultado
				while($_row=$_qs->fetch()) {
					echo "<tr>";
					echo "<td>$_l</td><td>$_n</td>";
					echo "</tr>";
				}
				echo "</table>";
			}
		}	 
		
		$_qs->close();
		$_con->close();
	?>
