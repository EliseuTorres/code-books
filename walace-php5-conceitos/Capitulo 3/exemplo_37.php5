<?php
	$a = array("cliente 1", 3 => "cliente 2", "cliente 3");
	$a1 = array("cliente 1" => 1000, "cliente 2" => 5000, "cliente 3" => 0);
	$a2 = array("cliente 1" => 
				array("endere�o" => "Rua x, no. 10", 
						"bairro" => "Vila Maria",
						"cidade" => "S�o Paulo"),
			"cliente 2" =>	
				array("endere�o" => "Rua y, no. 102 ", 
						"bairro" => "Gl�ria",
						"cidade" => "Vila Velha"),
			"cliente 3" =>	
				array("endere�o" => "Rua z, no. 2 ", 
						"bairro" => "Centro",
						"cidade" => "Curitiba"));
	echo "<pre>";
	print_r($a);
	print_r($a1);
	print_r($a2);
	echo "</pre>";
?>	
