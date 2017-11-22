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

    
     
        <script type="text/javascript">
		function refresh()
			{
				var
					$http,
					$self = arguments.callee;

				if (window.XMLHttpRequest) {
					$http = new XMLHttpRequest();
				} else if (window.ActiveXObject) {
					try {
						$http = new ActiveXObject('Msxml2.XMLHTTP');
					} catch(e) {
						$http = new ActiveXObject('Microsoft.XMLHTTP');
					}
				}

				if ($http) {
					$http.onreadystatechange = function()
					{
						if (/4|^complete$/.test($http.readyState)) {
							document.getElementById('mysql').innerHTML = $http.responseText;
							setTimeout(function(){$self();}, 100);
						}
					};
					$http.open('GET', 'refresh.php' + '?' + new Date().getTime(), true);
					$http.send(null);
				}

			}
</script>			
<script type="text/javascript">
			setTimeout(function() {refresh();}, 100);
			
</script>
	<body>
      <div id="mysql" class="mysql"> </div>
        

   
		<form action="ladda.php" method="post" class="stilmall">
		<h1>Ladda ditt kort</h1>
		<label>
			<span>Hur mycket vill du ladda kortet</span>
			<input type="knapp" name="knapp" value="Ange kod här"/><br />	
		</label>
		<br>
		<input type="submit" name="form" class="button" value="Ladda" />
		
	

	<?php


// Hämtar värde för specific kod och adderar med nuvarande saldo
$saldo = ($credit + $visa_saldo);
$saldo2 = ($credit2 + $visa_saldo);
$saldo3 = ($credit3 + $visa_saldo);

//Sätter variabler för uppdateringen av saldo till nuvarande kort
$update = "UPDATE card_credit SET value = '$saldo' WHERE card_id='$current_card'";
$update2 = "UPDATE card_credit SET value = '$saldo2' WHERE card_id='$current_card'";
$update3 = "UPDATE card_credit SET value = '$saldo3' WHERE card_id='$current_card'";


//Beroende på vilken av de 3 korrekta koderna som införs körs en uppdatering i db annars händer inget
if(isset($_POST['knapp'])){
	 if($_POST['knapp'] == $refill){
        
        		if($conn = connect_db()) {
			$var=$conn->query($update);
			}
			
			
			echo "Ditt kort har laddats med $credit SEK";
           
         
         
         }
			else if ($_POST['knapp'] == $refill2){
              
              		if($conn = connect_db()) {
			$var=$conn->query($update2);
			}
			
			
			echo "Ditt kort har laddats med $credit2 SEK";
           
                
                }
    else if ($_POST['knapp'] == $refill3){
              
        
        
            		if($conn = connect_db()) {
			$var=$conn->query($update3);
			}
			
			
			echo "Ditt kort har laddats med $credit3 SEK";
           
                
                
                }
    
                else {
        
                echo "Du har skrivt in fel kod";
                exit;
     }
}

			




	?>
		</form>
		<br />
		<br />
	</body>
</html>

