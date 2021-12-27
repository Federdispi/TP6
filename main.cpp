#include <iostream>
#include "sudoku.h"
int main()
{
    srand(time(NULL));
    Sudoku sudoku1(1);
    Sudoku sudoku2(2);
    Sudoku sudoku3(3);
    Sudoku sudoku4(4);
    Sudoku sudoku5(5);
    std::cout << sudoku1;
    std::cout << sudoku2;
    std::cout << sudoku3;
    std::cout << sudoku4;
    std::cout << sudoku5;
}