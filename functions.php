<?php
// Hämtar senast registrerat kort
if($result = $mysqli->query("SELECT card_id FROM rfid_rawdate ORDER BY id DESC LIMIT 1"))  {
        
 
          
        //Hämtar rows som en assosiativ array
            $rows = $result->fetch_assoc();
           
        }

//Bryter ut arrayen till en string
$current_card = implode($rows);






//Hämtar värde från det senaste lästa kortet

if($result2 = $mysqli->query("SELECT value FROM card_credit WHERE card_id='$current_card'"))  {
        
  
          
        //Hämtar rows som en assosiativ array
            $rows2 = $result2->fetch_assoc();
           
    }
//Bryter ut arrayen till en string
$visa_saldo = implode($rows2);



//Hämtar refillkod1
if($result3 = $mysqli->query("SELECT refill FROM card_refill WHERE id='1' "))  {
        
 
          
        //Hämtar rows som en assosiativ array
            $rows3 = $result3->fetch_assoc();
           
        }

//Bryter ut arrayen till en string
$refill = implode($rows3);




//Hämtar refillkod2
if($result4 = $mysqli->query("SELECT refill FROM card_refill WHERE id='2' "))  {
        
 
          
        //Hämtar rows som en assosiativ array
            $rows4 = $result4->fetch_assoc();
           
        }

//Bryter ut arrayen till en string
$refill2 = implode($rows4);




//Hämtar refillkod3
if($result5 = $mysqli->query("SELECT refill FROM card_refill WHERE id='3' "))  {
        
 
          
        //Hämtar rows som en assosiativ array
            $rows5 = $result5->fetch_assoc();
           
        }

//Bryter ut arrayen till en string
$refill3 = implode($rows5);




//Hämtar värdet i credit från specifikt id
if($result6 = $mysqli->query("SELECT credit FROM card_refill WHERE id='1' "))  {
        
 
          
        //Hämtar rows som en assosiativ array
            $rows6 = $result6->fetch_assoc();
           
        }

//Bryter ut arrayen till en string
$credit = implode($rows6);




//Hämtar värdet i credit från specifikt id
if($result7 = $mysqli->query("SELECT credit FROM card_refill WHERE id='2' "))  {
        
 
          
        //Hämtar rows som en assosiativ array
            $rows7 = $result7->fetch_assoc();
           
        }

//Bryter ut arrayen till en string
$credit2 = implode($rows7);




//Hämtar värdet i credit från specifikt id
if($result8 = $mysqli->query("SELECT credit FROM card_refill WHERE id='3' "))  {
        
 
          
        //Hämtar rows som en assosiativ array
            $rows8 = $result8->fetch_assoc();
           
        }

//Bryter ut arrayen till en string
$credit3 = implode($rows8);









	function connect_db() { 
	
	date_default_timezone_set('Europe/Stockholm');
	
	// Här ska du lägga in anslutningsinformation för att kunna ansluta dig mot din databas:
	// DittAnvändarID, DittLösen och den databas du har skapat tabellerna i.
	
	$conn = new mysqli("localhost", "root", "", "phidget_rfid");

	if (!$conn->set_charset("utf8")) {
    	echo "Fel vid inställning av teckentabell utf8: %s\n". $conn->error;
	} else {
 		//echo "Nuvarande teckenkodningstabell: %s\n". $mysqli->character_set_name();
	}

	if ($conn->connect_errno) {
	    echo "Misslyckades att ansluta till MySQL: (" . $conn->connect_errno . ") " . $conn->connect_error;
	}

	return $conn;
	}
	

?>