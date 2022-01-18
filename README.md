# TP6 C++ : Sudoku

_Federico Di Spirito et Lucas Blanchard_

## Introduction

Le but de ce TP est d'implémenter un générateur / solveur de grilles de sudoku.
La grille de Sudoku est composée de N × N cases et elle se décompose en N carrés élémentaires de dimension sqrt(N).
La grille doit être remplie selon les règles classiques du Sudoku, c'est à dire que chaque rangée, chaque colonne et chaque carré élémentaire doit être rempli avec les numéros de 1 à N, sans répéter aucun nombre dans la rangée, la colonne ou le carré.

## Fonctionnement du programme

À chaque lancement du programme, une nouvelle grille de Sudoku de taille N×N est générée, avec un nombre variable de cases pré-remplies en fonction du niveau de difficulté choisi.

Le programme affiche alors 2 tableaux :
* Le premier est le tableau initial qui ne sera pas modifié, ce qui permet de connaître les cases remplies par l'utilisateur.
* Le deuxième est le tableau que le joueur peut modifier en rajoutant des valeurs dans les cases qu'au début étaient vides.

Le joueur peut choisir 3 modes :
* **Jouer :** l'utilisateur peut remplir une case du tableau tout en suivant les règles du Sudoku.
* **Completer :** l'ordinateur essaie de compléter le tableau en tenant compte des cases remplies par le joueur.
* **Solution :** l'ordinateur donne la solution du Sudoku, s'il y en a une;