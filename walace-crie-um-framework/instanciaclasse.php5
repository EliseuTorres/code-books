<?php
/**
 * Instancia a Classe definida e executa o m�todo processaAcao()
 */
include_once("framework/includes/autoload.inc");
include_once("framework/classes/classe_bancodados.inc");
include_once("framework/classes/classe_html.inc");
include_once("framework/classes/classe_base.inc");
include_once("framework/classes/classe_paginacao.inc");
include_once("framework/classes/classe_formulario.inc");
include_once("framework/includes/configbd.inc");
include_once("framework/includes/autenticacao.inc");

$_path = pathinfo($_SERVER['PHP_SELF']);
if(stripos($_SESSION['AUTORIZADOS'],$_path['basename'])===false&&$_path['basename']!='index.php5') {
	die("<span style='color:red;font-weight:bold;font-size:15px;'>Voc� n�o tem Permiss�o para Acessar Este programa</span>");
}
include_once($_classe["arquivo"]);

setcookie("ULTIMO_PROGRAMA",$_SERVER['PHP_SELF'],time()+365*86400);

// Incluir no historico
$_hist = new historico($_bd);
$_hist->incluirHistorico($_path['basename']);
//

$_cl = new $_classe["nome"]($_bd);
return $_cl->processaAcao();
?>