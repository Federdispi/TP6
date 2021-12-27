#include "sudoku.h"
#include <cmath>
Sudoku::Sudoku(int complexite)
    :_complexite(complexite)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            _tableau[i][j] = 0;
    }
    int a = 20 + (5 - _complexite) * 5;
    int l,c,n;
    while(a > 0)
    {
        l = rand() % N + 1;
        c = rand() % N + 1;
        n = rand() % N + 1;
        if(_tableau[c][l] == 0)
        {
            if(remplir(l,c,n))
                a--;
        }
    }
}

bool Sudoku::ligneValide(int ligne, int n)
{
    for(int i = 0; i < N; i++)
    {
        if(_tableau[i][ligne] == n)
            return false;
    }
    return true;
}

bool Sudoku::colonneValide(int colonne, int n)
{
    for(int i = 0; i < N; i++)
    {
        if(_tableau[colonne][i] == n)
            return false;
    }
    return true;
}

bool Sudoku::carreValide(int ligne, int colonne, int n)
{
    int l, c;
    l = ligne - ligne % int(sqrt(N));
    c = colonne - colonne % int(sqrt(N));
    for(int i = 0; i < sqrt(N); i++)
    {
        for(int j = 0; j < sqrt(N); j++)
        {
            if(_tableau[c + i][l + j] == n)
                return false;
        }
    }
    return true;
}

bool Sudoku::check(int ligne, int colonne, int n)
{
    if(ligneValide(ligne, n) && colonneValide(colonne, n) && carreValide(ligne, colonne, n))
        return true;
    else
        return false;
}

bool Sudoku::remplir(int ligne, int colonne, int n)
{
    if(check(ligne, colonne, n) && n > 0 && n <= N && ligne > 0 && ligne <= N && colonne > 0 && colonne <= N){
        _tableau[colonne][ligne] = n;
        return true;
    }else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku)
{
    os << std::endl << "COMPLEXITE : " << sudoku._complexite << std::endl;
    os << "-------------------" << std::endl;
    for(int i = 0; i < N; i++){
        os << "|";
        for(int j = 0; j < N; j++){
            if(sudoku._tableau[i][j] == 0)
                os << " ";
            else
                os << sudoku._tableau[i][j];
            if((j + 1) % int(sqrt(N)) == 0)
                os<<"|";
            else
                os<<" ";
        }
        os << std::endl;
        if((i + 1) % int(sqrt(N)) == 0)
            os << "-------------------" << std::endl;
    }
}