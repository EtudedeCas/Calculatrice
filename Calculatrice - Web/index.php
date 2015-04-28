<html>
	<head>
	  <title>Calculatrice</title>
	  <meta charset="utf-8">
	  <link href="style.css" rel="stylesheet">
	</head>
	<body>
		<div class="resultat"><span id="oper"></span><span id="actuel"></span></div>
		<div class="ligne4" id="7"><p>7</p></div><div class="ligne4" id="8"><p>8</p></div><div class="ligne4" id="9"><p>9</p></div></br>
		<div class="ligne3" id="4"><p>4</p></div><div class="ligne3" id="5"><p>5</p></div><div class="ligne3" id="6"><p>6</p></div></br>
		<div class="ligne2" id="1"><p>1</p></div><div class="ligne2" id="2"><p>2</p></div><div class="ligne2" id="3"><p>3</p></div></br>
		<div class="ligne1" id="0"><p>0</p></div><div class="ligne1" id="plus"><p>+</p></div><div class="ligne1" id="moins"><p>-</p></div></br>
		<div class="ligne0" id="mult"><p>x</p></div><div class="ligne0" id="divi"><p>/</p></div><div class="ligne0" id="del"><p>DEL</p></div></br>
		<div class="ligne" id="reset"><p>C</p></div><div class="ligne" id="egal"><p>=</p></div></br>
		
	</body>
</html>

<script src="jquery.js"></script>
<script>
	  $(function() {
		//une variable pour récupérer les chiffres et une variable pour sauvegarder le symbole (et éviter les opérations bizarres)
	   var a = 0;
	   
	   //une liste qui stocke tout les chiffres/symboles sur lesquels on a cliqué (plus facile pour faire les opérations ensuite)
	   var liste = [];
	   
	   //ensuite on gère le click sur les div de chaque chiffre
		$('#0').on('click', function(){
			$('#actuel').append('0');
		});
		$('#1').on('click', function(){
			$('#actuel').append('1');
		});
		$('#2').on('click', function(){
			$('#actuel').append('2');
		});
		$('#3').on('click', function(){
			$('#actuel').append('3');
		});
		$('#4').on('click', function(){
			$('#actuel').append('4');
		});
		$('#5').on('click', function(){
			$('#actuel').append('5');
		});
		$('#6').on('click', function(){
			$('#actuel').append('6');
		});
		$('#7').on('click', function(){
			$('#actuel').append('7');
		});
		$('#8').on('click', function(){
			$('#actuel').append('8');
		});
		$('#9').on('click', function(){
			$('#actuel').append('9');
		});
		//---------------------------------------
		
		$('#del').on('click', function(){
			var temp = $('#actuel').text();
			temp = temp.slice(0,-1);
			$('#actuel').text(temp);
		});
		
		//on arrive aux opérations
		//on met a à 0 si aucune valeur n'est saisie
		$('#plus').on('click', function(){
			a = $('#actuel').text();
			if ($('#actuel').text() == "")
				a = 0;
			$('#actuel').text("");
			
			liste[liste.length] = a;
			liste[liste.length] = "+";
			
			$('#oper').append(a + "+");
		});
		
		$('#moins').on('click', function(){
			a = $('#actuel').text();
			if ($('#actuel').text() == "")
				a = 0;
			$('#actuel').text("");
			
			liste[liste.length] = a;
			liste[liste.length] = "-";
			
			$('#oper').append(a + "-");
		});
		
		$('#mult').on('click', function(){
			a = $('#actuel').text();
			if ($('#actuel').text() == "")
				a = 0;
			$('#actuel').text("");
			
			liste[liste.length] = a;
			liste[liste.length] = "*";

			$('#oper').append(a + "*");
		});
		
		$('#divi').on('click', function(){
			a = $('#actuel').text();
			if ($('#actuel').text() == "")
				a = 0;
			$('#actuel').text("");
			
			liste[liste.length] = a;
			liste[liste.length] = "/";
			
			$('#oper').append(a + "/");
		});		
		//------------------------------------------------------------------
		
		
		//et enfin le calcul
		$('#egal').on('click', function(){
			a = $('#actuel').text();
			if ($('#actuel').text() == " ")
				a = 0;
				
			liste[liste.length] = a;
			
			$('#oper').append(a + "=");
			
			var resultat = Number(liste[0]);
			var i;
			for (i = 0; i < liste.length; i++)
			{
				switch(liste[i])
				{					
					//un cas par opération
					case "+": 
						resultat += Number(liste[i + 1]);
						break;
					case "-": 
						resultat -= Number(liste[i + 1]);
						break;
					case "*": 
						resultat *= Number(liste[i + 1]);
						break;
					case "/": 
						resultat /= Number(liste[i + 1]);
						break;
					//------------------------------------------
					
				}
			}
			
			//on réinitialise la liste, le calcul est fini, et on affiche le résultat
			liste = [];
			
			$('#actuel').text(resultat);
		});
		//------------------------------------------
		
		//implémentation du bouton "reset" qui réinitialise la liste, les variables et l'affichage
		$('#reset').on('click', function(){
			$('#actuel').text("");
			$('#oper').text("");
			liste = [];
			a = 0;
		});
	  });
	  
	</script>