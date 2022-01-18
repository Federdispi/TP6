#include <iostream>
#include "sudoku.h"
int main()
{
    srand(time(NULL));
    int a, alert, ligne, colonne;
    system("clear");
    std::cout << "QuickFind The Number" << std::endl << std::endl;
    std::cout << "Selectionner un niveau de difficulte (1 a 5) : ";
    do{
        std::cin >> a;
    }while(a < 1 || a > 5);
    Sudoku sudoku(a); //Tableau qu'on modifie
    Sudoku sudokubase(sudoku); //Tableau de depart
    while(sudoku.findVide(ligne, colonne)) //Le programme se termine une fois que le tableau est completement rempli
    {
        system("clear");
        if(alert == 1)
            std::cout << "La valeur n'est pas valide" << std::endl << std::endl;
        else if(alert == 2)
            std::cout << "Tu ne peux pas placer de valeurs dans cette case" << std::endl << std::endl;
        else if(alert == 3)
            std::cout << "Pas de solutions" << std::endl << std::endl;
        std::cout << "Sudoku de depart" << sudokubase;
        std::cout << sudoku;
        std::cout << "1. Jouer     2. Completer     3. Solution     "; //Menu
        do{
            std::cin >> a;
        }while(a < 1 || a > 3);
        switch (a)
        {
        case 1: //Le joueur peut remplir le tableau en specifiant la case et la valeur
            int l,c,v;
            std::cout << "Selectionner la ligne (1 a " << N << "): ";
            do{
                std::cin >> l;
            }while(l < 1 || l > N);
            std::cout << "Selectionner la colonne (1 a " << N << ") ";
            do{
                std::cin >> c;
            }while(c < 1 || c > N);
            std::cout << "Selectionner la valeur (1 a " << N << "): ";
            std::cin >> v;
            if(sudokubase.caseVide(l - 1, c - 1))
            {
                if(sudoku.remplir(l - 1, c - 1, v))
                    alert = 0;
                else
                    alert = 1;
            }else
                alert = 2;
            break;
        case 2: //
            if(sudoku.solve()) //Remplie le tableau en tenant compte des cases remplies par le joueur
            {
                std::cout << "Je place le reste des chiffres" << std::endl << sudoku;
                return 0;
            }
            else
                alert = 3;
            break;
        case 3: //Solution du tableau initial
            if(sudokubase.solve())
                std::cout << "SOLUTION" << std::endl << sudokubase;
            else
                std::cout << "Pas de solutions" << std::endl;
            return 0;
            break;
        }
        std::cout << sudoku << "T'AS GAGNE" << std::endl;
    }
}