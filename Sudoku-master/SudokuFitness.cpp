#include "Sudoku.h"
#include "SudokuFitness.h"

// _p: input puzzle
// determine fitness of a puzzle
int SudokuFitness::howFit(shared_ptr<Puzzle> &_p) {
    // cast to Sudoku Puzzle
    shared_ptr<Sudoku> p = dynamic_pointer_cast<Sudoku>(_p);
    int tot = 0;

    // update tot helper
    // tot is the total conflict number
    auto update_tot = [&tot](int cnt[]) {
        for (int i=0; i<10; ++i) {
            if (cnt[i] > 1) tot += cnt[i];
        }
    };

    // check row
    for (int i=0; i<9; ++i) {
        int cnt[10] = {0};
        for (int j=0; j<9; ++j) {
            ++cnt[p->value(i, j)];
        }
        update_tot(cnt);
    }

    // check column
    for (int i=0; i<9; ++i) {
        int cnt[10] = {0};
        for (int j=0; j<9; ++j) {
            ++cnt[p->value(j, i)];
        }
        update_tot(cnt);
    }

    // check block
    for (int k=0; k<9; ++k) {
        int x = (k / 3) * 3;
        int y = (k % 3) * 3;
        int cnt[10] = {0};
        for (int i=x; i<x+3; ++i) {
            for (int j=y; j<y+3; ++j) {
                ++cnt[p->value(i, j)];
            }
        }
        update_tot(cnt);
    }

    return tot;
}
