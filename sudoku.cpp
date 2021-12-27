#include "sudoku.h"
#include <cmath>
Sudoku::Sudoku()
{
    for(int i = 0; i < N; i++){
        for(int j = 0;j < N;j++)
            _tableau[i][j] = 0;
    }
}

bool Sudoku::ligneValide(int ligne, int n)
{
    for(int i = 0; i < N; i++)
    {
        if(_tableau[ligne][i] == n)
            return false;
    }
    return true;
}

bool Sudoku::colonneValide(int colonne, int n)
{
    for(int i = 0; i < N; i++)
    {
        if(_tableau[i][colonne] == n)
            return false;
    }
    return true;
}

bool Sudoku::carreValide(int ligne, int colonne, int n)
{
    int l, c;
    l = ligne - ligne % 3;
    c = colonne - colonne % 3;
    for(int i = 0; i < sqrt(N); i++)
    {
        for(int j = 0; j < sqrt(N); j++)
        {
            if(_tableau[l + i][c + j] == n)
                return false;
        }
    }
    return true;
}

bool Sudoku::check(int ligne, int colonne, int n)
{
    if(n > 0 && n <= N)
    {
        if(ligneValide(ligne, n) && colonneValide(colonne, n) && carreValide(ligne, colonne, n))
            return true;
        else
            return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku)
{
    for(int i = 0; i < N; i++){
        os << "-------------------" << std::endl << "|";
        for(int j = 0; j < N; j++){
            if(sudoku._tableau[i][j] == 0)
                os << " |";
            else
                os << sudoku._tableau[i][j] << "|";
        }
        os << std::endl;
    }
    os << "-------------------" << std::endl;
}