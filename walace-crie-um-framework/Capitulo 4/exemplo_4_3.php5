<?php
/**
 * Exemplo do uso da classe pagincao
 * temos um total de 1200 registros e estamos 
 * processando a p�gina 10
 */
include_once("framework/classes/classe_paginacao.inc");
// pagina��o
echo implode(" ",paginacao::paginar(1200,10));
?>