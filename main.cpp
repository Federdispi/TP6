#include <iostream>
#include "sudoku.h"
int main()
{
    Sudoku sudoku;
    std::cout<<sudoku;
    if(sudoku.check(1,1,1))
        std::cout<<"OK"<<std::endl;
    else
        std::cout<<"NOPE"<<std::endl;
}