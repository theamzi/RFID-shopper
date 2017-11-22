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
        	<form action="handla.php" method="post" class="stilmall">
		<h1>Handla</h1>
		<label>
			
			<input type="hidden" name="cardid" value="100"/><br />	
		</label>
		<img src=img/skor.jpg alt=Skor width="250px height=200px">
                <br>
                <br>
                <span>Köp ett par skor för 100 SEK</span>
		<input type="submit" name="knapp" class="button" value="Köp" />
		
        </form>
        
        <?php


	// Om användaren klickat på formulärets knapp "Översätt", så fortsätt 
	if(isset($_POST['knapp'])){
		// 1. Bearbeta formulärdata 
					
			// Räknar ut mha aktuellt köp vad nytt upppdaterat värde till det lästa kortet ska vara 
			$card_id = $_POST['cardid'];
            $kop = ($visa_saldo-$card_id);
            $update = "UPDATE card_credit SET value = '$kop' WHERE card_id='$current_card'";
			
	
				// Kör fråga och uppdaterar db
			if($conn = connect_db()) {
			$var=$conn->query($update);
			}
			
			
			echo "<br \><br \><h2><span>Ditt köp för 100 SEK har registrerats ";
           
        
			
	
	} 



            ?>
                
                  	<form action="handla.php" method="post" class="stilmall">
	
		<label>
			
            <br>
			<input type="hidden" name="mossa" value="150"/><br />	
		</label>
		<img src=img/mossa.jpg.jpg alt=Skor width="250px height=200px">
                <br>
                <br>
                        <span>Köp en mössa för 150 SEK</span>
		<input type="submit" name="knapp2" class="button" value="Köp" />
		
		   </form>
        
        <?php


	// Om användaren klickat på formulärets knapp "Översätt", så fortsätt 
	if(isset($_POST['knapp2'])){
		// 1. Bearbeta formulärdata 
					
        // Räknar ut mha aktuellt köp vad nytt upppdaterat värde till det lästa kortet ska vara 
			$mossa = $_POST['mossa'];
            $kop2 = ($visa_saldo-$mossa);
            $update2 = "UPDATE card_credit SET value = '$kop2' WHERE card_id='$current_card'";
			
	
				// Kör fråga och uppdaterar db
			if($conn = connect_db()) {
			$var2=$conn->query($update2);
			}
			
			
			echo "<br \><br \><h2><span>Ditt köp för 150 SEK har registrerats ";
           
        
			
	
	} 



            ?>
                        
                          	<form action="handla.php" method="post" class="stilmall">
		
		<label>
			
			<input type="hidden" name="halsduk" value="200"/><br />	
		</label>
		<img src=img/halsduk.jpg alt=halsduk width="250px height=200px">
                <br>
                <br>
                                <span>Köp en halsduk för 200 SEK</span>
		<input type="submit" name="knapp3" class="button" value="Köp" />
		
		   </form>
        
        <?php

   
	// Om användaren klickat på formulärets knapp "Översätt", så fortsätt 
	if(isset($_POST['knapp3'])){
		// 1. Bearbeta formulärdata 
					
			// Räknar ut mha aktuellt köp vad nytt upppdaterat värde till det lästa kortet ska vara  
			$halsduk = $_POST['halsduk'];
            $kop3 = ($visa_saldo-$halsduk);
            $update3 = "UPDATE card_credit SET value = '$kop3' WHERE card_id='$current_card'";
			
	
				// Kör fråga och uppdaterar db
			if($conn = connect_db()) {
			$var3=$conn->query($update3);
			}
			
			
			echo "<br \><br \><h2><span>Ditt köp för 200 SEK har registrerats ";
           
        
			
	
	} 



            ?>
	</body>
</html>


