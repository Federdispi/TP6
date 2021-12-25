#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <array>

class Sudoku {
public:
    Sudoku();
    friend std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku);
private:
    std::array<std::array<int,9>,9> _tableau;
    int _complexite;
};
#endif