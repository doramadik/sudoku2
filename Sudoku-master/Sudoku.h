/**
 * Sudoku class
 * 9x9 grid
 * pair<int, bool>, first is number, second is it is determinent
 */

#pragma once

#include "Puzzle.h"
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Sudoku : public Puzzle {
public:
    Sudoku();
    ~Sudoku();
    istream &readin(istream &in) override;
    ostream &printout(ostream &out) const override;
    int value(int r, int c);
    bool determinent(int r, int c);
    void setValue(int r, int c, int val, bool deter);

private:
    // vector to represent Sudoku layout
    // (x, y) is grid[x*9+y]
    vector<pair<int, bool>> grid;
};
