#include "sudoku.h"
#include <cmath>

//Constructeur
Sudoku::Sudoku(int complexite)
    :_complexite(complexite)
{
    //Remplie le tableau de cases vides
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            _tableau[i][j] = 0;
    }
    int a = 20 + (5 - _complexite) * 5; //Definie le nombre de valeur a placer par defaut dans le tableau
    int l,c,n;
    //Remplie le tableau avec des valeurs aleatoires
    while(a > 0)
    {
        l = rand() % N;
        c = rand() % N;
        n = rand() % N + 1;
        if(_tableau[l][c] == 0)
        {
            if(remplir(l,c,n))
                a--;
        }
    }
}

//Constructeur par copie
Sudoku::Sudoku(const Sudoku& sudoku)
{
    _tableau = sudoku._tableau;
    _complexite = sudoku._complexite;
}

//Verifie si la ligne du tableau est valide
bool Sudoku::ligneValide(int ligne, int n)
{
    for(int i = 0; i < N; i++)
    {
        if(_tableau[ligne][i] == n)
            return false;
    }
    return true;
}

//Verifie si la colonne du tableau est valide
bool Sudoku::colonneValide(int colonne, int n)
{
    for(int i = 0; i < N; i++)
    {
        if(_tableau[i][colonne] == n)
            return false;
    }
    return true;
}

//Verifie si le carre du tableau est valide
bool Sudoku::carreValide(int ligne, int colonne, int n)
{
    int l, c;
    //On se place au debut du carre
    l = ligne - ligne % int(sqrt(N));
    c = colonne - colonne % int(sqrt(N));
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

//Verifie si on peut inserer la valeur dans la case
bool Sudoku::check(int ligne, int colonne, int n)
{
    if(ligneValide(ligne, n) && colonneValide(colonne, n) && carreValide(ligne, colonne, n))
        return true;
    else
        return false;
}

//Verifie si la case est vide
bool Sudoku::caseVide(int ligne, int colonne)
{
    if(_tableau[ligne][colonne] == 0)
        return true;
    return false;
}

//Insere la valeur dans la case
bool Sudoku::remplir(int ligne, int colonne, int n)
{
    if(check(ligne, colonne, n) && n > 0 && n <= N && ligne >= 0 && ligne < N && colonne >= 0 && colonne < N){
        _tableau[ligne][colonne] = n;
        return true;
    }else{
        return false;
    }
}

//Cherche une case vide
bool Sudoku::findVide(int& ligne, int& colonne)
{
    for(ligne = 0; ligne < N; ligne++)
        for(colonne = 0; colonne < N; colonne++)
            if(_tableau[ligne][colonne] == 0)
                return true;
    return false;
}

//Resout le sudoku
bool Sudoku::solve()
{
    int ligne, colonne;
    if(!findVide(ligne, colonne))//On se place dans une case vide s'il y en a une, sinon on retourne true
        return true;
    for(int n = 1; n <= N; n++)
    {
        if(remplir(ligne, colonne, n))
        {
            if(solve()) //récursivité
                return true;
            _tableau[ligne][colonne] = 0; //On enleve la valeur qui n'etait pas bonne
        }
    }
    return false;
    /**
     * Quantite de traitements : pour chaque case vide il y a 9 options possibles, donc 9^(n*n)
     * Temps d'execution : ça depend de la taille du tableau et de la puissance de l'ordinateur. Pour une grille 9*9, le temps d'execution est presque instantane
     */
}

//Fonction pour compter le nombre de chiffres dans un nombre
int numDigits(int n)
{
    int digits = 0;
    while(n > 0)
    {
        n/=10;
        digits++;
    }
    return digits;
}

//Surcharge de l'operateur <<
std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku)
{
    os << std::endl << "COMPLEXITE : " << sudoku._complexite << std::endl;
    for(int i = 0; i < (numDigits(N) + 1) * N + 1; i++) //La taille des lignes horizontales s'adapte a la taille du tableau
        os<<"-";
    os<<std::endl;
    for(int i = 0; i < N; i++){
        os << "|";
        for(int j = 0; j < N; j++){
            if(sudoku._tableau[i][j] == 0)
            {
                for(int k = 0; k < numDigits(N); k++) //Les cases sont espaces en fonction de la taille du tableau
                    os << " ";
            }
            else
            {
                for(int k = 0; k < numDigits(N) - numDigits(sudoku._tableau[i][j]); k++)
                    os << " ";
                os << sudoku._tableau[i][j];
            }
            if((j + 1) % int(sqrt(N)) == 0) //Le placement des lignes verticales est en fonction de la taille du tableau
                os<<"|"; 
            else
                os<<" ";
        }
        os << std::endl;
        if((i + 1) % int(sqrt(N)) == 0)
        {
            for(int i = 0; i < numDigits(N) * N + N + 1; i++)
                os<<"-";
            os << std::endl;
        }
    }
}