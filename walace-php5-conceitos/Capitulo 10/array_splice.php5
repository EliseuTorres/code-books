<?php
	$_arr = Array("Rei","Rainha","Bispo","Pe�o");
	$_k1 = array_splice($_arr,-1,1,Array("Cavalo","Pe�o"));
	$_k2 = array_splice($_arr,4,0,Array("Torre"));
	echo "<pre>";
	print_r($_k1);
	print_r($_k2);
	print_r($_arr);
	echo "</pre>";
?>
