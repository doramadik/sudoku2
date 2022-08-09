/**
 * create new Sudoku from existing one
 */

#pragma once

#include "Reproduction.h"
#include <memory>
using namespace std;

class SudokuOffspring : public Reproduction {
public:
    shared_ptr<Puzzle> makeOffspring(shared_ptr<Puzzle> &p) override;
};
