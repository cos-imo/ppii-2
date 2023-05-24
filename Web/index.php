<?php

$erreur = false;

function AdresseCoord($adresse) {
    // URL de l'API Gouv
    $url = "https://api-adresse.data.gouv.fr/search/?q=" . urlencode($adresse);

    // Appel à l'API gouv
    $response = file_get_contents($url);

    // Vérification de la réponse
    if ($response !== false) {
        // Décodage de la réponse JSON
        $data = json_decode($response, true);        
		// Récupération des coordonnées GPS
		$latitude = $data["features"][0]["geometry"]["coordinates"][1];
		$longitude = $data["features"][0]["geometry"]["coordinates"][0];

		// Retourne les coordonnées GPS
		return $latitude . ',' . $longitude;
    } else {
        // Bof
        return '0,0';
    }
}

?>


<!DOCTYPE html>
<html>
<head>
    <title>Itinéraire</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/leaflet@1.7.1/dist/leaflet.css" />
	<script>
        function showLoadingText() {
            var loadingText = document.getElementById("loadingText");
            loadingText.style.display = "inline-block";
			
			var loadingMap = document.getElementById("map");
            loadingMap.style.display = "none";
        }
    </script>
    <style>
        body {
			font-family: Arial, sans-serif;
			margin: 0;
			padding: 20px;
		}

		h1 {
			color: #333;
			text-align: center;
		}

		form {
			margin-bottom: 20px;
			text-align: center;
		}

		label {
			font-weight: bold;
		}

		input[type="text"] {
			padding: 5px;
			border: 1px solid #ccc;
			border-radius: 4px;
			width:300px;
			text-align:center;
		}
		
		input[type="number"] {
			padding: 5px;
			border: 1px solid #ccc;
			border-radius: 4px;
			width:300px;
			text-align:center;
		}

		input[type="submit"] {
			padding: 5px 10px;
			background-color: #4CAF50;
			color: white;
			border: none;
			border-radius: 4px;
			cursor: pointer;
		}

		button {
			padding: 5px 10px;
			background-color: #31aade;
			color: white;
			border: none;
			border-radius: 4px;
			cursor: pointer;
		}
		
		select {
			padding: 5px;
			border: 1px solid #ccc;
			border-radius: 4px;
			width:310px;
			text-align:center;
		}

		#map {
			height: calc(100vh - 100px);;
			width: 100%;
			margin-bottom: 20px;
		}

    </style>
