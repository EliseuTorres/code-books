<?php
	$dir=opendir("./"); 
	while($file=readdir($dir)) { 
 	    $texto.=$file . "; ";    
	}
    echo $texto . "<br>";
	echo "N�mero de ocorr�ncias de str: " . substr_count($texto,"str") . "<br>";
	echo "N�mero de ocorr�ncias de PHP5: " . substr_count($texto,"PHP5"); 	
?>

