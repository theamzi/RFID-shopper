<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Laboration 1 - Erik Andersson</title>		
		<style type="text/css">
		
            <?php
include 'connectdb.php';
include 'functions.php';
include 'css.css';



?>
		</style>
        
  <a href="saldo.php">Saldo</a>
        <a href="ladda.php">Ladda</a>
        <a href="handla.php">Handla</a>
        <a href="index.php">Registrera</a>
	</head>		

	<body>
        <form action="saldo.php" method="post" class="stilmall">
        
<h1>Saldo</h1>        
        
        <?php

echo "<h2>";
//Hämtar variabeln som visar saldo för läst kort
echo "Ditt saldo på kortet är $visa_saldo SEK";


echo "</h2>";


            ?>
        </form>
	</body>
</html>








