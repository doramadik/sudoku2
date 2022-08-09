/**
 * Sudoku class impl
 */

#include "Sudoku.h"

// constructor
Sudoku::Sudoku() {
    grid.resize(81);
}

// destructor
Sudoku::~Sudoku() {
}

// r: row
// c: column
// return value: value on position (r, c)
// get value from sudoku
int Sudoku::value(int r, int c) {
    return grid[r*9+c].first;
}

// r: row
// c: column
// return value: is (r, c) determined
// is the cell determine already?
bool Sudoku::determinent(int r, int c) {
    return grid[r*9+c].second;
}

// r: row
// c: column
// val: value
// deter: is determined
// set value of a cell
void Sudoku::setValue(int r, int c, int val, bool deter) {
    grid[r*9+c] = {val, deter};
}

// in: input stream
// read in Sudoku from stream
istream &Sudoku::readin(istream &in) {
    // first clear grid
    grid.clear();
    char c;
    while (in >> c) {
        // read finished, break
        if (grid.size() == 81) break;
        // only use in digit
        if (isdigit(c)) {
            grid.push_back({c-'0', c!='0'});
        }
    }
    return in;
}

// out: output stream
// print out Sudoku to stream
ostream &Sudoku::printout(ostream &out) const {
    // header and footer string
    const string hdr_ftr = "+-------+-------+-------+\n";
    out << hdr_ftr;
    for (int i=0; i<9; ++i) {
        // border
        out << "|";
        for (int j=0; j<9; ++j) {
            out << " " << grid[i*9+j].first;
            // inner border
            if (j % 3 == 2) out << " |";
        }
        out << endl;
        if (i % 3 == 2) out << hdr_ftr;
    }
    return out;
}
