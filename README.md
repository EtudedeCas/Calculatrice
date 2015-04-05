# Calculatrice

Tizen IDE c'est bien pourri. J'imagine que vous aussi vous arrivez à Debugger que 1 fois sur 10 ? 
C'est un peu chaud de savoir exactement d'où viennent les erreurs sans pouvoir debugger correctement^^

Sinon j'ai copié-collé mon code (la structure de liste chainée) dans Visual Studio (donc les fonctions initialisation() et ajouterEnFin()) et j'ai essayé de faire des calculs
donc en gros j'ai ajouté des char* (genre 10,+ et 58 à ma liste) et ça marchait parfaitement, le bon résultat s'affichait.

Je comprends pas trop et puisqu'il est impossible de debugger correctement, j'avoue que j'ai pas mal ragé (genre vraiment beaucoup^^).
Au stade actuel: 10 + 20 = 40 sur Tizen et 10 + 20 = 30 sur la version Visual Studio....avec rigoureusement le même code que ce soit pour effectuer le calcul ou pour ajouter les valeurs dans la liste  o_O

Je pense sans en être sûr que dans Tizen le programme doit peut-être réinitialiser la liste à un moment donné et du coup le programme initialise deux fois le premier élément 
de la liste (donc l'ancienne valeur est remplacée par 20).

Parce que oui, une fois le Debug a marché et j'ai pu voir que le contenu de la liste lorsqu'on clique sur "=" (en effectuant le calcul: 10+20) c'est: "20,+,20" et non pas "10,+,20" comme on pourrait s'y attendre.
D'où mes reflexions de plus haut (initialiser deux fois "premier" ---> super bizarre btw, la seule explication c'est que la liste est réinitalisée quelque part (super biarre aussi sachant que la fonction dans laquelle elle est initialisée est appelée qu'une seule fois.....)).

Enfin ça explique pas pourquoi y a deux fois "20", ça j'avoue que ça me dépasse un peu^^ Je comprends pas pourquoi il est ajouté 2 fois...1 fois je comprendrait mais alors 2.......

