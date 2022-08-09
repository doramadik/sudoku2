/**
 * Puzzle class
 * read in puzzle, print out puzzle
 */

#include "Puzzle.h"

// out: output stream
// puzzle: puzzle to read in
// return value: output stream
// read in puzzle from stream
ostream &operator<<(ostream &out, const Puzzle &puzzle) {
    return puzzle.printout(out);
}

// in: in stream
// puzzle: puzzle to print out
// return value: input stream
// print out puzzle
istream &operator>>(istream &in, Puzzle &puzzle) {
    return puzzle.readin(in);
}

// destructor
Puzzle::~Puzzle() {
}
