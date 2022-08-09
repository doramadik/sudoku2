/**
 * Abstract Puzzle Factory
 */

#pragma once

#include "Puzzle.h"
#include "Reproduction.h"
#include <memory>
using namespace std;

class PuzzleFactory {
public:
    shared_ptr<Puzzle> createPuzzle(shared_ptr<Puzzle> &p);
    virtual ~PuzzleFactory();

protected:
    shared_ptr<Reproduction> reproduction; // reproduction
};