</head>
<body>
    <h1>Recherche d'itinéraire avec bornes de recharge</h1>

    <form method="post" action="">
        <label for="depart">Départ :</label><br>
        <input type="text" id="depart" name="depart" value ="<?php if (isset($_POST["depart"])) { echo $_POST["depart"]; } ?>" <?php
			if ($_SERVER['REQUEST_METHOD'] === 'POST'){
				if (!isset($_POST["depart"]) or $_POST["depart"] == ""){
					$erreur = true;
					echo 'style="background-color:red;" ';
				}
			}
		?>required>
		<br><br>
		<label for="destination">Destination :</label><br>
		<input type="text" id="destination" name="destination" value ="<?php if (isset($_POST["destination"])) { echo $_POST["destination"]; } ?>" <?php
			if ($_SERVER['REQUEST_METHOD'] === 'POST'){
				if (!isset($_POST["destination"]) or $_POST["destination"] == ""){
					$erreur = true;
					echo 'style="background-color:red;" ';
				}
			}
		?>required><br><br>
		<?php
        
        $commande = './main_output';
        $resultat = shell_exec($commande);

        
        $resultats_separes = explode('+', $resultat);
        ?>

        <label for="voiture">Véhicule :</label><br>
        <select name="voiture" id="voiture">
            <?php
			if (intval($_POST["voiture"]) < 0 or intval($_POST["voiture"]) >= count($resultats_separes)){
				$erreur = true;
			}
            
            foreach ($resultats_separes as $index => $option) {
				if (isset($_POST["voiture"]) and $index == $_POST["voiture"]){
					echo "<option value='$index' selected>$option</option>";
				}
				else{
					echo "<option value='$index'>$option</option>";
				}
            }
            ?>
        </select>
		<br><br>
		
		
		
		<label for="minBatteryPercent">Pourcentage minimal de batterie :</label><br>
		<input type="number" name="minBatteryPercent" 
		<?php
			if ($_SERVER['REQUEST_METHOD'] === 'POST' and $_POST["minBatteryPercent"] < 0 or $_POST["minBatteryPercent"] > 100){
				$erreur = true;
				echo 'style="background-color:red" ';
			}
		?>
		value="<?php if (isset($_POST["minBatteryPercent"])) { echo $_POST["minBatteryPercent"]; } else { echo "0"; } ?>"><br><br>
		<label for="maxTimeAtStation">Temps maximal à passer à une station :</label><br>
		<input type="number" name="maxTimeAtStation" value="<?php if (isset($_POST["maxTimeAtStation"])) { echo $_POST["maxTimeAtStation"]; } else { echo "60"; } ?>" 
		<?php
			if ($_SERVER['REQUEST_METHOD'] === 'POST' and $_POST["maxTimeAtStation"] < 0 or $_POST["maxTimeAtStation"] > 120){
				$erreur = true;
				echo 'style="background-color:red" ';
			}
		?>
		max="120"><br><br>
        <input type="submit" value="Rechercher" onclick="showLoadingText()">

    <?php
    if ($_SERVER['REQUEST_METHOD'] === 'POST' and !$erreur) {
        $destination = $_POST['location'];

        $command = 'sleep 3;echo '.AdresseCoord($_POST["depart"]).'+49.18659,-0.36325+48.85814,2.29442+49.24736,4.03278+'.AdresseCoord($_POST["destination"]);
		$output = array();
		$returnValue = null;

		exec($command, $output, $returnValue);


		$destinations = [];

		$split1 = explode("+", $output[0]);
		$totalDestinations = count($split1);
		
		$strurl = "https://www.google.fr/maps/dir";

		foreach ($split1 as $index => $subString) {
			$split2 = explode(",", $subString);
			$lat = $split2[0];
			$lng = $split2[1];
			
			$strurl = $strurl . "/".$lat.",".$lng;
			
			if ($index === 0) {
				$destinations[] = ['name' => 'Départ', 'lat' => $lat, 'lng' => $lng];
			} elseif ($index === ($totalDestinations - 1)) {
				$destinations[] = ['name' => 'Arrivée', 'lat' => $lat, 'lng' => $lng];
			} else {
				$destinations[] = ['name' => 'Borne n°' . $index, 'lat' => $lat, 'lng' => $lng];
			}
		}

		echo "<br><br><button onclick=\"window.open('".$strurl."', '_blank')\">Voir l'itinéraire dans Google Maps</button>";

        ?>
		</form>
	<?php } ?>
	<center><div id="loadingText" style="display:none;"><h1><font color="green">Chargement en cours...</font></h1><br></div></center>
	<?php if ($_SERVER['REQUEST_METHOD'] === 'POST' and !$erreur) { ?>
		<div id="map"></div>
        <script src="https://cdn.jsdelivr.net/npm/leaflet@1.7.1/dist/leaflet.js"></script>
        <script>
            var map = L.map('map').setView([<?php echo $destinations[0]['lat']; ?>, <?php echo $destinations[0]['lng']; ?>], 6);

            L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
                attribution: '&copy; <a href="https://www.openstreetmap.org/">OpenStreetMap</a> contributors'
            }).addTo(map);

            <?php foreach ($destinations as $destination) { ?>
                var marker = L.marker([<?php echo $destination['lat']; ?>, <?php echo $destination['lng']; ?>]).addTo(map);
                marker.bindPopup('<h1><?php echo $destination['name']; ?></h1><center><?php echo "(".$destination['lat'].", ".$destination['lng'].")"; ?></center>');
            <?php } ?>
        </script>
        <?php
    }
    ?>

</body>
</html>
