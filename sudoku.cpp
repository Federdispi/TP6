#include "sudoku.h"
Sudoku::Sudoku()
{
    _tableau = {{
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
        }};
}

std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku)
{
    for(int i=0;i<9;i++){
        os<<"-------------------"<<std::endl<<"|";
        for(int j=0;j<9;j++){
            if(sudoku._tableau[i][j]==0)
                os<<" |";
            else
                os<<sudoku._tableau[i][j]<<"|";
        }
        os<<std::endl;
    }
    os<<"-------------------"<<std::endl;
}