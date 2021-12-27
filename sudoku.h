#ifndef SUDOKU_H
#define SUDOKU_H
#define N 9
#include <iostream>
#include <array>

class Sudoku {
public:
    Sudoku(int complexite);
    friend std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku);
    bool remplir(int ligne, int colonne, int n);
private:
    std::array<std::array<int,N>,N> _tableau;
    int _complexite;
    bool ligneValide(int ligne, int n);
    bool colonneValide(int colonne, int n);
    bool carreValide(int ligne, int colonne, int n);
    bool check(int ligne, int colonne, int n);
};
#endif