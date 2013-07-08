	<?php
		require_once("class_bd.inc");
		require_once("class_HTML.inc");
		require_once("class_usuario.inc");
		require_once("class_sessao.inc"); 
		require_once("class_permissao.inc");
		
		
		$_script = "man_permissao.php5";
		
		 
		/*PostgreSQL 
		$_con = new CONSULTA("postgresql");
		$_con->setUsuario("postgres");
		*/
		/*
		MySQL
		$_con = new CONSULTA();
		*/

		/* MySQLI */
		$_con = new CONSULTA("mysqli");
		$_con->setBD("BD_PHP5");		   
		$_con->conecta();
		
		$_usr = new USUARIO($_con);

		/* Primeramente verifica se uma sess�o foi aberta */
		$_sess = new sessao(TRUE);
		if($_sess->getVars("userid")===NULL) {
			// Usu�rio n�o autorizado		  
			echo "<script>location.href='login.php5';</script>";
			exit;
		}
		
		/* Verificar se o usu�rio tem permiss�o para acessar esta p�gina */
		$_p = new permissao($_con);
		if($_p->permissao($_script,$_sess->getVars("userNivel"))===FALSE) {
			echo "<p><b>Voc� n�o tem permiss�o para acessar esta p�gina...</b></p>";
			exit;
		}	  
		
		$_perm = new Permissao($_con);
		
		// OK
		
		$_html = new HTML();
		$_id[0] = $_html->AddTag("HTML");
		$_id[1] = $_html->AddTag("HEAD");
		$_html->AddTag("TITLE",NULL,TRUE,"PHP5 - Editora �rica - Manuten��o de Permiss�es");
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
			case 'CA':	// Altera��o
						if($_perm->buscar((int) $_POST["permid"])===FALSE) {
							echo "<script>alert('Pemiss�o n�o Cadastrada');</script>";
							$_opcao = "";
							break;
						}											  
			case 'CI':	// Inlcus�o
						$_perm->setpermDesc($_POST["permDesc"]);
						$_perm->setpermNivel($_POST["permNivel"]);						
						$_perm->setpermScript($_POST["permScript"]);
						if($_opcao=="CI") {
							if($_perm->Incluir()===TRUE) {
								echo "<script>alert('Permiss�o Incluida');</script>";
							} else {
								echo "<script>alert('Ocorreu um Erro na Inclus�o');</script>";
								echo "ERRO";
								exit;
								$_opcao = "I";
								break;
							}
						} else {
							if($_perm->Alterar()===TRUE) {
								echo "<script>alert('Permiss�o Alterada');</script>";
							} else {
								echo "<script>alert('Ocorreu um Erro na Altera��o');</script>";	 
								$_GET["permid"] = $_POST["permid"];
								$_opcao = "A";
								break;
							}
						}
						$_opcao = "";
						break;
			case 'CE':	// Exclus�o
						if($_perm->buscar((int) $_POST["permid"])===FALSE) {
							echo "<script>alert('Permiss�o n�o Cadastrada');</script>";
							$_opcao = "";
							break;
						}											  
						if($_perm->excluir()===TRUE) {
							echo "<script>alert('Permiss�o Excluida');</script>";
						} else {
							echo "<script>alert('Ocorreu um Erro na Exclus�o');</script>";
						}
						$_opcao = "";
						break;
		}
		

		/* Montar tabela com menu do lado esquerdo */
		$_tab_pr = $_html->AddTag("TABLE",Array("border"=>0,
							  		   		"cellspacing"=>0,
							  		   		"cellpadding"=>2,
											"width"=>800,
											"valign"=>"top"));
		$_tr_pr = $_html->AddTag("TR");
		$_html->AddTag("TD",Array("valign"=>"top"),TRUE,$_p->menu($_sess->getVars("userNivel")));
		$_td_pr = $_html->AddTag("TD",NULL);


		switch($_opcao) {
			case 'A':	// Altera��o (mesmo formul�rio de Inclus�o)
						if($_perm->buscar((int) $_GET["permid"])===FALSE) {
							echo "<script>alert('Permiss�o n�o Cadastrada');</script>";
							$_opcao = "";
							break;
						}											  
			case 'I':	// Incluir ou alterar
						$_s = $_html->AddTag("SCRIPT",NULL);
						$_html->AddText($_s,"   var campos = new Array(0,1);\n");
						$_html->AddText($_s,"   var nomes  = new Array('Descri��o','Script');\n");
						$_html->AddText($_s,"   var tipos  = new Array(8,8);\n");
						$_html->AddText($_s,"   var status = new Array(1,1);\n");
						$_html->EndTag($_s);
						$_html->AddTag("P",NULL,TRUE,"<b>" . ($_opcao=="I" ? "Inclus�o de Permiss�o" : "Altera��o dos dados de uma Permiss�o") . "</b>");
						$_f = $_html->AddTag("FORM",Array("name"=>"permissao",
												"method"=>"POST",
												"action"=>$_SERVER["PHP_SELF"],
												"onSubmit"=>"return valida_form(0,campos,nomes,tipos,status);"));
						$_tab = $_html->AddTag("TABLE",Array("border"=>0,
							  		    				"cellspacing"=>0,
							  		    				"cellpadding"=>2,
										  				"width"=>500,
										  				"valign"=>"top"));
						// Descri��o
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Descri��o:");
						$_td = $_html->AddTag("TD");						
						$_html->AddTag("INPUT",Array("name"=>"permDesc",
													"size"=>30,
													"type"=>"text",
													"value"=>$_perm->getpermDesc()),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr);
						// Script
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Nome do Script:");
						$_td = $_html->AddTag("TD");						
						$_html->AddTag("INPUT",Array("name"=>"permScript",
													"size"=>30,
													"type"=>"text",
													"value"=>$_perm->getpermScript()),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr); 
						// Nivel
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"N�vel do Usu�rio:");
						$_td = $_html->AddTag("TD");						
						$_sel = $_html->AddTag("SELECT",Array("name"=>"permNivel"));
						$_html->AddTag("OPTION",Array("value"=>1,"_"=>($_perm->getpermNivel()==1 ? "SELECTED" : "")),TRUE,"Adiministrador");
						$_html->AddTag("OPTION",Array("value"=>5,"_"=>($_perm->getpermNivel()==5 ? "SELECTED" : "")),TRUE,"Usu�rio");
						$_html->EndTag($_sel);
						$_html->EndTag($_td);
						$_html->EndTag($_tr); 
						// Bot�o OK
						$_tr = $_html->AddTag("TR");
						$_td = $_html->AddTag("TD", Array("colspan"=>2,"align"=>"right"));						
						$_html->AddTag("INPUT",Array("name"=>"ok",
													"type"=>"submit",
													"value"=>"Confirmar"),TRUE);
						$_html->AddTag("INPUT",Array("name"=>"permid",
													"value"=>$_GET["permid"],
													"type"=>"hidden"),TRUE);
						$_html->AddTag("INPUT",Array("name"=>"opcao",
													"value"=>"C" . $_opcao,
													"type"=>"hidden"),TRUE);
						$_html->EndTag($_td);
						$_html->EndTag($_tr);
						$_html->EndTag($_tab);
						$_html->EndTag($_f);
						break;
			case 'E':	// Confirmar Exclus�o 
						if($_perm->buscar((int) $_GET["permid"])===FALSE) {
							echo "<script>alert('Permiss�o n�o Cadastrada');</script>";
							$_opcao = "";
							break;
						}											  
						$_html->AddTag("P",NULL,TRUE,"<b>Exclus�o de Permiss�o</b>");
						$_f = $_html->AddTag("FORM",Array("name"=>"permissao",
												"method"=>"POST",
												"action"=>$_SERVER["PHP_SELF"]));
						$_tab = $_html->AddTag("TABLE",Array("border"=>0,
							  		    				"cellspacing"=>0,
							  		    				"cellpadding"=>2,
										  				"width"=>500,
										  				"valign"=>"top"));
						// Descri�o
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Descri��o:");
						$_td = $_html->AddTag("TD",NULL,TRUE,$_perm->getpermDesc());						
						$_html->EndTag($_tr);
						// Nome do Script
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"Script:");
						$_td = $_html->AddTag("TD",NULL,TRUE,$_perm->getpermScript());						
						$_html->EndTag($_tr);
						// Nivel
						$_tr = $_html->AddTag("TR");
						$_html->AddTag("TD",NULL,TRUE,"N�vel:");
						$_td = $_html->AddTag("TD",NULL,TRUE,$_perm->getpermNivel());						
						$_html->EndTag($_tr);
						// Bot�o OK
						$_tr = $_html->AddTag("TR");
						$_td = $_html->AddTag("TD", Array("colspan"=>2,"align"=>"right"));						
						$_html->AddTag("INPUT",Array("name"=>"ok",
													"type"=>"submit",
													"value"=>"Confirmar Exclus�o"),TRUE);
						$_html->AddTag("INPUT",Array("name"=>"permid",
													"value"=>$_GET["permid"],
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
						$_html->addText($_td_pr,$_perm->listar());
		}
		
		$_html->EndTag($_td_pr);
		$_html->EndTag($_tr_pr);
		$_html->EndTag($_tab_pr);
		$_html->AddTag("P",NULL,TRUE,"[{$_sess->getVars("userName")}]");
		$_html->EndTag($_id[1]);
		$_html->EndTag($_id[0]);
		echo $_html->toHTML();
		
		$_con->close();													   
	
	?>