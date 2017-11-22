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
        
        
	</head>		

	<body>
        <div id="mysql" class="mysql"> </div>
        
   
		<form action="index.php" method="post" class="stilmall">
		<h1>Registrera ditt kort här</h1>
		<label>
			<span>Ange KortID:</span>
			<input type="text" name="cardid" value="2e00e43947"/><br />	
		</label>
		<br>
		<input type="submit" name="knapp" class="button" value="Registrera kort" />
		

	<?php
	
	
	// Om användaren klickat på formulärets knapp "Översätt", så fortsätt 
	if(isset($_POST['knapp'])){
		// 1. Bearbeta formulärdata 
					
			// Lagra kortid  
			$card_id = $_POST['cardid'];
			$sql = "INSERT INTO rfid_rawdate(card_id,reader_id,reader_name) values ('".$card_id."',0010,'StoreCredit emulator')";
        
	
				// Kör fråga
			if($mysqli = connect_db()) {
			$var=$mysqli->query($sql);
			}
			
			
			echo "<br \><h2><span>Kortid: ".$card_id." har registrerats i databasen"; 
			
	
	} 
    

?>
            
     
            
            
	</body>
</html>