<?php
    echo "<b>Fun��o strstr:</b><br>";
	$dir=opendir("./"); 
	while($file=readdir($dir)) { 
 		if (strstr($file,".PHP5")) { 
     	   echo "$file<br>";    
		} 
	}
?>

