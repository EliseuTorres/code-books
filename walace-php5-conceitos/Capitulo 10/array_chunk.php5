<?php
	$_arr = Array("cor"=>"Verde","nome"=>"Walace",
						"Cor"=>"Branco","cIdaDe"=>"S�o Paulo");	
	echo "<PRE>";
	print_r(array_chunk($_arr,2));
	print_r(array_chunk($_arr,2,TRUE));
	echo "</PRE>";
?>
