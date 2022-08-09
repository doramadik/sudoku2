/**
 * Puzzle Factory
 * used to create puzzle
 */

#include "PuzzleFactory.h"

// p: initial puzzle
// return value: new puzzle from old one
// create puzzle from an existing puzzle
shared_ptr<Puzzle> PuzzleFactory::createPuzzle(shared_ptr<Puzzle> &p) {
    return reproduction->makeOffspring(p);
}

// destructor
PuzzleFactory::~PuzzleFactory() {
}
