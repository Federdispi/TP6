# TP6 C++ : Sudoku

_Federico Di Spirito et Lucas Blanchard_

Nous avons choisi ce sujet puisque c'était celui de niveau le plus élevé et nous avons trouvé fascinant le fait de pouvoir résoudre à l'aide d'un ordinateur un casse tête qui peut prendre beaucoup de temps à un être humain.

Comme ce sujet est de niveau trop avancé pour Lucas, Federico s'est concentré sur ce TP sous l'oeil attentif de son binôme. Ça a donc été une opportunité pour Federico de s'entraîner et pour Lucas d'apprendre en observant. Pour que la lecture et la compréhension du code soit plus simple, Federico a essayé de coder de manière propre et en commentant tout ce qui est important.

Le programme implique une seule classe Sudoku, qui présente seulement deux attributs (niveau de difficulté et grille), des méthodes privés (tout ce qui permet de valider l'insertion d'une valeur) et des méthodes publiques (les constructeurs, les fonctions pour trouver des cases vides, insérer des valeurs ou résoudre le Sudoku et la surcharge de l'operateur <<). L'algorithme pour résoudre le Sudoku présente une fonction récursive. La taille du tableau peut varier et l'affichage de la grille change en conséquence (avec des lignes et des colonnes qui sont déssinées pour séparér les carrés élémentaires). Même si ce n'était pas demandé, le programme possède aussi un menu qui permet à l'utilisateur non seulement de résoudre le Sudoku mais aussi de jouer.

Je n'ai pas trouvé de difficultés même si le code pour afficher la grille en fonction de la taille du tableau m'a pris un peu de temps. Le programme fonctionne donc correctement.

## Introduction

Le but de ce TP est d'implémenter un générateur / solveur de grilles de sudoku.
La grille de Sudoku est composée de N × N cases et elle se décompose en N carrés élémentaires de dimension sqrt(N).
La grille doit être remplie selon les règles classiques du Sudoku, c'est à dire que chaque rangée, chaque colonne et chaque carré élémentaire doit être rempli avec les numéros de 1 à N, sans répéter aucun nombre dans la rangée, la colonne ou le carré.

## Fonctionnement du programme

À chaque lancement du programme, une nouvelle grille de Sudoku de taille N × N est générée, avec un nombre variable de cases pré-remplies en fonction du niveau de difficulté choisi.

Le programme affiche alors 2 tableaux :
* Le premier est le tableau initial qui ne sera pas modifié, ce qui permet de connaître les cases remplies par l'utilisateur.
* Le deuxième est le tableau que le joueur peut modifier en rajoutant des valeurs dans les cases qui au début étaient vides.

Le joueur peut choisir 3 modes :
* **Jouer :** l'utilisateur peut remplir une case du tableau tout en suivant les règles du Sudoku.
* **Completer :** l'ordinateur essaie de compléter le tableau en tenant compte des cases remplies par le joueur.
* **Solution :** l'ordinateur donne la solution du Sudoku, s'il y en a une;
