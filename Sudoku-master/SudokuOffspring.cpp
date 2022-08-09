/**
 * Offspring class
 * used to regenerate new Puzzle from existing one
 */
#include "Sudoku.h"
#include "SudokuOffspring.h"
#include <random>
#include <functional>
#include <memory>
using namespace std;

// _p: input puzzle
// main function for SudokuOffspring
shared_ptr<Puzzle> SudokuOffspring::makeOffspring(shared_ptr<Puzzle> &_p) {
    shared_ptr<Sudoku> p = dynamic_pointer_cast<Sudoku>(_p);
    const int prob = 5;

    // initial random generator
    random_device rd;
    mt19937 mt(rd());
    // [0, 99] generator
    auto rng_100 = bind(uniform_int_distribution<int>(0, 99), mt);
    // [1, 9] generator
    auto rng_9 = bind(uniform_int_distribution<int>(1, 9), mt);

    shared_ptr<Sudoku> s = make_shared<Sudoku>();
    for (int i=0; i<9; ++i) for (int j=0; j<9; ++j) {
        int v = p->value(i, j);
        bool d = p->determinent(i, j);

        // regenerate if
        // 1. not determine yet
        // 2. determined, 5% prob to regenerate
        if (v == 0 || (rng_100() < prob && !d)) {
            v = rng_9();
        }
        s->setValue(i, j, v, d);
    }

    return s;
}
