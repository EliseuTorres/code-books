<?php
	$_dir = dir("./");
	echo "Diret�rio: " . $_dir->path . "<br/>Conte�do:<br/>";
	while (($_l=$_dir->read())!==FALSE) {
	   echo $_l . "<br/>";
	}
	echo "<br/>Retornando ao inicio...<br/>";
	$_dir->rewind();
	do {
	   $_str = readdir($_dir->handle);
	} while (substr($_str,0,1)=='.');
	echo readdir($_dir->handle) . "<br/>";
	$_dir->close();
	$_dir->rewind();
?> 
