<?php
    echo "<b>Fun��o stristr:</b><br>";
	$dir=opendir("./"); 
	while($file=readdir($dir)) { 
 		if (stristr($file,".PHP5")) { 
     	   echo "$file<br>";    
		} 
	}
?>

