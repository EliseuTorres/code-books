	<?php
		require_once("class_bd.inc");
		require_once("class_HTML.inc");
		require_once("class_usuario.inc");
		require_once("class_sessao.inc");
		
		/* 
		PostgreSQL 
		$_con = new CONSULTA("postgresql");
		$_con->setUsuario("postgres");
		
		MySQL
		$_con = new CONSULTA();
		*/

		/* MySQLI */
		$_con = new CONSULTA("mysqli");		
		$_con->setBD("BD_PHP5");
		$_con->conecta();		   
		
		$_usr = new USUARIO($_con);

		$_sess = new sessao(TRUE);
		if($_sess->getVars("userid")===NULL ||
			$_sess->getVars("userNivel")!=1) {
			// Usu�rio n�o autorizado		  
			echo "<script>location.href='login.php5';</script>";
			exit;
		}
		 

		$_html = new HTML();
		$_id[0] = $_html->AddTag("HTML");
		$_id[1] = $_html->AddTag("HEAD");
		$_html->AddTag("TITLE",NULL,TRUE,"PHP5 - Editora �rica");
		$_html->AddTag("SCRIPT",Array("Language"=>"JavaScript",
									"src"=>"funcoes.js"),TRUE);
		$_html->EndTag($_id[1]);									
		$_id[1] = $_html->AddTag("BODY",Array("width"=>600));

		// Op��o escolhida pelo Usu�rio (I,A ou E) ou (CA, CI ou CE)
		if(isset($_GET["opt"])) {
			$_opcao = $_GET["opt"];
		} elseif(isset($_POST["opcao"])) {
			$_opcao =  $_POST["opcao"];  
		}
				
		switch($_opcao) {
			case 'CA':	// Altera��o dos dados		  
						if($_usr->buscar((int) $_POST["userid"])===FALSE) {
							echo "<script>alert('Usu�rio n�o Cadastrado');</script>";
							$_opcao = "";
							break;
						}											  
			case 'CI':	// Inlcus�o de um novo usu�rio
						$_usr->setUserName($_POST["userName"]);
						$_usr->setUserLogin($_POST["userLogin"]);						
						$_usr->setUserEmail($_POST["userEmail"]);
						$_usr->setUserPassw($_POST["userPassw"]);
						$_usr->setUserNivel($_POST["userNivel"]);
						if($_opcao=="CI") {
							if($_usr->Incluir()===TRUE) {
								echo "<script>alert('Usu�rio Incluido');</script>";
							} else {
								echo "<script>alert('Ocorreu um Erro na Inclus�o');</script>";
								echo "ERRO";
								exit;
								$_opcao = "I";
								break;
							}
						} else {
							if($_usr->Alterar()===TRUE) {
								echo "<script>alert('Usu�rio Alterado');</script>";
							} else {
								echo "<script>alert('Ocorreu um Erro na Altera��o');</script>";	 
								$_GET["userid"] = $_POST["userid"];
								$_opcao = "A";
								break;
							}
						}
						$_opcao = "";
						break;
			case 'CE':	// Exclus�o
						if($_usr->buscar((int) $_POST["userid"])===FALSE) {
							echo "<script>alert('Usu�rio n�o Cadastrado');</script>";
							$_opcao = "";
							break;
						}											  
						if($_usr->excluir()===TRUE) {
							echo "<script>alert('Usu�rio Excluido');</script>";
						} else {
							echo "<script>alert('Ocorreu um Erro na Exclus�o');</script>";
						}
						$_opcao = "";
						break;
		}
		
		switch($_opcao) {
			case 'A':	// Altera��o (mesmo formul�rio de Inclus�o)
						if($_usr->buscar((int) $_GET["userid"])===FALSE) {
							echo "<script>alert('Usu�rio n�o Cadastrado');</script>";
							$_opcao = "";
							break;
						}											  
			case 'I':	// Incluir um usu�rio ou alterar seus dados
						$_s = $_html->AddTag("SCRIPT",NULL);
						$_html->AddText($_s,"   var campos = new Array(0,1,3,4,5);\n");
						$_html->AddText($_s,"   var nomes  = new Array('Nome','E-mail','Login','Senha','Confirma��o de Senha');\n");
						$_html->AddText($_s,"   var tipos  = new Array(8,4,9,9,10);\n");
						$_html->AddText($_s,"   var status = new Array(1,1,1,1,1);\n");
						$_html->EndTag($_s);
						$_html->AddTag("P",NULL,TRUE,"<b>" . ($_opcao=="I" ? "Inclus�o de usu�rio" : "Altera��o dos dados de um Usu�rio") . "</b>");
						$_f = $_html->AddTag("FORM",Array("name"=>"usuario",
												"method"=>"POST",
												"action"=>$_SERVER["PHP_SELF"],
												"onSubmit"=>"return valida_form(0,campos,nomes,tipos,status);"));
						$_tab = $_html->AddTag("TABLE",Array("border"=>0,
							  		    				"cellspacing"=>0,
							  		    				"cellpadding"=>2,
										  				"width"=>500,
										  				"valign"=>"top"));
						// Nome do usu�rio
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Nome:");
						$_td = $_html->AddTag("TD");						
						$_html->AddTag("INPUT",Array("name"=>"userName",
													"size"=>30,
													"type"=>"text",
													"value"=>$_usr->getUserName()),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr);
						// Endere�o de E-mail
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"E-mail:");
						$_td = $_html->AddTag("TD");						
						$_html->AddTag("INPUT",Array("name"=>"userEmail",
													"size"=>30,
													"type"=>"text",
													"value"=>$_usr->getUserEmail()),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr); 
						// Nivel
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Nivel:");
						$_td = $_html->AddTag("TD");						
						$_sel = $_html->AddTag("SELECT",Array("name"=>"userNivel"));
						$_html->AddTag("OPTION",Array("value"=>1,"_"=>($_usr->getuserNivel()==1 ? "SELECTED" : "")),TRUE,"Adiministrador");
						$_html->AddTag("OPTION",Array("value"=>5,"_"=>($_usr->getuserNivel()==5 ? "SELECTED" : "")),TRUE,"Usu�rio");
						$_html->EndTag($_sel);
						$_html->EndTag($_td);
						$_html->EndTag($_tr); 
						// Login
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Login:");
						$_td = $_html->AddTag("TD");						
						$_html->AddTag("INPUT",Array("name"=>"userLogin",
													"size"=>20,
													"type"=>"text",
													"value"=>$_usr->getUserLogin()),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr);
						// Senha
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Senha:");
						$_td = $_html->AddTag("TD");						
						$_html->AddTag("INPUT",Array("name"=>"userPassw",
													"size"=>20,
													"type"=>"password",
													"value"=>$_usr->getUserPassw()),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr);
						// Confirma��o da senha
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Confirma��o de Senha:");
						$_td = $_html->AddTag("TD");						
						$_html->AddTag("INPUT",Array("name"=>"userCPassw",
													"size"=>20,
													"type"=>"password",
													"value"=>$_usr->getUserPassw()),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr);  
						// Bot�o OK
						$_tr = $_html->AddTag("TR");
						$_td = $_html->AddTag("TD", Array("colspan"=>2,"align"=>"right"));						
						$_html->AddTag("INPUT",Array("name"=>"ok",
													"type"=>"submit",
													"value"=>"Confirmar"),TRUE);
						$_html->AddTag("INPUT",Array("name"=>"userid",
													"value"=>$_GET["userid"],
													"type"=>"hidden"),TRUE);
						$_html->AddTag("INPUT",Array("name"=>"opcao",
													"value"=>"C" . $_opcao,
													"type"=>"hidden"),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr);
						$_html->EndTag($_tab);
						$_html->EndTag($_f);
						break;
			case 'E':	// Confirmar Exclus�o do Usu�rio
						if($_usr->buscar((int) $_GET["userid"])===FALSE) {
							echo "<script>alert('Usu�rio n�o Cadastrado');</script>";
							$_opcao = "";
							break;
						}											  
						$_html->AddTag("P",NULL,TRUE,"<b>Exclus�o de usu�rio</b>");
						$_f = $_html->AddTag("FORM",Array("name"=>"usuario",
												"method"=>"POST",
												"action"=>$_SERVER["PHP_SELF"]));
						$_tab = $_html->AddTag("TABLE",Array("border"=>0,
							  		    				"cellspacing"=>0,
							  		    				"cellpadding"=>2,
										  				"width"=>500,
										  				"valign"=>"top"));
						// Nome do usu�rio
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Nome:");
						$_td = $_html->AddTag("TD",NULL,TRUE,$_usr->getUserName());						
						$_html->EndTag($_tr);
						// Endere�o de E-mail
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"E-mail:");
						$_td = $_html->AddTag("TD",NULL,TRUE,$_usr->getUserEmail());						
						$_html->EndTag($_tr);
						// Login
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Login:");
						$_td = $_html->AddTag("TD",NULL,TRUE,$_usr->getUserLogin());						
						$_html->EndTag($_tr);
						// Bot�o OK
						$_tr = $_html->AddTag("TR");
						$_td = $_html->AddTag("TD", Array("colspan"=>2,"align"=>"right"));						
						$_html->AddTag("INPUT",Array("name"=>"ok",
													"type"=>"submit",
													"value"=>"Confirmar Exclus�o"),TRUE);
						$_html->AddTag("INPUT",Array("name"=>"userid",
													"value"=>$_GET["userid"],
													"type"=>"hidden"),TRUE);
						$_html->AddTag("INPUT",Array("name"=>"opcao",
													"value"=>"CE",
													"type"=>"hidden"),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr);
						$_html->EndTag($_tab);
						$_html->EndTag($_f);
						break;
			default:
						$_html = new HTML();
						$_html->AddTag("P",NULL,TRUE,"<b>Rela��o de Usu�rios</b>");
						$_id[2] = $_html->AddTag("DIV");
						$_html->addText($_id[2],$_usr->listar());
						$_html->EndTag($_id[2]);
		}
		
		$_html->AddTag("P",NULL,TRUE,"[{$_sess->getVars("userName")}]");
		$_html->EndTag($_id[1]);
		$_html->EndTag($_id[0]);
		echo $_html->toHTML();
		
		$_con->close();													   
	
	?>