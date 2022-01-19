#ifndef SUDOKU_H
#define SUDOKU_H
#define N 9 //Dimension du tableau
#include <iostream>
#include <array>

class Sudoku {
public:
    Sudoku(int complexite); //Constructeur
    Sudoku(const Sudoku& sudoku); //Constructeur par copie
    friend std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku); //Surcharge de l'operateur <<
    bool caseVide(int ligne, int colonne); //Verifie si la case est vide
    bool remplir(int ligne, int colonne, int n); //Insere la valeur dans la case
    bool solve(); //Resout le sudoku
    bool findVide(int& ligne, int& colonne); //Cherche une case vide
private:
    std::array<std::array<int,N>,N> _tableau;
    int _complexite;
    bool ligneValide(int ligne, int n); //Verifie si la ligne du tableau est valide
    bool colonneValide(int colonne, int n); //Verifie si la colonne du tableau est valide
    bool carreValide(int ligne, int colonne, int n); //Verifie si le carre du tableau est valide
    bool check(int ligne, int colonne, int n); //Verifie si on peut inserer la valeur dans la case
};
#endif